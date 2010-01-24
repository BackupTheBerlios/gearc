/// @file gestor_notas.h Declaración de la clase GestorNota para manejar notas.

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

#include "Gnota.h"

#include "ui_gestor_notas.h"

#include <QList>
#include <QWidget>

class GestorNota : public QWidget, private Ui::frm_GestorNotas
{
    Q_OBJECT
    
public:
    GestorNota (QWidget *parent = 0);
    
public slots:
    void Agregar_Nota ();
    float CalcularPromedio ();
    void Promediar ();
    void Calcular_Notas ();
    void ActualizarNota (const QString& texto, GNota *nota);
    void Eliminar_Nota (GNota *nota);
    
private:
    QList <GNota*> notas;
    
protected:
    //void mouseMoveEvent (QMouseEvent *event);
    
};

#endif // GESTOR_NOTA_H
