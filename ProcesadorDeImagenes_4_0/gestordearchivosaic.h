/*!
 *  \class      GestorDeArchivos
 *  \brief      Clase Encargado
 *  \details    Es una clase virtual pura.
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-07-23
 *  \date       Fecha de última modificación: 2023-07-23
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef GESTORDEARCHIVOSAIC_H
#define GESTORDEARCHIVOSAIC_H
#include "gestordearchivos.h"

class GestorDeArchivosAIC:public GestorDeArchivos
{
public:
    GestorDeArchivosAIC(string pRuta);

    Imagen virtual Cargar() override;
    void  virtual Guardar(string pNombre,string pFormato, Imagen &pImagen) override;


private:

    string Ruta;

};

#endif // GESTORDEARCHIVOSAIC_H
