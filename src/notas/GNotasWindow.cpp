/// \file GNotasWindow.cpp Definición de la clase GestorNota para manejar notas.

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


#include "GNotasWindow.h"

#include <QtCore/QDebug>
//#include <QtGui/QMouseEvent>


#define VALOR_MIN 0.1


/**
 * Constructor por defecto. \em parent puede ser cualquier widget que se defina
 * como padre de este widget; en general el padre será el GEARC_MainWindow.
*/
GestorNota::GestorNota (QWidget* parent) : QWidget (parent)
{
    setupUi (this);
    connect (btnAgregarNota, SIGNAL (clicked () ), this, SLOT (agregarNota () ) );
    connect (btnAutocalcular, SIGNAL (clicked () ), this, SLOT (calcularNotas() ) );
}

/** Destruye el widget */
GestorNota::~GestorNota()
{
    qDebug() << "Destruyendo Gestor de notas " << this;
}

/**
 * Agrega una nueva nota a la lista de notas y se muestra en la caja de notas.
 * Conecta todas las señales necesarias.
*/
void GestorNota::agregarNota ()
{
    qDebug () << "\nAgregando nota.";
    
    // Crea una nueva nota
    GNota *ptr = new GNota (this);
    qDebug () << "Nueva nota: " << ptr;
    
    // Agrega a la lista
    qDebug () << "Agregando nota " << ptr << " a la lista.";
    notas.append (ptr);
    
    // Agrega al frame
    qDebug () << "Agregando nota " << ptr << " al frame.";
    lytNotas->addWidget (ptr);
    
    qDebug () << "Size (notas) : " << notas.size () << endl;
    
    // Quita el espaciador y lo coloca nuevamente pero al final
    // no he encontrado otro método para solucionarlo.
    lytNotas->removeItem (spcrNotas);
    lytNotas->addItem (spcrNotas);
    
    connect (ptr, SIGNAL (returnPressed () ), this, SLOT (promediar() ) );
    connect (ptr , SIGNAL (eliminar (GNota*) ), this, SLOT (eliminarNota (GNota*) ) );
    connect (ptr, SIGNAL (modificada (QString, GNota*) ), this, SLOT (actualizarNota (QString, GNota*) ) );
}

/**
 * Calcula el promedio o media aritmética de las notas existentes.
 * \return EL valor calculado.
*/
float GestorNota::calcularPromedio ()
{
    qDebug () << "Promediando";
    
    float Sum = 0;
    float Prom = 0;
    
    for (int I = 0; I < notas.size(); I++)
    {
        Sum += (notas[I]->text ().toFloat () );
    }
    
    qDebug () << "Sum: " << Sum;
    qDebug () << "Size (notas) : " << notas.size();
    
    Q_ASSERT (notas.size () > 0);
    
    Prom = Sum / float (notas.size () );
    return Prom;
}

/**
 * Utilizando calcularPromedio() obtiene el promedio de las notas, luego convierte ese número
 * en una cadena QString y lo asigna a la caja de texto lnePromedio.
*/
void GestorNota::promediar ()
{
    float Prom = calcularPromedio ();
    
    QString cadena;
    cadena.setNum (Prom, 'g', 3);
    lnePromedio->setText (cadena);
}

/**
 * Autocalcula todas las notas marcadas como automáticas para lograr el
 * promedio definido.
 * \bug Falla cuando se presiona el botón <b> Autocalcular Notas</b> y
 * no hay notas. Desactivar el botón en esos casos es una solución.
*/
void GestorNota::calcularNotas()
{
    float Valor;
    QString cadena;
    float PromE = 4.0;
    float Prom = calcularPromedio ();
    
    // Coloca todas las notas automáticas a 0 antes de continuar
    for (int I = 0; I < notas.size(); I++)
    {
        if (notas[I]->isAuto () )
            notas[I]->clear ();
    }
    
    while (PromE > Prom)
    {
        for (int I = 0; I < notas.size(); I++)
        {
            qDebug () << endl;
            qDebug () << "I: " << I;
            qDebug () << notas[I]->isAuto ();
            
            if (notas[I]->isAuto () )
            {
                Valor = (notas[I]->text ().toFloat () + VALOR_MIN);
                //Valor += VALOR_MIN;
                qDebug () << "Valor: " << Valor;
                cadena.setNum (Valor, 'g', 3);
                notas[I]->setText (cadena);
                qDebug () << "Cadena: " << cadena;
                qDebug () << "Texto: " << notas[I]->text ();
            }
        }
        
        Prom = calcularPromedio ();
        qDebug () << "Prom: " << Prom;
        qDebug () << "PromE: " << PromE;
    }
}

/**
 * Cuando el texto de una nota cambia, esta función evalúa si la nota tiene contenido
 * o está en blanco y asigna la propiedad \em automática a la nota según corresponda;
 * luego calcula nuevamente el promedio.
 * \todo Explicar con más detalle el sistema de notas automáticas y manuales.
*/
void GestorNota::actualizarNota (const QString& texto, GNota* nota)
{
    //qDebug () << "Nota " << nota << " modificada: " << texto;
    if (texto == "")
        nota->setAuto (true);
    else
        nota->setAuto (false);
        
    promediar ();
}

/**
 * Quita la nota especificada en el puntero \em nota de la caja de notas.
 * Luego la quita de la lista de notas y es eliminada. Recalcula el promedio.
*/
void GestorNota::eliminarNota (GNota* nota)
{
    int Indice = notas.indexOf (nota);
    
    qDebug () << "\nEliminando nota." << endl;
    
    qDebug () << "Indice : " << Indice;
    qDebug () << "Size (notas) : " << notas.size () << endl;
    
    qDebug () << "Invisibilizando widget";
    notas[Indice]->setVisible (false);
    
    qDebug () << "Nota a eliminar: " << nota;
    
    
    qDebug () << "Quitando del layout";
    lytNotas->removeWidget (nota);
    
    qDebug () << "Quitando de la lista";
    notas.removeOne (nota);
    
    qDebug () << "Eliminando objeto" << nota;
    
    nota->close ();
    
    qDebug () << "Size (notas) : " << notas.size () << endl;
    
    if (notas.size () > 0)
        promediar ();
}


#include "GNotasWindow.moc"
