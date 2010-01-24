/// \file GEARC_MainWindow.h Declaración de la interfaz gráfica principal.

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


#ifndef GMAINWINDOW_H
#define GMAINWINDOW_H

#include "Gi18n.h"

#include "ui_GEARC_MainWindow.h"
#include "notas/GNotasWindow.h"

#include <QtGui/QMainWindow>

// Declaraciones aplazadas (Forward declarations)
class GListaRamos;


/**
 * \class GEARC_MainWindow
 * \brief Ventana principal de GEARC.
 *
 * GEARC_MainWindow posee los métodos y propiedades que determinan la ventana
 * principal de GEARC. Es heredada de \c QMainWindow y de \c Ui::GEARC_MainWindow, la
 * cual es generada a partir del archivo \c GMainWindow.ui.
 *
 * \sa main.cpp
*/

class GEARC_MainWindow : public QMainWindow, private Ui::GEARC_MainWindow
{
    Q_OBJECT
    
public:

    GEARC_MainWindow (QWidget *parent = 0);
    ~GEARC_MainWindow ();
    
    
public slots:

    void showAcercaDe ();
    void agregarRamo ();
    void itemApretado (QTreeWidgetItem *item, int column);
    
private:

    GestorNota *gestorNotas; /**< Ventana que manipula las notas, se empotra en la ventana principal. */
    GListaRamos *listaRamos; /**< Mantiene en memoria la lista de ramos. */
    QList<QTreeWidgetItem *> itemsRamos;
};

#endif // GMAINWINDOW_H
