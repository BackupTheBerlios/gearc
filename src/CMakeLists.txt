#*****************************************************************************#
#         GEARC. Gestor y administrador de ramos y calificaciones.            #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#


# Asigna los FLAGS de compilación
IF (CMAKE_COMPILER_IS_GNUCXX)
	SET (CMAKE_CXX_FLAGS "-Wall -Wold-style-cast -pedantic -Wno-long-long")
	SET (CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wunused-macros")
	SET (CMAKE_CXX_FLAGS_DEBUGFULL "-O0 -g3 -fno-inline -Wundef -Wunused-macros")
	SET (CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")
	IF (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
		ADD_DEFINITIONS (-DDEBUG)
		
	ELSE (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
		ADD_DEFINITIONS (-DNDEBUG -DQT_NO_DEBUG_OUTPUT -DQT_NO_WARNING_OUTPUT)
		
		# Evita que se muestre una consola en Windows
		# al compilarse en un modo de no depuración.
		IF (WIN32)
			SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
		ENDIF (WIN32)
		
	ENDIF (CMAKE_BUILD_TYPE STREQUAL debugfull OR CMAKE_BUILD_TYPE STREQUAL debug)
ENDIF (CMAKE_COMPILER_IS_GNUCXX)


# Directorios de inclusión de cabeceras
INCLUDE_DIRECTORIES (
	${CMAKE_CURRENT_BINARY_DIR}
	notas
)

# Archivos fuente que serán compilados
SET (GEARC_SRC
	main.cpp
	GMainWindow.cpp
	notas/Gvalidador.cpp
	notas/Gnota.cpp
	notas/gestor_notas.cpp
)

SET (GEARC_UI
	GMainWindow.ui
	notas/gestor_notas.ui
)

SET (GEARC_RSC
    recursos/recursos.qrc
)

QT4_ADD_RESOURCES (RCC_SRC ${GEARC_RSC})
QT4_AUTOMOC (${GEARC_SRC})
QT4_WRAP_UI (UI_SRC ${GEARC_UI} OPTIONS -p)


ADD_EXECUTABLE (gearc ${GEARC_SRC} ${UI_SRC} ${RCC_SRC})

TARGET_LINK_LIBRARIES (gearc
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)

INSTALL (TARGETS gearc DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# Archivos de FreeDesktop
INSTALL (FILES recursos/gearc.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
INSTALL (FILES recursos/gearc.png DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
