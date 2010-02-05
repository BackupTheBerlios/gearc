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

#include "archivos/GLecturaGrc.h"
#include "ramos/GListaRamos.h"

#include <QtGui/QFileDialog>
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
    gestorNotas = new GNotasWindow (this);
    
    layoutNotas->addWidget (gestorNotas);
    
    listaRamos = new GListaRamos (lstRamos);
    
    
    conexiones();
    
    
    /*---------------------
       Configuraciones ¿?
       --------------------*/
    frmNotas->resize (20, 20);
    gestorNotas->resize (20, 20);
    
    lstRamos->setSortingEnabled (true);
    lstRamos->setAlternatingRowColors (true);
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
    
    texto += "Copyright &copy; 2009 Daniel L. Contreras P.";
    texto += _ ("<br>Liberado bajo los términos de la Licencia Pública General de GNU versión 3 (GPLv3).");
    texto += _ ("<p>GEARC es un administrador de ramos y calificaciones.\
            Permite promediar y autocalcular calificaciones.\
            Aun se encuentra en un estado muy prematuro pero ira creciendo poco a poco.\
            Para más información visite: ");

    texto += QString ("<a href=%1>%2</a>").arg (web).arg (web);
    
    web = "http://www.gnu.org/licenses";
    gnuWeb = QString ("<a href=%1>%2</a>").arg (web).arg (web);
    
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
    datosRamo ramo;
    
    ramo.nombre = QInputDialog::getText (this,
                                         "Agregando un ramo",
                                         "Ingrese el nombre del ramo:",
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
                                         
    if (!ok || ramo.nombre.isEmpty() )
        return;
        
    ramo.nombreProfesor = QInputDialog::getText (this,
                          "Agregando un ramo",
                          "Ingrese el nombre del profesor ramo:",
                          QLineEdit::Normal,
                          "",
                          &ok);
                          
    if (!ok || ramo.nombreProfesor.isEmpty() )
        return;
        
    listaRamos->agregarRamo (ramo);
}


void GEARC_MainWindow::abrirArchivo()
{
    QString nombreArchivo = QFileDialog::getOpenFileName (this, _ ("Abrir archivo GEARC"),
                            QDir::currentPath(), _ ("Archivo GEARC (*.grc)") );
                            
    if (nombreArchivo.isEmpty() )
        return;
        
    //treeWidget->clear();
    
    
    QFile archivo (nombreArchivo);
    
    if (!archivo.open (QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning (this, _ ("Archivo GEARC"),
                              _ ("No se puede leer el archivo %1:\n%2.")
                              .arg (nombreArchivo)
                              .arg (archivo.errorString() ) );
        return;
    }
    
    /*XbelReader reader (treeWidget);
    
    if (!reader.read (&file) )
    {
        QMessageBox::warning (this, tr ("QXmlStream Bookmarks"),
                              tr ("Parse error in file %1 at line %2, column %3:\n%4")
                              .arg (fileName)
                              .arg (reader.lineNumber() )
                              .arg (reader.columnNumber() )
                              .arg (reader.errorString() ) );
    }
    else
    {
        statusBar()->showMessage (tr ("File loaded"), 2000);
    }
    */
    
    GLecturaGrc lectura (&archivo, listaRamos);
    
    if (!lectura.leer() )
    {
        qWarning() << "Error leyendo el archivo " << nombreArchivo
        << " en la línea " << lectura.lineNumber()
        << " , columna " << lectura.columnNumber();
        qWarning() << "El error fue: " << lectura.errorString();
        
        QMessageBox::warning (this, "GEARC",
                              _ ("Error de lectura en el archivo %1\n%2")
                              .arg (nombreArchivo)
                              .arg (lectura.errorString() ) );
    }
    
    barEstado->showMessage (_ ("Archivo cargado correctamente"), 3000 );
}

void GEARC_MainWindow::guardarArchivo()
{

}


/**
 * Slot que actualiza los datos de las cajas de texto en relación a la información
 * del ramo seleccionado. Se conecta con la señal \em itemActivated(QListWidgetItem*).
 *
 * \param item Puntero al item seleccionado en el QListWidget.
*/
void GEARC_MainWindow::actualizarDatosRamo (QListWidgetItem *item)
{
    qDebug() << "El item presionado fue: " << item;
    
    lneNombre->setText (listaRamos->nombreRamo (static_cast<GRamo*> (item) ) );
    lneNombreProfesor->setText (listaRamos->nombreProfesorRamo (static_cast<GRamo*> (item) ) );
}

void GEARC_MainWindow::conexiones()
{
    // Menús
    connect (actAboutQt, SIGNAL (triggered () ), qApp, SLOT (aboutQt () ) );
    connect (actAbout, SIGNAL (triggered () ), this, SLOT (showAcercaDe () ) );
    connect (actNuevoRamo, SIGNAL (triggered () ), this, SLOT (agregarRamo () ) );
    connect (actAbrir, SIGNAL (triggered (bool) ), this, SLOT (abrirArchivo() ) );
    connect (actGuardar, SIGNAL (triggered (bool) ), this, SLOT (guardarArchivo() ) );
    
    connect (lstRamos, SIGNAL (itemActivated (QListWidgetItem*) ),
             this, SLOT (actualizarDatosRamo (QListWidgetItem*) ) );
}



#include "GEARC_MainWindow.moc"
