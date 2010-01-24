/// @file gi18n.h Declaraciones para internacionalización con gettext.

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


#ifndef GI18N_H
#define GI18N_H

#include <QString>

/**
	@TODO GetText no funciona correctamente en Windows.
*/

// Inclusiones de gettext
#ifndef WIN32
#include <libintl.h>
#include <locale.h>

// Definiciones para la localización
#define _(String) QString::fromUtf8 (gettext(String))
#define gettext_noop(String) String
#define N_(String) QString::fromUtf8 (gettext_noop (String))

#else
// Omite la localización en windows
#define _(String) QString::fromUtf8 (String)
#define N_(String) QString::fromUtf8 (String)
#endif


#endif // GI18N_H
