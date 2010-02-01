/// \file GListaRamos.cpp Declaración de la clase GListaRamos.

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


#include "GListaRamos.h"

#include <QtCore/QDebug>

/**
 * Constructor por defecto.
 * \param parent Es la dirección de memoria del QListWidget de la ventana principal.
*/
GListaRamos::GListaRamos (QListWidget* parent) : m_parent (parent)
{

}

/**
 * Destructor. Utiliza qDeleteAll() para destruir el contenido del contenedor
 * listaRamos con todos sus GRamo.
*/
GListaRamos::~GListaRamos()
{
    qDeleteAll (listaRamos);
}

/**
 * Crea y agrega un nuevo ramo en base al nombre del ramo y al nombre del profesor.
 * el nombre es agregado a listaRamos y se añade una entrda a la QListWidget de la
 * ventana principal.
 * 
 * \param nombre Nombre del ramo.
 * \param nombreProfesor Nombre del profesor.
*/
void GListaRamos::agregarRamo (QString nombre, QString nombreProfesor)
{
    Q_ASSERT (m_parent != NULL);
    
    listaRamos.append (new GRamo (nombre, nombreProfesor, m_parent) );
    
    qDebug() << "Insertado el GRamo " << listaRamos.last();
    qDebug() << "Size (listaRamos): " << listaRamos.size();
}

/**
 * Retorna la dirección del QListWidget que se determinó como \em padre
 * en el constructor.
*/
QListWidget* GListaRamos::parent() const
{
    return m_parent;
}

/**
 * Retorna el nombre del ramo referenciado por el GRamo \em ramo.
 * \param ramo Es un puntero al ramo del cual se desea conocer el nombre.
*/
QString GListaRamos::nombreRamo (GRamo* ramo) const
{
    return listaRamos[listaRamos.indexOf (ramo) ]->nombre();
}

/**
 * Retorna el nombre del profesor del ramo referenciado por el GRamo \em ramo.
 * \param ramo Es un puntero al ramo del cual se desea conocer el nombre del profesor.
*/
QString GListaRamos::nombreProfesorRamo (GRamo* ramo) const
{
    return listaRamos[listaRamos.indexOf (ramo) ]->nombreProfesor();
}
