#include "interfaz.h"

Interfaz::Interfaz()
{

}

void Interfaz::getKeyBindings()
{
    cout<<endl<<endl;
    cout << " --------------------------LISTA DE COMANDOS---------------------------------------"<<endl<<endl;

    cout<<"1) Ctrl + flecha izquierda: Siguiente imagen en directorio"<<endl<<
          "2) Ctrl + flecha izquierda: Anterior imagen en directorio"<<endl<<
          "3) Ctrl + clic izquierdo: se pinta una region con el mismo color"<<endl<<
          "4) Ctrl + '+' : aumentar brillo"<<endl<<
          "5) Ctrl + '-' : disminuir brillo"<<endl<<
          "6) Ctrl + c   : ajustar contrastre"<<endl<<
          "7) Ctrl + b   : binarizar Imagen en gris"<<endl<<
          "8) Ctrl + 1   : aplicar aplicar Pseudo Coloreo(LUT) purpura a Imagenes con Intensidad"<<endl<<
          "9) Ctrl + 2   : aplicar aplicar Pseudo Coloreo(LUT) rojo y azul a Imagenes con Intensidad"<<endl<<
          "10)Ctrl + s   : aplicar Filtro de Suavizado"<<endl<<
          "11)Ctrl + m   : aplicar Filtro de Mediana"<<endl<<
          "12)Ctrl + h   : mostrar histograma de la imagen"<<endl<<
          "13)Ctrl + g   : guardar "<<endl;


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

  cout<<"SELECCIONE LA CARPETA A LA QUE QUIERE INGRESAR"<<endl<<endl;
  cout<<" 1) Carpeta 1 " <<endl<<
        " 2) Carpeta 2 " <<endl<<
        " 3) Carpeta 3: Corruptas " <<endl<<
        " 4) Carpeta 4: ij_image_samples"<<endl<<
        " 5) Carpeta 5: Imagenes Modificadas"<<endl<<
        " 6) Salir del programa " <<endl;

  cin>>aux;
  setOpcion(aux);

  while(getOpcion() > 7)
  {
      cout<<endl<<endl;
      cout<< "La opcion de Carpeta no es valida vuelva a ingresar"<<endl;
      cin>>opcion;
      setOpcion(aux);;
  }

  cout<<"Opcion escogida: "<<getOpcion();
}

void Interfaz::mostrarListaImagenes(vector<string> pLista)
{
    cout<<endl;
    cout<<"LAS IMAGENES EN CARPETAS SON:"<<endl;
    //for(unsigned int i=0;i<pLista.size();++i)
   // {

     cout<<"Aaa";
        //cout<<pLista[i]<<endl;
  //  }

}

int Interfaz::getOpcion() const
{
    return opcion;
}

void Interfaz::setOpcion(int newOpcion)
{
    opcion = newOpcion;
}
