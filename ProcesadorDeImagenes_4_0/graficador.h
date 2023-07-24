/*!
 *  \class      Graficador
 *  \brief      Clase encargada de graficar
 *  \details    se encarga de la visualizacion de la imagen y de la interaccion mediante eventos de teclado
 *  \author     Gonzalez Alexis Joaquin.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2023-04-06
 *  \date       Fecha de última modificación: 2023-07-24
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "imagen.h"
#include "filtroespacial.h"
#include "filtropap.h"
#include "lut.h"
#include "gestordearchivos.h"
#include "gestordearchivosaic.h"
#include "gestordearchivospnm.h"
#include "interfaz.h"
#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QKeyEvent>
#include <vector>
#include <QMouseEvent>

using namespace std;

class Graficador: public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    Graficador();
    /*!
     * \brief mostrar metodo encargado de mostrar la imagen
     * \param pPtrApp es un puntero a un objeto QApplication encargado de ejecutar la aplicacion
     */
     void mostrar( QApplication *pPtrApp);
     /*!
      * \brief setImagen es el metodo encargado de establecer la imagen
      */
     void setImagen();
     /*!
      * \brief algoritmoPintor es un metodo encargado de pintar un area con el mismo color de un pixel previamente seleccionado
      * \param pFil contiene el valor de la fila donde se ubica el pixel de interes
      * \param pCol contiene el valor de la columna donde se ubica el pixel de interes
      */
     void algoritmoPintor(int pFil,int pCol); 
     /*!
      * \brief setListaDeArchivos permite establecer la lista de imagenes en el directorio
      * \param newListaDeArchivos contiene la lista de imagenes en el directorio escogido
      */
     void setListaDeArchivos(const vector<string> &newListaDeArchivos);
     /*!
      * \brief setListaRutas permite establecer la lista de ruta de las imagenes en el directorio
      * \param newListaRutas contiene la lista de ruta de las imagenes en el directorio escogido
      */
     void setListaRutas(const vector<string> &newListaRutas);

protected:
     /*!
     * \brief initializeGL es un metodo redefinido de QOpenGLWidget que inicializa el color
     * de la ventana de graficacion
     */
     void initializeGL() override;
     /*!
      * \brief resizeGL es un metodo redefinido de QOpenGLWidget que permite redimensionar el tamaño
      * de la pantalla de graficacion.
      * \param pAncho representa al ancho de la venta de graficacion
      * \param pAlto representa al alto de la ventana de graficacion
      */
     void resizeGL(int pAncho,int pAlto)override;
     /*!
      * \brief paintGL es un metodo redefinido de QOpenGLWidget en el que se realizan los dibujos que se
      *  quieren observar en la ventana de graficacion
      */
     void paintGL()override;    
     /*!
      * \brief keyPressEvent es un metodo redefinido de QKeyEvent que permite trabajar con los atajos de teclado
      * \param pEvent es un puntero a un objeto de tipo QKeyEvent que permite interacturar con las teclas del
      * teclado
      */
     void keyPressEvent(QKeyEvent *pEvent) override;
     /*!
      * \brief mousePressEvent es un metodo redefinido de QMouseEvent que permite establecer acciones cuando se presione
      * el boton del mouse.
      * \param pEvent es un puntero de un objeto de tipo QMouseEvent que permite interactuar con el boton del mouse.
      */
     void mousePressEvent(QMouseEvent *pEvent) override;
     /*!
      * \brief mouseReleaseEvent es un metodo redefinido de QMouseEvent que permite definir acciones cuando
      * se deje de presionar el boton del mouse
      * \param pEvent es un puntero a un objeto de tipo QMouseEvent que permite interacturar con el boton del mouse
      */
     void mouseReleaseEvent(QMouseEvent *pEvent) override;


private:


     //Atributos
     /*!
      * \brief Imagen contiene la imagen que se quiere graficar y modificar
      */
     Imagen imagen;
     /*!
      * \brief imagenOriginal contiene la imagen a graficar sin modificar
      */
     Imagen imagenOriginal;
     /*!
      * \brief mask matriz de bool utilizada para seleccionar que pixeles pintar en el algoritmo del pintor
      */
     vector<vector<bool>> mask;
     /*!
      * \brief pixInicioPintado contiene el pixel donde se comienza a pintar con el algoritmo del pintor
      */
     Pixel pixInicioPintado;
     /*!
      * \brief gda apunta a un puntero de tipo archivo, esto le permite tener un comportamiento polimorfico
      */
     GestorDeArchivos *gda;
     /*!
      * \brief lut es una instancia de un objeto tipo lut que permite acceder a las tablas y
      * modificar la imagen
      */
     Lut lut;
     /*!
      * \brief ui es una instnacia del objeto interfaz que le permite a la clase interaccionar con
      * el usuario
      */
     Interfaz ui;
     /*!
      * \brief listaRutas contiene la lista de la rutas de las imagenes del directorio
      */
     vector<string> listaRutas;
     /*!
      * \brief listaDeArchivos contiene la lista con los nombres de las imagenes del directorio
      */
     vector<string> listaDeArchivos;
     /*!
      * \brief histo es un controlador para dibujar el histograma, esta inicializado en falso, de ser verdadero
      * se llama a dibujar el histograma
      */
     bool histo=false;
     /*!
      * \brief tolerancia guarda un valor a partir del cual se binarizara
      */
     float tolerancia=50;
     /*!
      * \brief relacionAncho guarda informacion sobre la continuidad de relacion y
      * aspecto en ancho de la imagen y la ventana
      */
     float relacionAncho;
     /*!
      * \brief relacionAncho guarda informacion sobre la continuidad de relacion y
      * aspecto en alto de la imagen y la ventana
      */
     float relacionAlto;
     /*!
      * \brief escala almacena la relación entre las dimensiones de la ventana y las de la imagen.
      */
     float escala;
     /*!
      * \brief dx almacena la posicion de la imagen en la ventana en sentido horizontal
      */
     float dx;
     /*!
      * \brief dy almacena la posicion de la imagen en la ventana en sentido vertical
      */
     float dy;
     /*!
      * \brief columnaInicial almacena el valor de columna del pixel que se selecciona como inicial
      */
     int columnaInicial;
     /*!
      * \brief filaInicial almacena el valor de fila del pixel que se selecciona como inicial
      */
     int filaInicial;
     /*!
      * \brief contador es utilizado para establecer un limite en el algoritmo del pintor para que no crashee por
      * la cantidad de iteraciones
      */
     int contador;
     /*!
      * \brief permite recorrer las imagenes del directorio
      */
     unsigned int indice;




     //Metodos
     /*!
      * \brief pintarRecutsivo es un metodo interno de la clase encargado de seleccionar que pixel pintar en el
      * algoritmo del pintor
      * \param pFil contiene el valor de la fila del pixel inicial
      * \param pCol contiene el valor de la columna del pixel inicial
      */
     void pintarRecursivo(int pFil,int pCol);
     /*!
      * \brief pintar metodo interno de la clase utilizado para pintar los pixeles en el algoritmo del pintor
      */
     void pintar();
     /*!
      * \brief getIntensidadpix es un metodo interno utilizado para calcular las diferencias de intensidades de pixeles
      * en el algoritmo del pintor
      */
     float getIntensidadpix(Pixel pix);
     /*!
      * \brief DibujarImagen es un metodo interno de la clase encargado de dibujar la imagen
      */
     void DibujarImagen();
     /*!
      * \brief DibujarHistograma es un metodo interno de la clase encargado de dibujar el histograma
      */
     void DibujarHistograma();


};

#endif // GRAFICADOR_H

