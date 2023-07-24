/*!
 *  \class      Imagen
 *  \brief      Clase creada con el fin de modelar una imagen
 *  \details    modela atributos y comportamientos de una imagen
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef IMAGEN_H
#define IMAGEN_H
#include "pixel.h"
#include <vector>
#include <string>

using namespace std;

class Imagen
{
public:
    Imagen();


    /*!
     * \brief getM este metodo permite obtener el rango dinamico de la imagen
     * \return retorna un entero con el rango dinamico de la imagen
     */
    int getM() const;
    /*!
     * \brief getAlto este metodo permite obtener el alto de la imagen
     * \return retorna un entero con el alto de la imagen
     */
    int getAlto() const;
    /*!
     * \brief getAncho este metodo permite obtener el ancho de la imagen
     * \return retorna un entero con el ancho de la imagen
     */
    int getAncho() const;
    /*!
     * \brief getMetadatos este metodo permite obtener los metadatos de la imagen
     * \return retorna un string con los metadatos
     */
    const string &getMetadatos() const;
    /*!
     * \brief setM este metodo permite establecer el rango dinamico de la imagen
     * \param newM es un entero que contiene el rango dinamico de la imagen
     */
    void setM(int newM);
    /*!
     * \brief setAlto este metodo permite establecer el alto de la imagen
     * \param newAlto es un entero con el alto de la imagen
     */
    void setAlto(int newAlto);
    /*!
     * \brief setAncho este metodo permite establecer el ancho de la imagen
     * \param newAncho es un entero con el ancho de la imagen
     */
    void setAncho(int newAncho);
    /*!
     * \brief setMetadatos este metodo permite establecer los metadatos de la imagen
     * \param newMetadatos es un string pasado por referencia con los metadatos de la imagen
     */
    void setMetadatos(const string &newMetadatos);
    /*!
     * \brief ModificarPixelTerna permite modificar los 3 canales de un pixel en una posicion de la matriz imagen
     * \param pPosF es un entero que contiene la posicion en la fila del pixel que se busca
     * \param pPosC es un entero que contiene la posicion en la columna del pixel que se busca
     * \param pR es un entero que contiene el valor del canal de rojo
     * \param pG es un entero que contiene el valor del canal de verde
     * \param pB es un entero que contiene el valor del canal de azul
     */;
    void ModificarPixelTerna(int pPosF, int pPosC, int pR, int pG, int pB);
    /*!
     * \brief ReservarMemoria se encarga de dimensionar la matriz de imagen con los valores de alto y ancho
     */;
    void ReservarMemoria()
    /*!
     * \brief getPixel permite obtener el Pixel en una posicion determinada de la matriz de imagen
     * \param pPosF es un entero que contiene la posicion en la fila del pixel que se busca
     * \param pPosC es un entero que contiene la posicion en la columna del pixel que se busca
     * \return retorna el pixel en la posicion de fila y columna que se paso como parametro
     */;
    Pixel getPixel(int pPosF,int pPosC);
    /*!
     * \brief getFormato este metodo permite obtener el formato de la imagen.
     * \return retorna un string con el formato de la imagen.
     */
    const string &getFormato() const;
    /*!
     * \brief setFormato este metodo permite establecer el formato de la imagen
     * \param new formato es un string pasado por referencia con el formato de la imagen
     */
    void setFormato(const string &newFormato);

private:
    /*!
     * \brief Img es una matriz que almacena pixeles en sus filas y columnas
     */
    vector<vector<Pixel>> Img;
    /*!
     * \brief M es un entero que almacena el rango dinamico maximo de la imagen
     */
    int M;
    /*!
     * \brief alto es un entero que almacena el alto de la imagen
     */
    int alto;
    /*!
     * \brief ancho es un entero que almacena el ancho de la imagen
     */
    int ancho;
    /*!
     * \brief metadatos es un string que almacena los metadatos de la imagen
     */
    string metadatos;
    /*!
     * \brief formato es un string que almacena el formato de la imagen
     */
    string Formato;


};

#endif // IMAGEN_H
