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
