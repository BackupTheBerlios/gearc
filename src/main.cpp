/// @file main.cpp Archivo inicial.

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
#include <QDebug>

#include "GMainWindow.h"
#include "Gi18n.h"

int main(int argc, char **argv)
{
	#ifndef WIN32
	// Localización
	setlocale(LC_ALL,"");
	bindtextdomain("gearc", "locale");
	textdomain("gearc");
	#endif
	
	qDebug() << "Iniciando GEARC" << endl;
	
	
        QApplication gearc (argc, argv);
	GEARC_MainWindow *principal = new GEARC_MainWindow ();
	
	qDebug() << "Creada ventana principal. " << principal;
	
	principal->show ();
	
	int run = gearc.exec ();
	
	qDebug() << endl << "Cerrando GEARC";
        delete principal;
	
    return run;
}
