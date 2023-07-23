#include "interfaz.h"

Interfaz::Interfaz()
{

}

void Interfaz::getKeyBindings()
{
    cout<<endl<<endl;
    cout<<"___________________________________________________________________"<<endl;
    cout <<"**********************LISTA DE COMANDOS***************************"<<endl;
    cout <<"__________________________________________________________________"<<endl<<endl;

    cout<<" Ctrl + flecha izquierda: Siguiente imagen en directorio"<<endl<<
          " Ctrl + flecha izquierda: Anterior imagen en directorio"<<endl<<
          " Ctrl + clic izquierdo: se pinta una region con el mismo color"<<endl<<
          " Ctrl + '+' : aumentar brillo"<<endl<<
          " Ctrl + '-' : disminuir brillo"<<endl<<
          " Ctrl + c   : ajustar contrastre"<<endl<<
          " Ctrl + b   : binarizar Imagen"<<endl<<
          " Ctrl + 1   : aplicar aplicar Pseudo Coloreo(LUT) Glow"<<endl<<
          " Ctrl + 2   : aplicar aplicar Pseudo Coloreo(LUT) Turbo"<<endl<<
          " Ctrl + s   : aplicar Filtro de Suavizado"<<endl<<
          " Ctrl + m   : aplicar Filtro de Mediana"<<endl<<
          " Ctrl + g   : guardar "<<endl;
}

string Interfaz::getNombreNueva()
{
  string aux;
  cout<<"Guardar Como: ";cin>>aux;
  cout<<endl;

  return aux;
}

string Interfaz::getFormatoNueva()
{
    string formato;
    cout<<"Seleccione un Formato para guardar la imagen"<<endl<<endl;
    cout<<"Formatos disponibles son P1,P2,P3,P4,P5,P6 O AIC";
    cout<<endl;
    cin>>formato;

    return formato;

}

void Interfaz::mostrarDir()
{
  int aux=0;
  cout<<"______________________________________________"<<endl;
  cout<<"SELECCIONE LA CARPETA A LA QUE QUIERE INGRESAR"<<endl;
  cout<<"______________________________________________"<<endl;

  cout<<" 1) Carpeta 1 " <<endl<<
        " 2) Carpeta 2 " <<endl<<
        " 3) Carpeta 3: Corruptas " <<endl<<
        " 4) Carpeta 4: ij_image_samples"<<endl<<
        " 5) Carpeta 5: Imagenes Modificadas"<<endl<<
        " 6) Salir del programa " <<endl<<endl;
cout<<"Eleccion: ";
  cin>>aux;
  setOpcion(aux);

  while(getOpcion() > 7)
  {
      cout<<endl<<endl;
      cout<< "La opcion de Carpeta no es valida vuelva a ingresar"<<endl;
      cin>>opcion;
      setOpcion(aux);;
  }
  cout<<endl<<endl;
  cout<<"Opcion escogida: "<<getOpcion();
  cout<<endl<<endl;
}

void Interfaz::mostrarListaImagenes(vector<string> pLista)
{
    cout<<endl;
    cout<<"LAS IMAGENES EN CARPETAS SON:"<<endl;
    for(unsigned int i=0;i<pLista.size();++i)
   {
        cout<<pLista[i]<<endl;
  }

}

int Interfaz::getOpcion() const
{
    return opcion;
}

void Interfaz::setOpcion(int newOpcion)
{
    opcion = newOpcion;
}
