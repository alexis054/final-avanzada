#ifndef GESTORDEARCHIVOSPNM_H
#define GESTORDEARCHIVOSPNM_H
#include "gestordearchivos.h"

class GestorDeArchivosPNM : public GestorDeArchivos
{
public:
    GestorDeArchivosPNM(string pRuta);
    Imagen Cargar() override;
    void Guardar() override;
private:
    string Ruta;
};

#endif // GESTORDEARCHIVOSPNM_H