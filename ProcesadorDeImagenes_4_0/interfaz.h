#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include <iostream>

using namespace std;

class Interfaz
{
public:
    Interfaz();
    void getDir();
    void getKeyBindings();


    string getNombreNueva();
    string getFormatoNueva();
    void mostrarDir();

    int getOpcion() const;
    void setOpcion(int newOpcion);

private:
    int opcion;


};

#endif // INTERFAZ_H
