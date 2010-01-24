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


#include "Gi18n.h"

#include <QApplication>
#include <QMainWindow>
#include <QValidator>
#include <QLineEdit>
#include <QPixmap>
#include <QMessageBox>

#include "GMainWindow.h"
#include "gestor_notas.h"

#include <QDebug>

#ifndef GEARC_VERSION
#define GEARC_VERSION " "
#endif // GEARC_VERSION


GEARC_MainWindow::GEARC_MainWindow( QWidget* parent ) : QMainWindow( parent ), Ui::GEARC_MainWindow()
{
    qDebug() << "Creando interfaz. " << this;
    // Establece la interfaz gráfica
    setupUi( this );

    qDebug() << "Creando Gestor de Notas.";
    g_notas = new GestorNota( this );

    layout_central->addWidget( g_notas );
    //setWindowIcon (QPixmap(":/gearc.png"));
    connect( actMenuAboutQt, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );
    connect( actMenuAbout, SIGNAL( triggered() ), this, SLOT( acercaDe() ) );
}


GEARC_MainWindow::~GEARC_MainWindow()
{
    qDebug() << "Destruyendo interfaz. " << this;
}


void GEARC_MainWindow::acercaDe()
{
    QString web = "http://gearc.berlios.de/blog";
    QString gnuWeb = "http://www.gnu.org/licenses";
    
    QString texto = QString( "<h2>GEARC %1 </h2>" ).arg( GEARC_VERSION );

    texto += N_( "Copyright &copy; 2009 Daniel L. Contreras P." );
    texto += _( "<br>Liberado bajo los términos de la Licencia Pública General de GNU versión 3 (GPLv3)." );
    texto += _( "<p>GEARC es un administrador de ramos y calificaciones.\
            Permite promediar y autocalcular calificaciones.\
            Aun se encuentra en un estado muy prematuro pero ira creciendo poco a poco.\
            Para más información visite: " );
            
    texto += QString( N_( "<a href=%1>%2</a>" ) ).arg( web ).arg( web );
    
    web = "http://www.gnu.org/licenses";
    gnuWeb = QString( N_( "<a href=%1>%2</a>" ) ).arg( web ).arg( web );
    
    texto += QString( _( "<p>Este programa se ofrece SIN GARANTÍA ALGUNA; es software libre y usted puede\
            redistribuirlo bajo ciertas condiciones. Usted debió haber recibido una copia de la licencia\
            junto con este programa, de todos modos puede dirigirse a %1\
            para mayor información." ) ).arg(gnuWeb) ;

    QMessageBox::about( this, _( "Acerca de GEARC" ),
            texto );
}

#include "GMainWindow.moc"
