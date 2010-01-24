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
	color.setRgb (250, 255, 200);
	pal.setColor (QPalette::Base, color);
	setPalette (pal);
	
	// Ajusta el tamaño de la nota
	setSizePolicy (QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize (60, 35);
	setMaximumSize (60, 35);
	
	// Crea el boton eliminar nota
	btnEliminar = new QPushButton (this);
	btnEliminar->setText ("-");
	btnEliminar->setFocusPolicy (Qt::NoFocus);
	
	// btnEliminar->setVisible (false);
	
	btnEliminar->setGeometry(60 - 15, 35 - 15, 15, 15);
	
	// Ajusta las propiedades del botón eliminar nota
	QFont font;
	font.setPointSize(12);
	font.setBold(true);
	btnEliminar->setFont (font);
	btnEliminar->setCursor(QCursor(Qt::ArrowCursor));
	
	connect (btnEliminar, SIGNAL (clicked()), this, SLOT (on_btnEliminar_clicked()));
}


GNota::GNota (double valor, QWidget* parent) : QLineEdit (parent), automatica (false)
{
	// Asigna el color normal a la nota
	setPalette (QPalette());
}


void GNota::on_btnEliminar_clicked ()
{
	// Cuando se presiona el botón 'btnEliminar' se activa esta señal
	// la cual envía la dirección de memoria de la nota a eliminar.
	emit Eliminar (this);
}

#include "Gnota.moc"
