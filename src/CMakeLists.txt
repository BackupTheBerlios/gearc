#*****************************************************************************#
#         GEARC. Gestor y administrador de ramos y calificaciones.            #
#                                                                             #
#   Copyright 2009 Daniel L. Contreras Pino <inextremares@users.berlios.de>   #
#*****************************************************************************#


# Directorios de inclusión de cabeceras
include_directories (
	${CMAKE_CURRENT_BINARY_DIR}
	notas
)

# Archivos fuente que serán compilados
set (GEARC_SRC
	main.cpp
	GMainWindow.cpp
	notas/Gvalidador.cpp
	notas/Gnota.cpp
	notas/gestor_notas.cpp
)

set (GEARC_UI
	GMainWindow.ui
	notas/gestor_notas.ui
)

qt4_automoc (${GEARC_SRC})
qt4_wrap_ui (UI_SRC ${GEARC_UI} OPTIONS -p)


add_executable (gearc ${GEARC_SRC} ${UI_SRC})

target_link_libraries (gearc
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)
