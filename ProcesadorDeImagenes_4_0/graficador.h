#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "imagen.h"
#include "filtro.h"
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
#include <iostream>
#include <vector>
#include <QMouseEvent>

using namespace std;

class Graficador: public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    Graficador();
     void mostrar( QApplication *pPtrApp);
     void setImagen();
     void algoritmoPintor(int pFil,int pCol); 
     void setListaDeArchivos(const vector<string> &newListaDeArchivos);
     void setListaRutas(const vector<string> &newListaRutas);

protected:
     void initializeGL() override;
     void resizeGL(int pAncho,int pAlto)override;
     void paintGL()override;
     void DibujarHistograma();

     void keyPressEvent(QKeyEvent *pEvent) override;
     void mousePressEvent(QMouseEvent *pEvent) override;
     void mouseReleaseEvent(QMouseEvent *pEvent) override;


private:


     //Atributos
     Imagen imagen;
     Imagen imagenOriginal;
     vector<vector<bool>> mask;
     Pixel pixInicioPintado;
     GestorDeArchivos *gda;
     Lut lut;
     Interfaz ui;
     vector<string> listaRutas;
     vector<string> listaDeArchivos;
     bool histo=false;
     float dela_intensidad=0.0;
     float tolerancia=50;
     float relacionAncho;
     float relacionAlto;
     float escala;
     float dx;
     float dy;
     int columnaInicial;
     int filaInicial;
     int contador;
     unsigned int indice;




     //Metodos

     void pintarRecursivo(int pFil,int pCol);
     void pintar();   
     float getIntensidadpix(Pixel pix);
     void DibujarImagen();



};

#endif // GRAFICADOR_H

