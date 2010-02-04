/// \file GRamo.h Declaración de la clase GRamo que representa una asignatura.

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

#ifndef GRAMO_H
#define GRAMO_H

#include <QtGui/QListWidgetItem>
#include <QtCore/QString>

/**
 * \class GRamo
 * \brief Representa un ramo o asignatura en GEARC.
 * 
 * Almacena la información como el nombre del ramo y el nombre del profesor.
 * También almacena las notas que posee este ramo.
*/

class GRamo : public QListWidgetItem
{
public:
    
    GRamo (const QString &nombre, const QString &nombreProfesor,
           QListWidget *parent = 0);
           
    ~GRamo();
    
    /**
     * Establece el nombre del ramo.
     * \sa nombre
    */
    void setNombre (const QString &nVal) {m_Nombre = nVal;}
    
    /**
     * Establece el nombre del profesor del ramo.
     * \sa nombreProfesor
    */
    void setNombreProfesor (const QString &nVal) {m_NombreProfesor = nVal;}
    
    /**
     * Retorna el nombre del ramo.
     * \sa setNombre
    */
    QString nombre () const {return m_Nombre;}
    
    /**
     * Retorna el nombre del profesor del ramo.
     * \sa setNombreProfesor
    */
    QString nombreProfesor () const {return m_NombreProfesor;}
    
private:
    QString m_Nombre; /**< Nombre del ramo */
    QString m_NombreProfesor; /**< Nombre del profesor del ramo */
    
};

#endif // GRAMO_H
