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


#ifndef GLISTARAMOS_H
#define GLISTARAMOS_H

#include "GRamo.h"

#include <QtCore/QList>

typedef QList<GRamo*> ListaGRamo;

/**
 * \class GListaRamos
 * \brief Manipula los ramos que se almacenan en memoria.
 *
 * Mantiene en memoria un QList de punteros a GRamo. Permite agregar y eliminar
 * los ramos. Debido a que los GRamo son también un tipo de QListWidgetItem, se necesita
 * conocer cual es el QListWidget que mostrará los ramos. Por tanto esta clase almacena
 * un puntero al QListWidget creado en la ventana principal para comunicarse con él
 * y mostrar correctamente la lista de ramos.
*/

class GListaRamos
{
public:
    GListaRamos (QListWidget *parent = 0);
    ~GListaRamos ();
    
    void agregarRamo (const QString &nombre, const QString &nombreProfesor);
    
    inline QListWidget *parent() const;
    
    QString nombreRamo (GRamo *ramo) const;
    QString nombreProfesorRamo (GRamo *ramo) const;
    
private:
    ListaGRamo listaRamos; /**< La lista de GRamo en memoria por medio de una QList. */
    QListWidget *m_parent; /**< Puntero al QListWidget en la ventana principal. */
};

#endif // GLISTARAMOS_H
