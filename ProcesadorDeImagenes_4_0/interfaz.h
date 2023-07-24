/*!
 *  \class      Interfaz
 *  \brief      Clase creada con el fin de interactuar con el usuario
 *  \details    Se encarga de la interaccion entre el usuario y el programa
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-01-16
 *  \date       Fecha de última modificación: 2023-07-23
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
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
    /*!
     * \brief getKeyBindings se encarga de mostrar los atajos de teclado implementados por consola.
     */
    void getKeyBindings();
    /*!
     * \brief geNombreNueva es un metodo que se encarga de devolver el nombre de la nueva imagen a guardar
     * \return retorna un string que contiene el nombre de la nueva imagen
     */
    string getNombreNueva();
    /*!
     * \brief getFormatoNueva es un metodo que se encarga de devolver el formato de la nueva imagen a guardar
     * \return retorna un string que contiene el formato de la nueva imagen
     */
    string getFormatoNueva();
    /*!
     * \brief mostrarDir es un metodo encargado de mostrar las carpetas a las que se puede acceder en el directorio
     * tambien es el metodo donde el usuario ingresa la opcion de carpeta a la que quiere acceder
     */
    void mostrarDir();
    /*!
     * \brief mostrarListaImagenes es un metodo que se encarga de mostrar por consola las imagenes de un directorio
     * \param pLista es un vector de strings que contiene la lista de imagenes que se encuentran en el actual directorio
     */
    void mostrarListaImagenes(vector<string> pLista);
    /*!
     * \brief getOpcion es un metodo que se encarga de devolver la opcion escogida por el usuario
     * \return retorna un valor entero que contiene la opcion escogida por el usuario
     */
    int getOpcion() const;
    /*!
     * \brief setOpcion es un metodo que se encarga de establecer la opcion de carpeta
     * \param newOpcion es un entero que contiene la opcion de carpeta escogida por el usuario
     */
    void setOpcion(int newOpcion);

private:
    /*!
     * \brief opcion almacena la opcion escogida por el usuario
     */
    int opcion;


};

#endif // INTERFAZ_H
