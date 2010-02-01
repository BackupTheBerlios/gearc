/// \file Gnota.cpp Definición de la clase GNota.

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


#include "Gnota.h"

#include <QtGui/QPushButton>
#include <QtCore/QDebug>

/** Constructor por defecto. Asigna \em true a la propiedad \em automática.*/
GNota::GNota (QWidget* parent) : QLineEdit (parent)
{
    automatica = true;
    
    // Asigna el color amarillo a la nota
    color.setRgb (250, 255, 200);
    pal.setColor (QPalette::Base, color);
    setPalette (pal);
    
    // Ajusta el tamaño de la nota
    setSizePolicy (QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize (60, 35);
    setMaximumSize (60, 35);
    
    // Crea el boton eliminar nota
    btnEliminar = new QPushButton (this);
    btnEliminar->setText ("-");
    btnEliminar->setFocusPolicy (Qt::NoFocus);
    
    // btnEliminar->setVisible (false);
    
    btnEliminar->setGeometry (60 - 15, 35 - 15, 15, 15);
    
    // Ajusta las propiedades del botón eliminar nota
    QFont font;
    font.setPointSize (12);
    font.setBold (true);
    btnEliminar->setFont (font);
    btnEliminar->setCursor (QCursor (Qt::ArrowCursor) );
    
    connect (btnEliminar, SIGNAL (clicked () ), this, SLOT (on_btnEliminar_clicked () ) );
    connect (this, SIGNAL (textEdited (QString) ), this, SLOT (on_GNota_textChanged (QString) ) );
}

/**
 * Constructor que inicializa el valor de la nota creada. Asigna \em false a la propiedad
 * \em automática.
 *
 * \todo ¿Realmente funciona esto?
*/
GNota::GNota (double valor, QWidget* parent) : QLineEdit (parent)
{
    automatica = false;
    
    // Asigna el color normal a la nota
    setPalette (QPalette() );
}


/** Define que valor tendrá la propiedad \em automática en esta nota. */
void GNota::setAuto (bool nwauto)
{
    automatica = nwauto;
    
    if (nwauto == true)
    {
        // Asigna el color amarillo a la nota
        color.setRgb (250, 255, 200);
        pal.setColor (QPalette::Base, color);
        setPalette (pal);
    }
    else
    {
        // Asigna el color normal a la nota
        setPalette (QPalette() );
    }
}

/** Elimina la nota al hacer clic en el botón de la GNota. Emite la señal \c eliminar(). */
void GNota::on_btnEliminar_clicked ()
{
    // Cuando se presiona el botón 'btnEliminar' se activa esta señal
    // la cual envía la dirección de memoria de la nota a eliminar.
    emit eliminar (this);
}


/** Se activa cuando el texto de la GNota cambia. Emite la señal \c modificada(). */
void GNota::on_GNota_textChanged (const QString &texto)
{
    // Cuando el texto de la nota es modificado se activa esta señal
    // la cual envía el nuevo texto y la dirección de memoria de la nota.
    emit modificada (texto, this);
}


#include "Gnota.moc"
