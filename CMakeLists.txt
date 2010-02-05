#*****************************************************************************#
# GEARC. Gestor y administrador de ramos y calificaciones.                    #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#

PROJECT (gearc)

SET (GEARC_VERSION "0.0.81 (alfa 1)")

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET (CMAKE_COLOR_MAKEFILE ON)

FIND_PACKAGE (Qt4 4.4.3 COMPONENTS QtCore QtGui QtXml REQUIRED)
IF (NOT QT4_FOUND)
    MESSAGE (FATAL_ERROR "GEARC necesita QT4 para compilarse.")
ENDIF (NOT QT4_FOUND)



# Directorios de inclusión de cabeceras de QT
INCLUDE_DIRECTORIES (${QT_INCLUDE_DIR})


# Definición para desinstalar archivos instalados.
CONFIGURE_FILE (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
)

ADD_CUSTOM_TARGET (uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)


ADD_DEFINITIONS (-DGEARC_VERSION="${GEARC_VERSION}")


# Analiza el uso de GetText
IF (NOT WIN32 AND NOT WITHOUT_GETTEXT)
    
    MESSAGE (STATUS " ")
    MESSAGE (STATUS "  *****     Usando GetText")
    MESSAGE (STATUS " ")
    
    INCLUDE (${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindGettext.cmake)
    ADD_DEFINITIONS (-DUSE_GETTEXT)
ENDIF (NOT WIN32 AND NOT WITHOUT_GETTEXT)


# Mensajes de estado
MESSAGE (STATUS " ")
MESSAGE (STATUS "  *****   Ruta de instalación: ${CMAKE_INSTALL_PREFIX}")

# Asigna debug por defecto.
IF (NOT CMAKE_BUILD_TYPE)
    SET (CMAKE_BUILD_TYPE relwithdebinfo)
    MESSAGE (STATUS " ")
    MESSAGE (STATUS "  *****  Tipo de construcción: RelWithDebInfo (por defecto)")
    MESSAGE (STATUS " ")
ELSE (NOT CMAKE_BUILD_TYPE)
    MESSAGE (STATUS " ")
    MESSAGE (STATUS "  *****  Tipo de construcción: ${CMAKE_BUILD_TYPE}")
    MESSAGE (STATUS " ")
ENDIF (NOT CMAKE_BUILD_TYPE)


# Subdirectorios
ADD_SUBDIRECTORY (src)
