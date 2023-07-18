#include "estadisticos.h"

Estadisticos::Estadisticos()
{

}
//Histogramas

map<float,int> Estadisticos::Hist_intensidad()
{
    map<float,int>histo_intensidad;

    for(auto &x:Vec)//para cada pixel dentro de Vec
    {
        histo_intensidad[x.intensidadRGB()*2.29f]++;//asigno al histograma clave: pixel normalizado y para cada
                                                 //clave con el mismo valor, sumo uno
                                                 //se multiplica por 2.29 para que quede en 255 (intensidad es 111 el max)
    }

    return histo_intensidad;
}

map<float,int> Estadisticos::Hist_R()
{
        map<float,int>histo_R;

        for(auto &x:Vec)
        {
            histo_R[x.getR()*255.0f]++;
        }

        return histo_R;
}

map<float,int> Estadisticos::Hist_G()
{
    map<float,int>histo_G;

    for(auto &x:Vec)
    {
        histo_G[x.getG()*255.0f]++;
    }

    return histo_G;
}

map<float,int> Estadisticos::Hist_B()
{
    map<float,int>histo_B;

    for(auto &x:Vec)
    {
        histo_B[x.getB()*255.0f]++;
    }

    return histo_B;
}


//promedios

float Estadisticos::Promedio_Intensidad()
{
    float promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].intensidadRGB();
    }
    return promedio/Vec.size();
}

float Estadisticos::Promedio_R()
{
    float promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].getR();
    }
    return promedio/Vec.size();
}

float Estadisticos::Promedio_G()
{
    float promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].getG();
    }
    return promedio/Vec.size();
}


float Estadisticos::Promedio_B()
{
    float promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].getB();
    }
    return promedio/Vec.size();
}
//Medidas de tendencia central

Pixel Estadisticos::Moda()
{
    unsigned n=Vec.size();
    int max_count=1, count=1;
    Pixel res=Vec[0];

    for(unsigned i=1;i<n;++i)
    {
        if(Vec[i].intensidadRGB()==Vec[i-1].intensidadRGB())
            count++;
        else
        {
            if(count>max_count)
            {
                max_count=count;
                res=Vec[i-1];
            }
        }
        count=1;
    }

    if(count>max_count) //por si el ultimo elemento es el mas frecuente
    {
        res=Vec[n-1];
    }

    cout<<"  Max_count:"<<max_count;

    return res;
}


Pixel Estadisticos::Mediana()
{

    int n=Vec.size();
    if(n % 2 == 0)
        return (Vec[n/2 - 1] + Vec[n/2])/2;

    else return Vec[n/2];

}

float Estadisticos::MedianaR()
{
    vector<float> aux;

    for(unsigned int i=0;i<Vec.size();++i)
    {
        aux.push_back(Vec[i].getR());
    }

    sort(aux.begin(),aux.end());

    int n=aux.size();
    if(n % 2 == 0)
        return (aux[n/2 - 1] + aux[n/2])/2;

    else return aux[n/2];
}



float Estadisticos::MedianaG()
{
    vector<float> aux;

    for(unsigned int i=0;i<Vec.size();++i)
    {
        aux.push_back(Vec[i].getG());
    }

    sort(aux.begin(),aux.end());

    int n=aux.size();
    if(n % 2 == 0)
        return (aux[n/2 - 1] + aux[n/2])/2;

    else return aux[n/2];
}

float Estadisticos::MedianaB()
{
    vector<float> aux;

    for(unsigned int i=0;i<Vec.size();++i)
    {
        aux.push_back(Vec[i].getB());
        cout<<aux[i];
    }

    sort(aux.begin(),aux.end());

    int n=aux.size();
    if(n % 2 == 0)
        return (aux[(n/2) - 1] + aux[n/2])/2;

    else return aux[n/2];
}

vector<float> Estadisticos::DesvioSTD()
{
float DesvioR, AcumR=0.0;
float DesvioG,AcumG=0.0;
float DesvioB,AcumB=0.0;
float DesvioIntensidad,Acumint=0.0;
vector<float> aux;

    for(unsigned int i=0;i<Vec.size();++i)
    {
        AcumR+=pow(Vec[i].getR()-this->Promedio_R(),2.0);
        AcumG+=pow(Vec[i].getG()-this->Promedio_G(),2.0);
        AcumB+=pow(Vec[i].getB()-this->Promedio_B(),2.0);
        Acumint+=pow(Vec[i].intensidadRGB()-this->Promedio_Intensidad(),2.0);
    }
    DesvioR=sqrt(AcumR/Vec.size());
    DesvioG=sqrt(AcumG/Vec.size());
    DesvioB=sqrt(AcumB/Vec.size());
    DesvioIntensidad=(Acumint/Vec.size());

    aux.push_back(DesvioR);
    aux.push_back(DesvioG);
    aux.push_back(DesvioB);
    aux.push_back(DesvioIntensidad);

    return aux;
}

//Maximos y Minimos

float Estadisticos::Max_Intensidad()
{
    return Vec.rbegin()->intensidadRGB();
}

float Estadisticos::Min_Intensidad()
{
    return Vec.begin()->intensidadRGB();
}



float Estadisticos::Max_R()
{
    float R=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(R<Vec[i].getR())
        {
            R=Vec[i].getR();
        }
    }

    return R;
}

float Estadisticos::Max_G()
{

    float G=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(G<Vec[i].getG())
        {
            G=Vec[i].getG();
        }
    }

    return G;
}

float Estadisticos::Max_B()
{

    float B=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(B<Vec[i].getB())
        {
            B=Vec[i].getB();
        }
    }

    return B;
}




float Estadisticos::Min_R()
{
    float min=Vec[0].getR();
    for(unsigned i=0;i<Vec.size();++i)
    {
        if(Vec[i].getR()<min)
            min=Vec[i].getR();

    }
    return min;
}

float Estadisticos::Min_G()
{
    float min=Vec[0].getG();
    for(unsigned i=0;i<Vec.size();++i)
    {
        if(Vec[i].getG()<min)
            min=Vec[i].getG();

    }
    return min;
}

float Estadisticos::Min_B()
{
    float min=Vec[0].getB();
    for(unsigned i=0;i<Vec.size();++i)
    {
        if(Vec[i].getB()<min)
            min=Vec[i].getB();

    }
    return min;
}




//Metodos miscelaneos

void Estadisticos::Ordenar()
{
    for(int i=0;i<Datos.getAlto();++i)
    {
        for(int j=0;j<Datos.getAncho();++j)
        {
            Vec.push_back(Datos.getPixel(i,j));
        }
    }

    sort(Vec.begin(),Vec.end());
}

void Estadisticos::setVec(const vector<Pixel> &newVec)
{
    Vec = newVec;
    sort(Vec.begin(),Vec.end());

}

const vector<Pixel> &Estadisticos::getVec() const
{
    return Vec;
}


void Estadisticos::setDatos(const Imagen &newDatos)
{
    Datos = newDatos;
    this->Ordenar();
}
