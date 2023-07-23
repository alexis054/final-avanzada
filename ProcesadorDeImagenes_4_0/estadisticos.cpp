#include "estadisticos.h"

Estadisticos::Estadisticos()
{

}
//Histogramas

map<int,int> Estadisticos::Hist_intensidad()
{
    map<int,int>histo_intensidad;

   for( int i = 0; i < Datos.getM()-1 ; i++)
    {
        histo_intensidad.insert(make_pair(i,0));
    }
   for(auto &x: Vec )
    {
        histo_intensidad[x.intensidad()]=histo_intensidad[x.intensidad()]+1;
    }


   auto max_it = std::max_element(histo_intensidad.begin(), histo_intensidad.end(),
           [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
               return p1.second < p2.second;
    });

   MF_intensidad.first=max_it->first;
   MF_intensidad.second=max_it->second;

    return histo_intensidad;
}

map<int,int> Estadisticos::Hist_R()
{
        map<int,int>histo_R;

        for( int i = 0; i < Datos.getM()-1 ; i++)
         {
             histo_R.insert(make_pair(i,0));
         }
        for(unsigned int i=0;i<Vec.size();++i)
         {
             histo_R[(int)(Vec[i].getR())]=histo_R[Vec[i].getR()]+1;
         }
        auto max_it = std::max_element(histo_R.begin(), histo_R.end(),
                [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                    return p1.second < p2.second;
                });

        MF_R.first=max_it->first;
        MF_R.second=max_it->second;

        //sort(histo_R.begin(),histo_R.end());

        return histo_R;
}

map<int,int> Estadisticos::Hist_G()
{
    map<int,int>histo_G;

    for(auto &x:Vec)
    {
        histo_G[x.getG()*255.0f]++;
    }

    return histo_G;
}

map<int,int> Estadisticos::Hist_B()
{
    map<int,int>histo_B;

    for(auto &x:Vec)
    {
        histo_B[x.getB()*255.0f]++;
    }

    return histo_B;
}


//promedios

int Estadisticos::Promedio_Intensidad()
{
    int promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].intensidad();
    }
    return promedio/Vec.size();
}

int Estadisticos::Promedio_R()
{
    int promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].getR();
    }
    return promedio/Vec.size();
}

int Estadisticos::Promedio_G()
{
    int promedio=0;

    for(unsigned int i=0; i<Vec.size();++i)
    {
        promedio+=Vec[i].getG();
    }
    return promedio/Vec.size();
}


int Estadisticos::Promedio_B()
{
    int promedio=0;

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
        if(Vec[i].intensidad()==Vec[i-1].intensidad())
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

int Estadisticos::MedianaR()
{
    vector<int> aux;

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



int Estadisticos::MedianaG()
{
    vector<int> aux;

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

int Estadisticos::MedianaB()
{
    vector<int> aux;

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
        Acumint+=pow(Vec[i].intensidad()-this->Promedio_Intensidad(),2.0);
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

int Estadisticos::Max_Intensidad()
{
    return Vec.rbegin()->intensidad();
}

int Estadisticos::Min_Intensidad()
{
    return Vec.begin()->intensidad();
}



int Estadisticos::Max_R()
{
    int R=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(R<Vec[i].getR())
        {
            R=Vec[i].getR();
        }
    }

    return R;
}

int Estadisticos::Max_G()
{

    int G=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(G<Vec[i].getG())
        {
            G=Vec[i].getG();
        }
    }

    return G;
}

int Estadisticos::Max_B()
{

    int B=0;

    for(unsigned int i=0;i<Vec.size(); ++i)
    {
        if(B<Vec[i].getB())
        {
            B=Vec[i].getB();
        }
    }

    return B;
}




int Estadisticos::Min_R()
{
    int min=Vec[0].getR();
    for(unsigned i=0;i<Vec.size();++i)
    {
        if(Vec[i].getR()<min)
            min=Vec[i].getR();

    }
    //cout<<min;
    return min;
}

int Estadisticos::Min_G()
{
    int min=Vec[0].getG();
    for(unsigned i=0;i<Vec.size();++i)
    {
        if(Vec[i].getG()<min)
            min=Vec[i].getG();

    }
    return min;
}

int Estadisticos::Min_B()
{
    int min=Vec[0].getB();
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

const pair<unsigned int, unsigned int> &Estadisticos::getMF_R() const
{
    return MF_R;
}

const pair<unsigned int, unsigned int> &Estadisticos::getMF_intensidad() const
{
    return MF_intensidad;
}


void Estadisticos::setDatos(const Imagen &newDatos)
{
    Datos = newDatos;
    Ordenar();

}
