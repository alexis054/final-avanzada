/*!
 *  \class      Pixel
 *  \brief      Clase creada con el fin de modelar un pixel
 *  \details
 *  \author      Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>//para accumulate

using namespace std;

class Pixel
{
public:
    Pixel();
    /*!
     * \brief getB es un metodo que me permite obtener el valor del canal azul del pixel
     * \return retorna un valor entero con el valor de azul del pixel
     */
    int getB() const;   
    /*!
     * \brief getR es un metodo que me permite obtener el valor del canal rojo del pixel
     * \return retorna un valor entero con el valor de rojo del pixel
     */
    int getR() const;
    /*!
     * \brief getG es un metodo que me permite obtener el valor del canal verde del pixel
     * \return retorna un valor entero con el valor de verde del pixel
     */
    int getG() const;
    /*!
     * \brief intensidad es un metodo que obtiene un promedio entre los 3 canales
     * \return retorna un valor entero con el valor promedio de los 3 canales
     */
    int intensidad();
    /*!
     * \brief setR es un metodo que se encarga de establecer el valor al canal rojo del pixel
     * \param newR es el valor que se le asignara al canal rojo
     */
    void setR(int newR);
    /*!
     * \brief setG es un metodo que se encarga de establecer el valor al canal verde del pixel
     * \param newG es el valor que se le asignara al canal verde
     */
    void setG(int newG);
    /*!
     * \brief setB es un metodo que se encarga de establecer el valor al canal azul del pixel
     * \param newB es el valor que se le asignara al canal azul
     */
    void setB(int newB);
    /*!
     * \brief [] es una sobrecarga de operadores que devuelve el valor de pixel en la posicion entre corchetes
     * \param pos es un entero que se le pasa al operador que asigna la posicion del pixel de la que se quiere obtener el valor
     * \return retorna un valor entero que es el valor del canal previamente seleccionado por pos
     */
    int operator [](int pos);
    /*!
     * \brief < es una sobrecarga de operadores que permite comparar las intensidades de dos pixeles
     * \param pComp es el otro pixel con el que se quiere comparar, este se pasa por referencia
     * \return retorna un valor bool con valor true si el pixel de la clase es menor al pixel pComp
     */
    bool operator <(Pixel &pComp);
    /*!
     * \brief + es una sobrecarga de operadores que permite sumar los valores de los canales entre dos pixeles
     * \param pPix es el otro pixel que se quiere sumar, es pasado por referencia
     * \return retorna un Pixel que tiene como canales la suma de cada canal
     */
    Pixel operator +(Pixel &pPix);
    /*!
     * \brief / es una sobrecarga de operadores que permite dividir los valores de los canales entre una constante
     * \param pConstante es el entero por el que se divide los canales
     * \return retorna un Pixel que tiene como canales la division de cada canal por la constante
     */
    Pixel operator /(const int pConstante);

private:
    /*!
     * \brief R es un entero que guarda el valor del canal rojo del pixel
     */
    int R;
    /*!
     * \brief G es un entero que guarda el valor del canal verde del pixel
     */
    int G;
    /*!
     * \brief B es un entero que guarda el valor del canal azul del pixel
     */
    int B;
    /*!
     * \brief RGB es un vector que almacena los posibles valores que puede tomar cada pixel con el formato RGB
     */
    vector<int> RGB;
};

#endif // PIXEL_H
