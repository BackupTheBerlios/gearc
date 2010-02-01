/// \file main.cpp Archivo de partida para GEARC.

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

#include <QtGui/QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTextCodec>

/**
 * Función de partida. Crea un objeto \a QApplication, establece la codificación,
 * crea un objeto GEARC_MainWindow con la ventana principal y entra en la sentencia
 * <tt> gearc.exec () </tt> que inicia el bucle interno de \a QApplication.
 *
 * \return el valor entregado por <tt> gearc.exec () </tt>.
*/

int main (int argc, char **argv)
{
    qDebug() << "Iniciando GEARC" << endl;
    
    if (!asignarIdioma () )
    {
        qDebug() << "No se inició GetText.";
    }
    
    QApplication gearc (argc, argv);
    
    
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8") );
    QTextCodec::setCodecForLocale (QTextCodec::codecForName ("UTF-8") );
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8") );
    qDebug() << "Seleccionando UTF-8 como codificación por defecto.";
    qDebug() << endl;
    
    GEARC_MainWindow principal;
    
    qDebug() << "Creada ventana principal. " << &principal;
    
    principal.show ();
    
    int run = gearc.exec ();
    
    qDebug() << endl << "Cerrando GEARC";
    
    return run;
}
