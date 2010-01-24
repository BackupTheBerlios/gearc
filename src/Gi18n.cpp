/// \file Gi18n.cpp Definiciones para internacionalización con gettext.

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

#include <QtCore/QDebug>

bool asignarIdioma ()
{
#ifdef USE_GETTEXT
    // Localización
    qDebug () << "Locales del sistema: " << setlocale (LC_MESSAGES, "");
    qDebug () << "Ruta de locales: " << bindtextdomain ("gearc", NULL);
    textdomain ("gearc");
    qDebug() << endl;
    return true;
#else
    return false;
#endif // USE_GETTEXT
}
