/// \file GEARC_MainWindow.cpp Definición de la interfaz gráfica principal.

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

#include "GEARC_MainWindow.h"

#include "ramos/GListaRamos.h"

#include <QtGui/QLineEdit>
#include <QtGui/QPixmap>
#include <QtGui/QMessageBox>
#include <QtGui/QInputDialog>
#include <QtCore/QDebug>


#ifndef GEARC_VERSION
#define GEARC_VERSION " "
#endif // GEARC_VERSION


/**
 * Constructor por defecto.
 * El parámetro \em parent es utilizado por Qt. Por defecto es \a NULL y se
 * utiliza para determinar el padre del objeto.
*/
GEARC_MainWindow::GEARC_MainWindow (QWidget* parent) : QMainWindow (parent), Ui::GEARC_MainWindow()
{
    qDebug() << "Creando interfaz. " << this;
    // Establece la interfaz gráfica
    setupUi (this);
    
    qDebug() << "Creando Gestor de Notas.";
    gestorNotas = new GestorNota (this);
    
    //layout_central->addWidget( gestorNotas );
    //setWindowIcon (QPixmap(":/gearc.png"));
    layoutNotas->addWidget (gestorNotas);
    frmNotas->resize (20, 20);
    gestorNotas->resize (20, 20);
    connect (actAboutQt, SIGNAL (triggered () ), qApp, SLOT (aboutQt () ) );
    connect (actAbout, SIGNAL (triggered () ), this, SLOT (showAcercaDe () ) );
    
    listaRamos = new GListaRamos ();
    
    connect (actNuevoRamo, SIGNAL (triggered () ), this, SLOT (agregarRamo () ) );
    
    connect (treeRamos, SIGNAL (itemClicked (QTreeWidgetItem*, int)), this, SLOT (itemApretado(QTreeWidgetItem*,int)));
}


/** Destructor de la clase */
GEARC_MainWindow::~GEARC_MainWindow()
{
    qDebug() << "Destruyendo interfaz. " << this;
    delete listaRamos;
}


/**
 * Muestra el cuadro <em>acerca de</em> con información sobre el programa
 * y los autores.
*/
void GEARC_MainWindow::showAcercaDe()
{
    QString web = "http://gearc.berlios.de/blog";
    QString gnuWeb = "http://www.gnu.org/licenses";
    
    QString texto = QString ("<h2>GEARC %1 </h2>").arg (GEARC_VERSION);
    
    texto += N_ ("Copyright &copy; 2009 Daniel L. Contreras P.");
    texto += _ ("<br>Liberado bajo los términos de la Licencia Pública General de GNU versión 3 (GPLv3).");
    texto += _ ("<p>GEARC es un administrador de ramos y calificaciones.\
            Permite promediar y autocalcular calificaciones.\
            Aun se encuentra en un estado muy prematuro pero ira creciendo poco a poco.\
            Para más información visite: ");

    texto += QString (N_ ("<a href=%1>%2</a>") ).arg (web).arg (web);
    
    web = "http://www.gnu.org/licenses";
    gnuWeb = QString (N_ ("<a href=%1>%2</a>") ).arg (web).arg (web);
    
    texto += QString (_ ("<p>Este programa se ofrece SIN GARANTÍA ALGUNA; es software libre y usted puede\
            redistribuirlo bajo ciertas condiciones. Usted debió haber recibido una copia de la licencia\
            junto con este programa, de todos modos puede dirigirse a %1\
            para mayor información.") ).arg (gnuWeb) ;

    QMessageBox::about (this, _ ("Acerca de GEARC"),
                        texto);
}


/**
 * Pide información sobre el nuevo ramo a crear y lo agrega a la lista
 * de ramos.
 * \sa listaRamos
*/
void GEARC_MainWindow::agregarRamo()
{
    bool ok;
    QString nombreRamo = QInputDialog::getText (this,
                         "Agregando un ramo",
                         "Ingrese el nombre del ramo:",
                         QLineEdit::Normal,
                         "",
                         &ok);
                         
    if (!ok || nombreRamo.isEmpty() )
        return;
        
    QString nombreProfesor = QInputDialog::getText (this,
                             "Agregando un ramo",
                             "Ingrese el nombre del profesor ramo:",
                             QLineEdit::Normal,
                             "",
                             &ok);
                             
    if (!ok || nombreProfesor.isEmpty() )
        return;
        
    listaRamos->agregarRamo (nombreRamo, nombreProfesor);
    QStringList datos;
    datos << nombreRamo << nombreProfesor;
    
    itemsRamos.append (new QTreeWidgetItem (treeRamos, datos) );
}

void GEARC_MainWindow::itemApretado(QTreeWidgetItem* item, int column)
{
    qDebug() << endl;
    qDebug() << "El item presionado fue: " << item;
    qDebug() << "En la columna: " << column;
    qDebug() << endl;
}



#include "GEARC_MainWindow.moc"
