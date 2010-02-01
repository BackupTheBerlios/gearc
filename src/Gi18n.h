/// \file Gi18n.h Declaraciones para internacionalización con \ref gettext "GNU GetText".
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
/**
* \file Gi18n.h
*
* Contiene macros y funciones necesarias para usar GetText y permitir
* la internacionalización de GEARC. La mayoría de estas funciones
* dependen de la macro \c USE_GETTEXT definida durante la compilación.
* \ref gettext "Más información sobre GNU GetText"
*
* \warning Este archivo debe ser incluido \b antes que los archivos de formularios
* de Qt (\c ui_nombre.h) ya que esos archivos utilizan las funciones de traducción
* y además son autogenerados por el comando \c uic de Qt. Por tanto las funciones
* y macros de este archivo deben estar definidas antes que los archivos de formulario
* sean incluidos.
*
* \todo GetText no funciona correctamente en Windows.
*/

#ifndef GI18N_H
#define GI18N_H

// Inclusiones de gettext
#ifdef USE_GETTEXT

#include <libintl.h>
#include <locale.h>

#endif // USE_GETTEXT

#include <QtCore/QString>

/**
 * Pasa el parámetro \em cadena a través de la función
 * <tt> gettext (const char*) </tt> con lo cual es posible usarla en un idioma
 * diferente. Cada vez que una cadena deba ser traducida es necesario pasarla
 * como el argumento de esta función. Por ejemplo:
 * \code button1.setText ("Bienvenido a GEARC"); \endcode
 * Sería usada de esta forma:
 * \code button1.setText (_("Bienvenido a GEARC")); \endcode
 * Note que el texto a traducir es pasado entre comillas como siempre pero
 * dentro de la función _(...)
 *
 * \return La nueva cadena como un objeto \a QString. Esta cadena vendrá
 * traducida dependiendo de distintos factores (El sistema, si la traducción
 * está disponible, que se esté usando GetText, etc). En otro caso la cadena
 * resultante será la original.
 * \ref gettext "Más información sobre GNU GetText"
*/
inline QString _ (const char *cadena, int a = 0)
{
#ifdef USE_GETTEXT
    return gettext (cadena);
#else
    return cadena;
#endif // USE_GETTEXT
}

// Declaración de funciones -----

/**
 * Utiliza funciones de \ref gettext "GNU GetText" para determinar el idioma
 * del sistema en el que GEARC está corriendo y busca un paquete de idioma
 * correspondiente si es que existe.
 * \return Actualmente devuelve \a false si no se está usando \ref gettext "GetText"
 * y devuelve \a true si \ref gettext "GetText" se está utilizando.
 *
 * \note Esta función retorna \a true independiente de si se logra o no activar
 * la traducción correspondiente.
 *
 * \todo Ampliar esta función y añadir nuevas funciones para manejar correctamente
 * los idiomas.
 */
bool asignarIdioma ();

#endif // GI18N_H
