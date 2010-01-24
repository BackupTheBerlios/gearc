/// @file gearc.h Declaración de la interfaz gráfica principal.

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


#ifndef GEARC_H
#define GEARC_H

#include "ui_gearc.h"

#include <QMainWindow>
#include <QList>

#include "gestor_notas.h"


class GEARC_MainWindow : public QMainWindow, private Ui::GEARC_MainWindow
{
	Q_OBJECT
	
	public:
		GEARC_MainWindow (QWidget *parent = 0);
		~GEARC_MainWindow ();
		
	private:
		QList <QLineEdit*> notas;
		GestorNota *g_notas;
		
	public slots:
		void Agregar_nota (void);
		void Eliminar_nota (void);
		void Promediar (void);
};

#endif // GEARC_H
