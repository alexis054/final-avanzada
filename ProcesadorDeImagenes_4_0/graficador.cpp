    #include "graficador.h"

Graficador::Graficador()
{
     srand(time(0));
     indice=0;
     dx=0.0;
     dy=0.0;
     gda=NULL;

}

void Graficador::mostrar(QApplication *pPtrApp)
{
    resize(imagen.getAncho(),imagen.getAlto());
    show();
    pPtrApp->exec();
}

void Graficador::setImagen()
{
    string nombre;
    string ruta;
    string formato;
    int posicion;

    nombre=listaDeArchivos[indice];
    ruta=listaRutas[indice];
    posicion=nombre.find_last_of(".");
    formato=nombre.substr(posicion);


    if(formato == ".pgm" or formato== ".pbm" or formato == ".ppm" or formato == ".pnm")
    {
        gda= new GestorDeArchivosPNM(ruta);
    }
    if(formato==".aic")
    {
        gda = new GestorDeArchivosAIC(ruta);
    }

    imagen=gda->Cargar();
    imagenOriginal=imagen;

    delete gda;

    setWindowTitle(nombre.c_str()); //casteo

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


    glOrtho(xmin,w+xmax,ymin,h+ymax,zmin,zmax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL()
{

    Pixel pix;
    float R,G,B;
    int M=imagen.getM();

    //resizeGL(width(),height());
    glClear(GL_COLOR_BUFFER_BIT);

    relacionAncho=(float)width()/(float)imagen.getAncho();
    relacionAlto=(float)height()/(float)imagen.getAlto();

    escala=1.0f;
    dx=0.0f;
    dy=0.0f;

    if(relacionAncho<relacionAlto)
    {
        escala=relacionAncho;

        dy=(height()-(float)(imagen.getAlto()*escala))*0.5f;
    }
    else
    {
        escala=relacionAlto;
        dx=(width()-(float)(imagen.getAncho()*escala))*0.5f;
    }

//---------------------------------grafico

    glPushMatrix();


    glTranslatef(dx,dy,0.0f);
    glScalef(escala,escala,1.0f);

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


           glVertex2i(c, imagen.getAlto()-f);
           glVertex2i(c, imagen.getAlto()-(f+1));
           glVertex2i(c+1, imagen.getAlto()-(f+1));
           glVertex2i(c+1, imagen.getAlto()-f);

         }
      }
    glEnd();

    glPopMatrix();
    setWindowTitle(listaDeArchivos[indice].c_str());
   // DibujarHistograma();

   // glEnd();
}

void Graficador::DibujarHistograma()
{

    Estadisticos stat;
    cout<<"histo";
   stat.setDatos(imagen);
   vector<Pixel> Vec = stat.getVec();


     glClear( GL_COLOR_BUFFER_BIT );
     glPushMatrix();

   glBegin(GL_LINE_STRIP);
   glLineWidth(3.0);

   for(unsigned int i=0;i<Vec.size();++i)
   {
       glColor3f(1,0,0);
        glVertex2f(Vec[i].getR(),stat.Hist_R()[Vec[i].getR()]);
    }



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
    bool ctrl_and_x=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_X;
    bool ctrl_and_b=pEvent->modifiers() & Qt::ControlModifier and pEvent->key() == Qt::Key_B;

    if(ctrl_and_b)
    {
        filtroPaP.Binarizar(imagen);
        repaint();
    }

    if(ctrl_and_x)
    {
        imagen=imagenOriginal;
        repaint();
    }

    if(ctrl_and_left)
    {
        if(indice>0)
        {
            indice--;
            setImagen();
            repaint();
        }
    }

    if(ctrl_and_right)
    {
        if(indice<listaDeArchivos.size()-1)
        {
            indice++;
            setImagen();
            repaint();
        }
    }

    if (ctrl_and_g)
    {
            gda=NULL;
            string nombre=ui.getNombreNueva();
            string formato=ui.getFormatoNueva();

            if(formato=="aic")
            {
                gda=new GestorDeArchivosAIC(listaRutas[indice]);
                nombre += ".aic";

            }
            else
            {
                gda=new GestorDeArchivosPNM(listaRutas[indice]);
            if(formato=="P1" or formato=="P4")
            {
                nombre +=".pbm";
            }
            if(formato=="P2" or formato=="P5")
            {
                nombre +=".pgm";
            }
            if(formato=="P3" or formato=="P6")
            {
                nombre +=".ppm";
            }
            }
            gda->Guardar(nombre,formato,imagen);
    }

    if(ctrl_and_s)
    {
        filtroEsp.filtradoSuavizado(imagen);
        repaint();
    }

    if(ctrl_and_m)
    {
        filtroEsp.filtradoMediana(imagen);
        repaint();
    }

     if(ctrl_and_c)
      {
          filtroPaP.Contraste(imagen);
          repaint();
      }

     if(ctrl_and_plus)
     {
         filtroPaP.Brillo(imagen);
         repaint();
     }

     if(ctrl_and_minus)
     {
         filtroPaP.Brillo(imagen);
         repaint();
     }

     if(ctrl_and_h)
     {
         histo=true;
         repaint();
     }

     if(ctrl_and_one)
     {
         imagen=imagenOriginal;
         lut.cargar(1);
         lut.modificarimg(imagen);
         repaint();
     }

     if(ctrl_and_two)
     {
         imagen=imagenOriginal;
         lut.cargar(2);
         lut.modificarimg(imagen);
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
        algoritmoPintor( filaInicial,columnaInicial);

        repaint();
    }
}

void Graficador::setListaRutas(const vector<string> &newListaRutas)
{
    listaRutas = newListaRutas;
}

void Graficador::setListaDeArchivos(const vector<string> &newListaDeArchivos)
{
    listaDeArchivos = newListaDeArchivos;

}


void Graficador::algoritmoPintor(int pFil, int pCol)
{
    mask.clear();//limpio la mascara
    mask.resize(imagen.getAlto(),vector<bool>(imagen.getAncho(),false));//dimensiono la mascara de la imagen

    pixInicioPintado=imagen.getPixel(pFil,pCol);//asigno el pixel inicial
    pintarRecursivo(pFil,pCol);//llamo a pintar recursivo para dar valores a mascara
    pintar();//pinto
}

void Graficador::pintar()
{
    contador = 0;//inicializo contador para que no haya buffer overflow
    int R,G,B;

    R=0;
    G=0;
    B=imagen.getM();//asigno un color para pintar

    for(int i=0;i<imagen.getAlto();++i)//recorro la imagen
    {
        for(int j=0;j<imagen.getAncho();++j)
        {
            if(mask[i][j])//si la mascara es verdadera
            {
                imagen.ModificarPixelTerna(i,j,R,G,B);//pinto los pixeles que me indique la mascara
            }
        }
    }
}

float Graficador::getIntensidadpix(Pixel pix)
{
    float intensidad=0.0;

    intensidad=sqrt(
            pow((pixInicioPintado.getR())-(pix.getR()),2)+
            pow((pixInicioPintado.getG())-(pix.getG()),2)+
            pow((pixInicioPintado.getB())-(pix.getB()),2));

    return intensidad;
}


void Graficador::pintarRecursivo(int pFila, int pCol)
{
        if(pFila < imagen.getAlto() && pCol < imagen.getAncho()  //controlo que filas y columnas esten dentro de
                && pFila>0 && pCol>0)                            //rango
        {
            if(getIntensidadpix(imagen.getPixel(pFila,pCol)) <= tolerancia and mask[pFila][pCol]!=true and contador<15000) //si la diferencia de intensidades
            {                                                                   //es menor a una tolerancia y si el contador es
                mask [pFila] [pCol] = true; //mascara verdadero (pinto)                // menor a un valor para que el programa no crashee

                ++contador;// aumento el contador

                //Revisa la vecindad del pixel
                pintarRecursivo(pFila+1, pCol);
                pintarRecursivo(pFila+1, pCol+1);
                pintarRecursivo(pFila-1, pCol);
                pintarRecursivo(pFila-1, pCol-1);
                pintarRecursivo(pFila,   pCol+1);
                pintarRecursivo(pFila,   pCol-1);
                pintarRecursivo(pFila+1, pCol-1);
                pintarRecursivo(pFila-1, pCol+1);
            }
        }
}

