#*****************************************************************************#
#         GEARC. Gestor y administrador de ramos y calificaciones.            #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#

# Asigna los FLAGS de compilación para compiladores GNU C++
IF (CMAKE_COMPILER_IS_GNUCXX)
    # FLAGS comunes a todos los modos
	SET (CMAKE_CXX_FLAGS "-Wall -Wold-style-cast -pedantic -ansi -std=c++0x")
	
	# FLAGS para modo de depuración
	SET (CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wunused-macros -Wundef")
    
    # FLAGS para modo release con información de depuración
	SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -Wundef -Wunused-macros")
	
	# FLAGS para modo de tamaño pequeño
	SET (CMAKE_CXX_FLAGS_MINSIZEREL "-Os -g0 fno-inline")
	
	# FLAGS para modo release
	SET (CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")
	
	IF (CMAKE_BUILD_TYPE STREQUAL debug OR CMAKE_BUILD_TYPE STREQUAL relwithdebinfo)
		ADD_DEFINITIONS (-DDEBUG)
		
    ELSE (CMAKE_BUILD_TYPE STREQUAL debug OR CMAKE_BUILD_TYPE STREQUAL relwithdebinfo)
		ADD_DEFINITIONS (-DNDEBUG -DQT_NO_DEBUG_OUTPUT -DQT_NO_WARNING_OUTPUT)
		
		# Evita que se muestre una consola en Windows
		# al compilarse en un modo de no depuración.
		IF (WIN32)
			SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
		ENDIF (WIN32)
		
    ENDIF (CMAKE_BUILD_TYPE STREQUAL debug OR CMAKE_BUILD_TYPE STREQUAL relwithdebinfo)
ENDIF (CMAKE_COMPILER_IS_GNUCXX)


# Directorios de inclusión de cabeceras
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_BINARY_DIR})


# Lista de archivos de código fuente
FILE (GLOB_RECURSE GEARC_SRC *.cpp)
#SET (GEARC_SRC
#    main.cpp
#    Gi18n.cpp
#    GMainWindow.cpp
#    notas/Gnota.cpp
#    notas/GNotasWindow.cpp
#    ramos/GRamo.cpp
#)

# Lista de archivos de formularios QT
FILE (GLOB_RECURSE GEARC_UI *.ui)
#SET (GEARC_UI
#    GMainWindow.ui
#    notas/GNotasWindow.ui
#)


# Lista de archivos de recursos
FILE (GLOB_RECURSE GEARC_RSC *.qrc)
#SET (GEARC_RSC
#    recursos/recursos.qrc
#)

# Genera los archivos de QT (Recursos, MOC, UI)
QT4_ADD_RESOURCES (RCC_SRC ${GEARC_RSC})
QT4_AUTOMOC (${GEARC_SRC})
QT4_WRAP_UI (UI_SRC ${GEARC_UI} OPTIONS -p -tr _)

# Archivos que serán procesados por GetText para generar el archivo POT
SET (GEARC_i18n
    ${UI_SRC}
    ${RCC_SRC}
    ${GEARC_SRC}
)

# Crea la plantilla de GetText (POT)
#   (NOMBRE_CATALOGO DIRECTORIO_SALIDA DIRECTORIO_ENTRADA ARCHIVOS)
# Se omite en Windows
IF (NOT WIN32 AND NOT WITHOUT_GETTEXT)
    GETTEXT_CREATE_TEMPLATE (gearc
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}
        GEARC_i18n
    )
ENDIF (NOT WIN32 AND NOT WITHOUT_GETTEXT)


# Compila las traducciones
#GETTEXT_CREATE_TRANSLATIONS (${CMAKE_CURRENT_BINARY_DIR}/gearc.pot
#ALL LANGUAGES es en)

#GETTEXT_CREATE_TRANSLATIONS(${CMAKE_CURRENT_BINARY_DIR}/bulmacont.pot
#ALL LANGUAGES es_ES.UTF-8 ca_ES.UTF-8
#en_US.UTF-8 fr_FR.UTF-8)


# Genera el archivo ejecutable 'gearc' en base a los archivos fuente
ADD_EXECUTABLE (gearc ${GEARC_SRC} ${UI_SRC} ${RCC_SRC})

# Enlaza el ejecutable con las librerias de QT
TARGET_LINK_LIBRARIES (gearc
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)

# BLANCOS DE INSTALACION (make install)

# Instalación del archivo ejecutable
INSTALL (TARGETS gearc DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# Archivos de FreeDesktop
INSTALL (FILES recursos/gearc.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
INSTALL (FILES recursos/gearc.png DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
