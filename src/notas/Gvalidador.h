/// @file Gvalidador.h Declaración de la clase GValidador para las Notas.

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


#ifndef GVALIDADOR_H
#define GVALIDADOR_H


#include <QValidator>

class GValidador : public QDoubleValidator
{
public:
    GValidador (double bottom, double top, int decimals, QObject* parent = 0);
    
    QValidator::State validate (QString &input, int &pos) const;
};

#endif // GVALIDADOR_H
