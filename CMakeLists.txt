#*****************************************************************************#
# GEARC. Gestor y administrador de ramos y calificaciones.                    #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#

PROJECT (gearc)

SET (GEARC_VERSION "0.0.81 (alfa 1)")

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET (CMAKE_COLOR_MAKEFILE ON)

FIND_PACKAGE (Qt4 4.4.3 COMPONENTS QtCore QtGui REQUIRED)

# Asigna debugfull por defecto.
IF (NOT CMAKE_BUILD_TYPE)
    SET (CMAKE_BUILD_TYPE debug)
    MESSAGE (STATUS "- - - - - - - - - - - - - - - - - - - - -")
    MESSAGE (STATUS "Tipo de construcción: debug (por defecto)")
    MESSAGE (STATUS "- - - - - - - - - - - - - - - - - - - - -")
ENDIF (NOT CMAKE_BUILD_TYPE)



# Directorios de inclusión de cabeceras
INCLUDE_DIRECTORIES (${QT_INCLUDES})


# Definición para desinstalar archivos instalados.
CONFIGURE_FILE (
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
	IMMEDIATE @ONLY
)

ADD_CUSTOM_TARGET (uninstall
	"${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)

IF (NOT CMAKE_INSTALL_PREFIX)
    SET (CMAKE_INSTALL_PREFIX /usr/local)
    MESSAGE (STATUS "- - - - - - - - - - - - - - - - - - - - - - -")
    MESSAGE (STATUS "Ruta de instalación: /usr/local (por defecto)")
    MESSAGE (STATUS "- - - - - - - - - - - - - - - - - - - - - - -")
ENDIF (NOT CMAKE_INSTALL_PREFIX)

ADD_DEFINITIONS (-DGEARC_VERSION=\"${GEARC_VERSION}\")

# Subdirectorios
ADD_SUBDIRECTORY (src)
