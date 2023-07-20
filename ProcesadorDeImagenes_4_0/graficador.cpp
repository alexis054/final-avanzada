    #include "graficador.h"

Graficador::Graficador()
{
     srand(time(0));
}



void Graficador::mostrar(int pAncho, int pAlto, QApplication *pPtrApp)
{

    resize(pAncho,pAlto);
    show();
    pPtrApp->exec();
}

void Graficador::setImagen(const Imagen &newImagen)
{
    imagen = newImagen;
}


void Graficador::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.5f,0.5f,0.5f,0.0f);
}

void Graficador::resizeGL(int w, int h)
{
    //glViewport(0,0,width(),height());
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float xmin,xmax,ymin,ymax,zmin,zmax;

    xmin=-10;            xmax=10;
    ymin=-10;           ymax=10;
    zmin=-1;            zmax=1;
    if(imagen.getAlto()>0)
    {
        xmax=imagen.getAncho()+10;
        ymax=imagen.getAlto()+10;

    }

    glOrtho(xmin,xmax,ymin,ymax,zmin,zmax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL()
{


    resizeGL(width(),height());
    glClear(GL_COLOR_BUFFER_BIT);

   // glPushMatrix();
//
      //      glTranslatef(0,imagen.getAlto(),0);
       //     glScalef(1,-1,1);

//     glBegin(GL_QUADS);

//     //imagen
//    for( int f=0;f<imagen.getAlto();++f)

//     {
//         for( int c=0;c<imagen.getAncho();++c)
//         {

//           pix=imagen.getPixel(f,c);

//           R=(float)pix.getR()/(float)M;
//           G=(float)pix.getG()/(float)M;
//           B=(float)pix.getB()/(float)M;


//             glColor3f(R,G,B);
//             glVertex3f(c,f,0);
//             glVertex3f(c,f+1,0);
//             glVertex3f(c+1,f+1,0);
//             glVertex3f(c+1,f ,0);

//         }
//      }
//    glEnd();

   // glPopMatrix();

    DibujarHistograma();

   // glEnd();
}

void Graficador::DibujarHistograma()
{

//    Estadisticos stat;
//    cout<<"histo";
//    stat.setDatos(imagen);
//    vector<Pixel> Vec = stat.getVec();


//      glClear( GL_COLOR_BUFFER_BIT );
//      glPushMatrix();

//    glBegin(GL_LINE_STRIP);
//    glLineWidth(3.0);

//    for(unsigned int i=0;i<Vec.size();++i)
//    {
//        glColor3f(1,0,0);
//        glVertex2f(Vec[i].getR(),stat.Hist_R()[Vec[i].getR()]);


//    }

    Pixel pix;
    float R,G,B;
    int M=imagen.getM();

     glPushMatrix();

             glTranslatef(0,imagen.getAlto(),0);
             glScalef(1,-1,1);

      glBegin(GL_QUADS);

      //imagen
     for( int f=0;f<imagen.getAlto();++f)

      {
          for( int c=0;c<imagen.getAncho();++c)
          {

            pix=imagen.getPixel(f,c);

            R=(float)pix.getR()/(float)M;
            G=(float)pix.getG()/(float)M;
            B=(float)pix.getB()/(float)M;


              glColor3f(R,G,B);
              glVertex3f(c,f,0);
              glVertex3f(c,f+1,0);
              glVertex3f(c+1,f+1,0);
              glVertex3f(c+1,f ,0);

          }
       }
     glEnd();

     glPopMatrix();

    glEnd();
 glPopMatrix();

 /*   setWindowTitle(
                "Histograma. Maxima Frecuencia(MF)de Intensidad(I): "+ QString::fromStdString(to_string(maxFrecI))+
                " MF Intesidad: "  + QString::fromStdString(to_string(int(IdeMFI))) +
                " Rango de I:[ 0 , "  + QString::fromStdString(to_string(int(maxRangoDinamico))) +" ]"+
                " MF Rojo: "  + QString::fromStdString(to_string(maxFrecR)) +
                " , I de MF Rojo: "  + QString::fromStdString(to_string(int(IdeMFR))) +
                " MF Verde: "        + QString::fromStdString(to_string(maxFrecG)) +
                " ,I deMF Verde: "  + QString::fromStdString(to_string(int(IdeMFG))) +
                " MF Azul: "        + QString::fromStdString(to_string(maxFrecB)) +
                " ,I de MF Azul: "  + QString::fromStdString(to_string(int(IdeMFB))) );

*/
}
//----------------------------------------------------------------------------------------------------------------------------
//Eventos

void Graficador::keyPressEvent(QKeyEvent *pEvent)
{
    FiltroPaP filtroPaP;
    FiltroEspacial filtroEsp;

    bool ctrl_and_s=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_S;
    bool ctrl_and_m=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_M;
    bool ctrl_and_c=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_C;
    bool ctrl_and_g=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_G;
    bool ctrl_and_plus=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_Plus;
    bool ctrl_and_minus=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_Minus;
    bool ctrl_and_h=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_H;
    bool ctrl_and_left=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_Left;
    bool ctrl_and_right=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_Right;
    bool ctrl_and_one=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_1;
    bool ctrl_and_two=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_2;


    if(ctrl_and_s)
    {
        filtroEsp.filtradoSuavizado(imagen);
    }

    if(ctrl_and_m)
    {
        filtroEsp.filtradoMediana(imagen);
    }

     if(ctrl_and_c)
      {
          filtroPaP.Contraste(imagen);
      }

     if(ctrl_and_plus)
     {
         filtroPaP.Brillo(imagen);
     }

     if(ctrl_and_minus)
     {
         filtroPaP.Brillo(imagen);
     }

     if(ctrl_and_h)
     {
         histo=true;
         repaint();
     }


}


void Graficador::mousePressEvent(QMouseEvent *pEvent)
{
    //Creo un bool que indica si Ctrl y ClickIzquierdo fueron presionados al mismo tiempo
    bool ctrlAndClickIzq = pEvent->modifiers()& Qt::ControlModifier &&
                           pEvent->button() == Qt::LeftButton;

    if (ctrlAndClickIzq)
    {
        //Si Ctrl y ClickIzquierdofueron presionados, entonces guardo la posición del cursor

        columnaInicial = this->mapFromGlobal(QCursor::pos()).x();
        filaInicial = this->mapFromGlobal(QCursor::pos()).y();
    }
}



void Graficador::mouseReleaseEvent(QMouseEvent *pEvent)
{
    bool releaseCtrlAndClickIzq = pEvent->modifiers()& Qt::ControlModifier && pEvent->MouseButtonRelease;

    if(releaseCtrlAndClickIzq)
    {
        algoritmoPintor(  columnaInicial,filaInicial);

        repaint();
    }
}


void Graficador::algoritmoPintor(int pFil, int pCol)
{
    mask.clear();
    mask.resize(imagen.getAlto(),vector<bool>(imagen.getAncho(),false));//dimensiono la mascara de la imagen
    pixInicioPintado=imagen.getPixel(pFil,pCol);
    pintarRecursivo(pFil,pCol);
    pintar();
}

void Graficador::pintar()
{
    contador = 0;
    int R,G,B;

    R=0;
    G=0;
    B=imagen.getM();

    for(int i=0;i<imagen.getAlto();++i)
    {
        for(int j=0;j<imagen.getAncho();++j)
        {
            if(mask[i][j])
            {
                imagen.ModificarPixelTerna(i,j,R,G,B);
            }
        }
    }
}


void Graficador::pintarRecursivo(int pFila, int pCol)
{
        if(pFila < imagen.getAlto() && pCol < imagen.getAncho()
                && pFila>0 && pCol>0)
        {
            ;
            int aux;
            aux=pixInicioPintado.intensidad()-imagen.getPixel(pFila,pCol).intensidad();

            if(aux < tolerancia and mask[pFila][pCol]!=true and contador<10000)
            {
                mask [pFila] [pCol] = true;
                //Incrementa los pixeles contados
                ++contador;
                //Revisa la vecindad del pixel
                pintarRecursivo(pFila+1, pCol);
                pintarRecursivo(pFila-1, pCol);
                pintarRecursivo(pFila,   pCol+1);
                pintarRecursivo(pFila,   pCol-1);
            }
        }
}

