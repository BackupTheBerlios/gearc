/// @file gestor_nota.cpp Definición de la clase GestorNota para manejar notas.

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


#include "gestor_notas.h"

#include <QDebug>
#include <QMouseEvent>


#define VALOR_MIN 0.1



GestorNota::GestorNota (QWidget* parent) : QWidget (parent)
{
	setupUi (this);
	connect (btn_agregarnota, SIGNAL (clicked () ), this, SLOT (Agregar_Nota () ) );
	connect (btn_calcularnotas, SIGNAL (clicked () ), this, SLOT (Calcular_Notas() ) );
}



void GestorNota::Agregar_Nota ()
{
	qDebug () << "\nAgregando nota.";
	
	// Crea una nueva nota
	GNota *ptr = new GNota (this);
	qDebug () << "Nueva nota: " << ptr;
	
	// Agrega a la lista
	qDebug () << "Agregando nota " << ptr << " a la lista.";
	notas.append (ptr);
	
	// Agrega al frame
	qDebug () << "Agregando nota " << ptr << " al frame.";
	layout_notas->addWidget (ptr);
	
	qDebug () << "Size (notas) : " << notas.size () << endl;
	
	// Quita el espaciador y lo coloca nuevamente pero al final
	// no he encontrado otro método para solucionarlo.
	layout_notas->removeItem (hSpacer_notas);
	layout_notas->addItem (hSpacer_notas);
	
	connect (ptr, SIGNAL (returnPressed () ), this, SLOT (Promediar () ) );
	connect (ptr , SIGNAL (Eliminar (GNota*) ), this, SLOT (Eliminar_Nota (GNota*) ) );
	connect (ptr, SIGNAL (Modificada (QString, GNota*) ), this, SLOT (ActualizarNota (QString, GNota*) ) );
}


float GestorNota::CalcularPromedio ()
{
	qDebug () << "Promediando";
	
	float Sum = 0;
	float Prom;
	
	for (int I = 0; I < notas.size(); I++)
	{
		Sum += (notas[I]->text ().toFloat () );
	}
	
	qDebug () << "Sum: " << Sum;
	qDebug () << "Size (notas) : " << notas.size();
	
	Q_ASSERT (notas.size () > 0);
	
	Prom = Sum / float (notas.size () );
	
	return Prom;
}


void GestorNota::Promediar ()
{
	float Prom = CalcularPromedio ();
	
	QString cadena;
	cadena.setNum (Prom, 'g', 3);
	lne_promedio->setText (cadena);
}


void GestorNota::Calcular_Notas()
{
	float Valor;
	QString cadena;
	float PromE = 4.0;
	float Prom = CalcularPromedio ();
	
	// Coloca todas las notas automáticas a 0 antes de continuar
	for (int I = 0; I < notas.size(); I++)
	{
		if (notas[I]->isAuto () )
			notas[I]->clear ();
	}
	
	while (PromE > Prom)
	{
		for (int I = 0; I < notas.size(); I++)
		{
			qDebug () << endl;
			qDebug () << "I: " << I;
			qDebug () << notas[I]->isAuto ();
			if (notas[I]->isAuto () )
			{
				Valor = (notas[I]->text ().toFloat () + VALOR_MIN);
				//Valor += VALOR_MIN;
				qDebug () << "Valor: " << Valor;
				cadena.setNum (Valor, 'g', 3);
				notas[I]->setText (cadena);
				qDebug () << "Cadena: " << cadena;
				qDebug () << "Texto: " << notas[I]->text ();
			}
		}
		
		Prom = CalcularPromedio ();
		qDebug () << "Prom: " << Prom;
		qDebug () << "PromE: " << PromE;
	}
}



void GestorNota::ActualizarNota (const QString& texto, GNota* nota)
{
	//qDebug () << "Nota " << nota << " modificada: " << texto;
	if (texto == "")
		nota->setAuto (true);
	else
		nota->setAuto (false);
	
	Promediar ();
}


void GestorNota::Eliminar_Nota (GNota* nota)
{
	int Indice = notas.indexOf (nota);
	
	qDebug () << "\nEliminando nota." << endl;
	
	qDebug () << "Indice : " << Indice;
	qDebug () << "Size (notas) : " << notas.size () << endl;
	
	qDebug () << "Invisibilizando widget";
	notas[Indice]->setVisible (false);
	
	qDebug () << "Nota a eliminar: " << nota;
	
	
	qDebug () << "Quitando del layout";
	layout_notas->removeWidget (nota);
	
	qDebug () << "Quitando de la lista";
	notas.removeOne (nota);
	
	qDebug () << "Eliminando objeto" << nota;
	
	nota->close ();
	
	qDebug () << "Size (notas) : " << notas.size () << endl;
	
	if (notas.size () > 0)
		Promediar ();
}


/*
void GestorNota::mouseMoveEvent (QMouseEvent* event)
{
	QWidget::mouseMoveEvent (event);
	qDebug () << "QUEEEEEEEEEEEEEEEEEEEEEEEEEEEEE: " << event->x();
	
}
*/


#include "gestor_notas.moc"
