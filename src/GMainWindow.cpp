/// @file gearc.cpp Definición de la interfaz gráfica principal.

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



#include <QApplication>
#include <QMainWindow>
#include <QValidator>
#include <QLineEdit>

#include "GMainWindow.h"
#include "gestor_notas.h"

#include <QDebug>

GEARC_MainWindow::GEARC_MainWindow (QWidget* parent) : QMainWindow (parent), Ui::GEARC_MainWindow ()
{
	qDebug() << "Creando interfaz. " << this;
	// Establece la interfaz gráfica
	setupUi (this);
	
	qDebug() << "Creando Gestor de Notas.";
	g_notas = new GestorNota (this);
	
	layout_central->addWidget (g_notas);
}


GEARC_MainWindow::~GEARC_MainWindow()
{
	qDebug() << "Destruyendo interfaz. " << this;
}


#include "GMainWindow.moc"
