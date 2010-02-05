/// \file GRamo.cpp Definición de la clase GRamo que representa una asignatura.

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

#include "GRamo.h"

#include <QtCore/QDebug>

/**
 * Constructor de GRamo, el cual hereda de QListWidgetItem.
 * \param nombre El nombre del ramo.
 * \param nombreProfesor Nombre del profesor del ramo.
 * \param parent Puntero al QListWidget de la ventana principal. \sa GListaRamos
*/
GRamo::GRamo (const QString& nombre, const QString& nombreProfesor, QListWidget* parent)
        : QListWidgetItem (nombre, parent),
        m_Nombre (nombre),
        m_NombreProfesor (nombreProfesor)
{
    // Nada :)
}


/** Destructor de GRamo. */
GRamo::~GRamo()
{
    qDebug() << "Destruyendo GRamo: " << this;
}

