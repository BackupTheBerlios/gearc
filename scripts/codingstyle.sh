#!/bin/sh

# Formatea  y aplica un estilo de código a todo el código fuente de GEARC
# que se encuentre dentro del directorio 'src' (../src)

# Es necesario tener instalado el programa astyle.


# Basado en el script codingstyle.sh de rekonq (navegador web basado en webkit
# para KDE. Modificado para GEARC.

PWD=$(pwd)
cd $PWD
cd ../src

echo "Iniciando indentación del código fuente..."
astyle \
--indent=spaces=4 \
--brackets=break \
--indent-labels \
--indent-preprocessor \
--indent-namespaces \
--max-instatement-indent=40 \
--break-blocks \
--pad=oper \
--pad-paren-out \
--keep-one-line-blocks \
--convert-tabs \
--fill-empty-lines \
--verbose \
`find -type f -name '*.cpp'` `find -type f -name '*.h'`

echo "Eliminando archivos .orig..."
rm `find -type f -name '*.orig'`

echo "Terminado!"
