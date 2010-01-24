/// \file GListaRamos.h Declaración de la clase GListaRamos.

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


#include "GListaRamos.h"

#include <QtCore/QDebug>


GListaRamos::GListaRamos()
{

}

GListaRamos::~GListaRamos()
{
    while (!listaRamos.isEmpty() )
    {
        qDebug() << "Removiendo el GRamo " << listaRamos.last();
        delete listaRamos.last();
        listaRamos.removeLast();
    }
}

void GListaRamos::agregarRamo (QString nombre, QString nombreProfesor)
{
    listaRamos.append (new GRamo() );
    qDebug() << "Insertado el GRamo " << listaRamos.last();
    qDebug() << "Size (listaRamos): " << listaRamos.size();
}


