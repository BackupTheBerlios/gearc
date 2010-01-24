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

GestorNota::GestorNota (QWidget* parent) : QWidget (parent)
{
	setupUi (this);
}


GestorNota::~GestorNota ()
{
	
}


void GestorNota::Agregar_Nota ()
{
	qDebug () << "\nAgregando nota.";
	qDebug () << "Size (notas) : " << notas.size ();
	
	// Crea una nueva nota
	GNota *ptr = new GNota (this);
	qDebug () << "Nueva nota: " << ptr;
	
	// Agrega a la lista
	qDebug () << "Agregando nota " << ptr << " a la lista.";
	notas.append (ptr);
	
	// Agrega al frame
	qDebug () << "Agregando nota " << ptr << " al frame.";
	layout_notas->addWidget (ptr);
	
	// Quita el espaciador y lo coloca nuevamente pero al final
	// no he encontrado otro método para solucionarlo.
	layout_notas->removeItem (hSpacer_notas);
	layout_notas->addItem (hSpacer_notas);
}


/*
void GestorNota::Eliminar_nota (void)
{
	qDebug () << "\nEliminando nota.";
	qDebug () << "Size (notas) : " << notas.size ();
	
	// Hace al widget de la nota invisible.
	qDebug () << "Invisibilizando widget";
	notas[notas.size() - 1]->setVisible (false);
	
	// Devuelve la última nota de la lista.
	GNota *ptr = notas.last ();
	qDebug () << "Nota a eliminar: " << ptr;
	
	Q_ASSERT (ptr == notas[notas.size() - 1]);
	
	// Elimina dicha nota de la lista.
	qDebug () << "Quitando de la lista";
	notas.removeOne (ptr);
	
	// Destruye el objeto
	qDebug () << "Eliminando objeto" << ptr;
	bool elim = ptr->close ();
	qDebug () << "Eliminado?: " << elim;
	
	qDebug () << "Size (notas) : " << notas.size ();
}
*/

void GestorNota::Promediar (void)
{
	
}


#include "gestor_notas.moc"
