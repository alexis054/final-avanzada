/*!
 *  \class      Estadisticos
 *  \brief      Clase encargada con el fin de realizar calculos estadisticos de la imagen
 *  \details    obtiene histogramas, maximos, minimos, medianas, modas, desvios estandar y  promedios
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef ESTADISTICOS_H
#define ESTADISTICOS_H
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#include "imagen.h"

using namespace std;

class Estadisticos
{
public:
    Estadisticos();
//histogramas

    /*!
     * \brief Hist_intensidad es un metodo que se encarga de armar un map donde la clave es la intensidad y el valor es la cantidad de veces que
     * esa intensidad se repite, ademas es el encargado de encontrar la intensidad que mas se repite y cuantas veces lo hace
     * \return retorna un map de enteros con claves enteras
     */
    map<int,int> Hist_intensidad();  
    /*!
     * \brief Hist_R  es un metodo que se encarga de armar un map donde la clave es la intensidad del canal rojo y el valor es la cantidad de veces que
     * esa intensidad se repite, ademas es el encargado de encontrar la intensidad que mas se repite y cuantas veces lo hace
     * \return retorna un map de enteros con claves enteras
     */
    map<int,int> Hist_R();
    /*!
     * \brief Hist_G  es un metodo que se encarga de armar un map donde la clave es la intensidad del canal verde y el valor es la cantidad de veces que
     * esa intensidad se repite, ademas es el encargado de encontrar la intensidad que mas se repite y cuantas veces lo hace
     * \return retorna un map de enteros con claves enteras
     */
    map<int,int> Hist_G();
    /*!
     * \brief Hist_R  es un metodo que se encarga de armar un map donde la clave es la intensidad del canal azul y el valor es la cantidad de veces que
     * esa intensidad se repite, ademas es el encargado de encontrar la intensidad que mas se repite y cuantas veces lo hace
     * \return retorna un map de enteros con claves enteras
     */
    map<int,int> Hist_B();
    /*!
     * \brief Promedio_Intensidad es un metodo encargado de obtener el promedio de la intensidad de todos los pixeles de la imagen
     * \return retorna un valor de entero con el promedio de intensidad
     */
    int Promedio_Intensidad();
    /*!
     * \brief Promedio_R es un metodo encargado de obtener el promedio del canal Rojo de todos los pixeles de la imagen
     * \return retorna un valor de entero con el valor promedio del canal rojo
     */
    int Promedio_R();
    /*!
     * \brief Promedio_G es un metodo encargado de obtener el promedio del canal verde de todos los pixeles de la imagen
     * \return retorna un valor de entero con el valor promedio del canal verde
     */
    int Promedio_G();
    /*!
     * \brief Promedio_B es un metodo encargado de obtener el promedio del canal Azul de todos los pixeles de la imagen
     * \return retorna un valor de entero con el valor promedio del canal azul
     */
    int Promedio_B();   
    /*!
     * \brief Moda es un metodo encargado de obtener la moda de los pixeles de la imagen
     * \return retorna un objeto tipo pixel con el pixel de la moda
     */
    Pixel Moda();
    /*!
     * \brief Mediana es un metodo encargado de obtener la mediana de los pixeles de la imagen
     * \return retorna un objeto tipo pixel con el pixel de la mediana
     */
    Pixel Mediana();
    /*!
     * \brief MedianaR es un metodo encargado de obtener la mediana del canal rojo de los pixeles de la imagen
     * \return retorna un entero con el valor de la mediana del canal rojo de los pixeles
     */
    int MedianaR();
    /*!
     * \brief MedianaG es un metodo encargado de obtener la mediana del canal verde de los pixeles de la imagen
     * \return retorna un entero con el valor de la mediana del canal verde de los pixeles
     */
    int MedianaG();
    /*!
     * \brief MedianaB es un metodo encargado de obtener la mediana del canal azul de los pixeles de la imagen
     * \return retorna un entero con el valor de la mediana del canal azul de los pixeles
     */
    int MedianaB();
    /*!
     * \brief DesvioSTD es un metodo que se encarga de obtener el desvio estandar de intensidades, rojos, verdes y azules y
     * los lmacena en un vector de flotantes
     * \return retorna un vector de flotantes con los valores de los desvios estandar
     */
    vector<float> DesvioSTD();
    /*!
     * \brief Max_intensidad es un metodo encargado de obtener el maximo valor de intensidad de los pixeles de la imagen
     * \return retorna un entero con el valor de la maxima intensidad
     */
    int Max_Intensidad();
    /*!
     * \brief Min_intensidad es un metodo encargado de obtener el minimo valor de intensidad de los pixeles de la imagen
     * \return retorna un entero con el valor de la minimo intensidad
     */
    int Min_Intensidad();

    /*!
     * \brief Max_R es un metodo encargado de obtener el maximo valor de los canales de rojo de los pixeles de la imagen
     * \return retorna un entero con el valor maximo encontrado en el canal de rojo
     */
    int Max_R();
    /*!
     * \brief Max_G es un metodo encargado de obtener el maximo valor de los canales de verde de los pixeles de la imagen
     * \return retorna un entero con el valor maximo encontrado en el canal de verde
     */
    int Max_G();
    /*!
     * \brief Max_B es un metodo encargado de obtener el maximo valor de los canales de azul de los pixeles de la imagen
     * \return retorna un entero con el valor maximo encontrado en el canal de azul
     */
    int Max_B();
    /*!
     * \brief Min_R es un metodo encargado de obtener el minimo valor de los canales de rojo de los pixeles de la imagen
     * \return retorna un entero con el valor minimo encontrado en el canal de rojo
     */
    int Min_R();
    /*!
     * \brief Min_G es un metodo encargado de obtener el minimo valor de los canales de verde de los pixeles de la imagen
     * \return retorna un entero con el valor minimo encontrado en el canal de verde
     */
    int Min_G();
    /*!
     * \brief Min_B es un metodo encargado de obtener el minimo valor de los canales de azul de los pixeles de la imagen
     * \return retorna un entero con el valor minimo encontrado en el canal de azul
     */
    int Min_B();
    /*!
     * \brief setDatos es un metodo que permite establecer los datos de la imagen de los que se quieren saber sus estadisticos
     * \param newDatos contiene la imagen de la que se quieren saber los estadisticos
     */
    void setDatos(const Imagen &newDatos);
    /*!
     * \brief Ordenar es un metodo utilizado para facilitar los calculos, genera un vector a partir de la matriz de imagen
     * y lo ordena
     */
    void Ordenar();
    /*!
     * \brief setVec permite obtener un vector de pixeles del cual se quieran saber sus estadisticos
     */
    void setVec(const vector<Pixel> &newVec);
    /*!
     * \brief getVec es un metodo que permite obetener el vector de datos con el que se esta realizando los estadisticos
     * \return retorna un vector de pixeles
     */
    const vector<Pixel> &getVec() const;

    /*!
     * \brief getMF_R devuelve la intensidad del canal rojo que mas se repite y la cantidad de veces que se repite
     * \return retorna un pair siendo el primero la intensidad y el segundo la cantidad de veces que se repite esa intensidad
     */
    const pair<unsigned int, unsigned int> &getMF_R() const;
    /*!
     * \brief getMF_intensidad devuelve la intensidades que mas se repiten y la cantidad de veces que se repite
     * \return retorna un pair siendo el primero la intensidad y el segundo la cantidad de veces que se repite esa intensidad
     */
    const pair<unsigned int, unsigned int> &getMF_intensidad() const;
    /*!
     * \brief getMF_G devuelve la intensidad del canal verde que mas se repite y la cantidad de veces que se repite
     * \return retorna un pair siendo el primero la intensidad y el segundo la cantidad de veces que se repite esa intensidad
     */
    const pair<unsigned int, unsigned int> &getMF_G() const;
    /*!
     * \brief getMF_B devuelve la intensidad del canal azul que mas se repite y la cantidad de veces que se repite
     * \return retorna un pair siendo el primero la intensidad y el segundo la cantidad de veces que se repite esa intensidad
     */
    const pair<unsigned int, unsigned int> &getMF_B() const;

private:
    /*!
     * \brief  Datos almacena los datos de los que se quieren obtener los estadisticos en forma de matriz
     */
    Imagen Datos;
    /*!
     * \brief  Vec almacena los datos de los que se quieren obtener los estadisticos en forma de vector
     */
    vector<Pixel> Vec;
    /*!
     * \brief  MF_R almacena la intensidad del canal rojo que mas se repite y la cantidad de veces que este se repite
     */
    pair<unsigned int, unsigned int> MF_R;
    /*!
     * \brief  MF_G almacena la intensidad del canal cerde que mas se repite y la cantidad de veces que este se repite
     */
    pair<unsigned int, unsigned int> MF_G;
    /*!
     * \brief  MF_B almacena la intensidad del canal azul que mas se repite y la cantidad de veces que este se repite
     */
    pair<unsigned int, unsigned int> MF_B;
    /*!
     * \brief  MF_intensidad almacena la intensidad que mas se repite y la cantidad de veces que esta se repite
     */
    pair<unsigned int, unsigned int> MF_intensidad;

};

#endif // ESTADISTICOS_H
