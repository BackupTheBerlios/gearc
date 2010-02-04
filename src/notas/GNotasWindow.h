/// \file GNotasWindow.h Declaración de la clase GNotasWindow para manejar notas.

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


#ifndef GESTOR_NOTA_H
#define GESTOR_NOTA_H

#include "../Gi18n.h"

#include "ui_GNotasWindow.h"
#include "Gnota.h"

#include <QtGui/QWidget>
#include <QtCore/QList>

/**
 * \class GNotasWindow
 * \brief El widget que maneja las calificaciones en la ventana principal.
 * 
 * Este widget se "empotra" en la ventan principal. Posee un espacio de visualización
 * para las GNota y los botones necesarios. Se implementa de esta forma para permitir
 * su uso como una ventana separada de la ventana principal de GEARC, de ser necesario.
*/

class GNotasWindow : public QWidget, private Ui::wdgtNotas
{
    Q_OBJECT
    
public:
    GNotasWindow (QWidget *parent = 0);
    ~GNotasWindow ();
    
public slots:
    void agregarNota ();
    float calcularPromedio ();
    void promediar ();
    void calcularNotas ();
    void actualizarNota (const QString& texto, GNota *nota);
    void eliminarNota (GNota *nota);
    
private:
    QList <GNota*> notas;
    
protected:
    //void mouseMoveEvent (QMouseEvent *event);
    
};

#endif // GESTOR_NOTA_H
