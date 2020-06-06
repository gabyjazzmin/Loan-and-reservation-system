//#ifndef LIBRO_H
//#define LIBRO_H

#include "Material.h"
#include <string.h>

//Clase hija de material
class Libro : public Material
{
    public:
        //Defaults
        Libro();
        Libro(int, std::string, int, std::string);

        //Setters
        void setnumPag(int numP);
        void setAutor(std::string aut);

        //Getters
        int getnumPag();
        std::string getAutor();
        
        //Obligatorios
        void muestraDatos();
        int cantidadDiasPrestamo();

        int getidMaterial();
        std::string gettitulo();

        

    protected:

    private:
    int numPag;
    std::string Autor;
};

Libro::Libro(){
  idMaterial=0;
  titulo="";
  numPag=0;
  Autor="";
}


Libro::Libro (int _idMaterial, std::string _titulo, int _numPag, std::string _Autor){
  idMaterial=_idMaterial;
  titulo=_titulo;
  numPag=_numPag;
  Autor=_Autor;
}

void Libro :: setnumPag(int numP){
  numPag = numP;
}

void Libro :: setAutor(std::string aut){
  Autor = aut;
}

int Libro :: getnumPag(){
  return numPag;
}

std::string Libro :: getAutor(){
  return Autor;
}

void Libro::muestraDatos(){
  std::cout<<"Información del libro"<< endl;
  std::cout<<idMaterial<<" "<<titulo<<" "<<numPag<<" "<<Autor<<'\n';
  std::cout << " " << endl;
}

int Libro::cantidadDiasPrestamo(){
  return 7;
}

//#endif // LIBRO_H
