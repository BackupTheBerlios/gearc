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
 * Crea y agrega un nuevo ramo en base a una estructura que posee los datos.
 * El nombre es agregado a listaRamos y se añade una entrda a la QListWidget de la
 * ventana principal.
 *
 * \param nuevoRamo Estructura que posee los datos del nuevo ramo.
 * \sa datosRamo
*/
void GListaRamos::agregarRamo (const datosRamo& nuevoRamo)
{
    Q_ASSERT_X (m_parent != NULL, "agregarRamo", "No hay padre QListWidget");
    
    listaRamos.append (new GRamo (nuevoRamo.nombre, nuevoRamo.nombreProfesor, m_parent) );
    
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


/**
 * Carga una serie de GRamos en la lista en memoria y en la lista de la ventana principal
 * en base a otra lista pasada como parámetro.
 * \param lista Una lista \em ListaGRamo (\c QList<GRamo*>) con los ramos que serán
 * cargados. Esta lista no debe estar vacía.
*/
void GListaRamos::cargar (const ListaGRamo& lista)
{
    Q_ASSERT_X (!lista.isEmpty(), "cargar", "La lista nueva viene vacía");
    
    limpiar();
    
    listaRamos = lista;
}


/**
 * Limpia la lista de ramos en memoria destruyendo cada uno de los GRamo y vaciando
 * la lista de ramos de la ventana principal (QListWidget).
*/
void GListaRamos::limpiar()
{
    if (listaRamos.isEmpty() )
    {
        return;
    }
    
    qDeleteAll (listaRamos);
    listaRamos.clear();
    
    m_parent->clear();
}
