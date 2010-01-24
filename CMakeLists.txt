#*****************************************************************************#
# GEARC. Gestor y administrador de ramos y calificaciones.                    #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#

project (gearc)
cmake_minimum_required (VERSION 2.6)

find_package (Qt4 REQUIRED)

# Asigna debugfull por defecto.
# TODO Quitar al hacer un Release
set (CMAKE_BUILD_TYPE debugfull)

# Asigna los FLAGS de compilación
if (CMAKE_COMPILER_IS_GNUCXX)
	set (CMAKE_CXX_FLAGS "-Wall -Wold-style-cast -pedantic -Wno-long-long")
	set (CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wunused-macros")
	set (CMAKE_CXX_FLAGS_DEBUGFULL "-O0 -g3 -fno-inline -Wundef -Wunused-macros")
	set (CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")
	if (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
		add_definitions (-DDEBUG)
		
	else (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
		add_definitions (-DNDEBUG -DQT_NO_DEBUG_OUTPUT -DQT_NO_WARNING_OUTPUT)
		
		# Evita que se muestre una consola en Windows
		# al compilarse en un modo de no depuración.
		if (WIN32)
			set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
		endif (WIN32)
		
	endif (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
endif (CMAKE_COMPILER_IS_GNUCXX)


# Directorios de inclusión de cabeceras
include_directories (${QT_INCLUDES})

add_subdirectory (src)
