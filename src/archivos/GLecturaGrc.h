/// \file GLecturaGrc.h Declaración de la clase GLecturaGrc para la lectura de archivos GEARC.

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

#ifndef GLECTURAGRC_H
#define GLECTURAGRC_H

#include <QtXml/QXmlStreamReader>

// Declaraciones aplazadas
class GListaRamos;


/**
 * \class GLecturaGrc
 * \brief Permite cargar los datos desde un archivo.
 *
 * Usando las funciones y métodos que provee el módulo QtXml, en especial
 * la clase \em QXmlStreamReader, cargamos los datos guardados previamente
 * en un archivo XML con extensión \c .grc.
 *
 * Esta clase provee \todo terminar documentación.
*/
class GLecturaGrc : public QXmlStreamReader
{
public:

    GLecturaGrc (QIODevice *archivo, GListaRamos *listaRamos);
    
    bool leer ();
    
    
private:

    GListaRamos *m_listaRamos; /**< Puntero a la lista de ramos creada en GEARC_MainWindow. */
};

#endif // GLECTURAGRC_H
