#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Interfaz
{
public:
    Interfaz();
    void getKeyBindings();


    string getNombreNueva();
    string getFormatoNueva();
    void mostrarDir();
    void mostrarListaImagenes(vector<string> pLista);

    int getOpcion() const;
    void setOpcion(int newOpcion);

private:
    int opcion;


};

#endif // INTERFAZ_H
