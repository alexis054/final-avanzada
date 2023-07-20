#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "imagen.h"
#include "filtro.h"
#include "filtroespacial.h"
#include "filtropap.h"
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
     void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
     void setImagen(const Imagen &newImagen);
     void algoritmoPintor(int pFil,int pCol);




protected:
     void initializeGL() override;
     void resizeGL(int pAncho,int pAlto)override;
     void paintGL()override;
     void DibujarHistograma();

     void keyPressEvent(QKeyEvent *pEvent) override;
     void mousePressEvent(QMouseEvent *pEvent) override;
     void mouseReleaseEvent(QMouseEvent *pEvent) override;


private:
     Imagen imagen;
     Imagen imagenOriginal;
     bool histo=false;
     void pintarRecursivo(int pFil,int pCol);
     void pintar();
     int maxVal;
     int tolerancia=50;
     vector<vector<bool>> mask;
     Pixel pixInicioPintado;
     int columnaInicial;
     int filaInicial;
     int contador;

};

#endif // GRAFICADOR_H

