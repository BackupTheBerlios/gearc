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

#include "gearc.h"
#include "gestor_notas.h"

#include <QDebug>

GEARC_MainWindow::GEARC_MainWindow (QWidget* parent) : QMainWindow (parent), Ui::GEARC_MainWindow ()
{
	qDebug() << "Creando interfaz. " << this;
	// Establece la interfaz gráfica
	setupUi (this);
	
	qDebug() << "Estableciendo propiedades.";
	// Establece las propiedades de inicio
	btn_eliminanota->setEnabled (false);
	btn_calcular->setEnabled (false);
	btn_promediar->setEnabled (false);
	
	
	// Señales y Slots
	connect (menu_Salir, SIGNAL (triggered()), this, SLOT (close()));
	connect (btn_agregarnota, SIGNAL (clicked()), SLOT (Agregar_nota()));
	connect (btn_eliminanota, SIGNAL (clicked()), SLOT (Eliminar_nota()));
	connect (btn_promediar, SIGNAL (clicked()), SLOT (Promediar()));
	
	g_notas = new GestorNota (this);
	//g_notas->show();
	
	layout_notas->addWidget (g_notas);
}


GEARC_MainWindow::~GEARC_MainWindow()
{
	qDebug() << "Destruyendo interfaz. " << this;
}



void GEARC_MainWindow::Agregar_nota (void)
{
	qDebug () << "\nAgregando nota.";
	qDebug () << "Size (notas) : " << notas.size ();
	
	QLineEdit *ptr = new QLineEdit (frame_notas);
	qDebug () << "Nueva nota: " << ptr;
	
	// Setea el color de fondo
	QPalette pal;
	pal.setColor (QPalette::Base, Qt::yellow);
	ptr->setPalette (pal);
	
	// Agrega a la lista
	qDebug () << "Agregando a la lista";
	notas.append (ptr);
	
	qDebug () << "Agregando al layout";
	layout_notas->addWidget (ptr);
	qDebug () << "Size (notas) : " << notas.size ();
	
	qDebug () << "Cambiando propieades de botones";
	btn_eliminanota->setEnabled (true);
	btn_promediar->setEnabled (true);
}


void GEARC_MainWindow::Eliminar_nota (void)
{
	qDebug () << "\nEliminando nota.";
	qDebug () << "Size (notas) : " << notas.size ();
	
	qDebug () << "Invisibilizando widget";
	notas[notas.size() - 1]->setVisible (false);
	
	QLineEdit *ptr = notas.last ();
	qDebug () << "Nota a eliminar: " << ptr;
	
	Q_ASSERT (ptr == notas[notas.size() - 1]);
	
	
	qDebug () << "Quitando del layout";
	layout_notas->removeWidget (ptr);
	
	qDebug () << "Quitando de la lista";
	notas.removeOne (ptr);
	
	qDebug () << "Eliminando objeto" << ptr;
	//delete ptr;
	qDebug () << "Eliminado?: " << ptr->close ();
	
	qDebug () << "Size (notas) : " << notas.size ();
	
	if (notas.size() == 0)
	{
		qDebug () << "Desactivando botones";
		btn_eliminanota->setEnabled (false);
		btn_promediar->setEnabled (false);
	}
}



void GEARC_MainWindow::Promediar (void)
{
	qDebug () << "Promediando";
	float Sum = 0;
	double Prom;
	
	for (int I = 0; I < notas.size(); I++)
	{
		Sum += (notas[I]->text().toFloat());
	}
	qDebug () << "Sum: " << Sum;
	qDebug () << "Size (notas) : " << notas.size();
	Q_ASSERT (notas.size() > 0);
	
	Prom = Sum / float (notas.size ());
	QString cadena;
	cadena.setNum (Prom, 'g', 2);
	lne_promedio->setText (cadena);
}


#include "gearc.moc"
