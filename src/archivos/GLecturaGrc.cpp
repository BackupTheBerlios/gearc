/// \file GLecturaGrc.cpp Definición de la clase GLecturaGrc para la lectura de archivos GEARC.

/******************************************************************************
*           GEARC. Gestor y administrador de ramos y calificaciones.          *
*                                                                             *
*         Copyright (C) 2009  Daniel L. Contreras Pino                        *
*             <inextremares@users.berlios.de>                                 *
*******************************************************************************

*******************************************************************************
*      Este programa es software libre: usted puede redistribuirlo y/o        *
*      modificarlo bajo los términos de la Licencia Pública General GNU       *
*      publicada por la Fundación para el Software Libre, ya sea la           *
*      la versión 3 de la Licencia, o (a su elección) cualquier versión       *
*      posterior.                                                             *
*                                                                             *
*      Debería haber recibido una copia de la Licencia Pública General        *
*      GNU junto a este programa. En caso contrario, consulte                 *
*      <http://www.gnu.org/licenses/>.                                        *
*******************************************************************************/

#include "../Gi18n.h"

#include "GLecturaGrc.h"

#include "../ramos/GListaRamos.h"

#include <QtCore/QDebug>



/*
    La estructura interna actual del formato GRC para GEARC:

    <?xml version="1.0" encoding="UTF-8"?>
    <GRC version="0.1">
        <ramo nombre="Nombre del ramo" profesor="Nombre del profesor"/>
        <ramo nombre="Otro Nombre" profesor="Otro profesor"/>
    </GRC>

*/

/**
 * Constructor de GLecturaGrc. Pide el archivo a leer y un puntero a un objeto
 * GListaRamos al cual serán enviados todos los datos que se recogan desde el archivo.
 *
 * \param archivo Puntero a un archivo ya abierto.
 * \param listaRamos Puntero a un objeto GListaRamos creado en GEARC_MainWindow.
*/
GLecturaGrc::GLecturaGrc (QIODevice *archivo, GListaRamos *listaRamos)
        : QXmlStreamReader (archivo), m_listaRamos (listaRamos)
{

}

/**
 * Lee los datos del archivo y los ingresa en la lista de ramos en memoria y en la lista
 * de ramos de la ventana principal.
*/
bool GLecturaGrc::leer()
{
    // Crea una estructura nuevoRamo para contener los datos
    datosRamo nuevoRamo;
    
    while (!atEnd() )
    {
        readNext(); // Lee el siguiente elemento
        
        if (isStartElement() )
        {
            if (name() != "GRC")
            {
                raiseError (_ ("El archivo no es un documento GRC de GEARC.") );
                return false;
            }
            else if (name () == "GRC" && attributes().value ("version") != "0.1")
            {
                raiseError (_ ("El archivo GRC no corresponde con la versión de GEARC en uso.") );
                return false;
            }
            else
            {
                while (!atEnd() )
                {
                    readNext();
                    
                    if (isStartElement() )
                    {
                        if (name() == "ramo")
                        {
                            nuevoRamo.nombre = attributes().value ("nombre").toString();
                            nuevoRamo.nombreProfesor = attributes().value ("profesor").toString();
                            
                            m_listaRamos->agregarRamo (nuevoRamo);
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

