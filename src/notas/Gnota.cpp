/// @file nota.cpp Definición de la clase GNota.

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


#include "Gnota.h"

#include <QDebug>

GNota::GNota (QWidget* parent) : QLineEdit (parent), automatica (true)
{
	// Asigna el color amarillo a la nota
	color.setRgb (180, 180, 0);
	pal.setColor (QPalette::Base, color);
	setPalette (pal);
}


GNota::GNota (double valor, QWidget* parent) : QLineEdit (parent), automatica (false)
{
	// Asigna el color normal a la nota
	setPalette (QPalette());
}
