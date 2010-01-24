/// @file nota.h Declaración de la clase GNota.

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


#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <QLineEdit>
#include <QPushButton>

class GNota : public QLineEdit
{
	Q_OBJECT
	
	public:
		GNota (QWidget* parent = 0);
		GNota (double valor, QWidget *parent = 0);
		
		QPushButton *btnEliminar;
		
		bool isAuto () const
		{
			return automatica;
		}
		
	private slots:
		void on_btnEliminar_clicked ();
		
	signals:
		void Cliqueado (GNota *objeto);
		
	private:
		QColor color;
		QPalette pal;
		bool automatica;
};

#endif // CALIFICACION_H
