//#ifndef DISCO_H
//#define DISCO_H
#pragma once
#include "Material.h"



//Clase hija de material
class Disco : public Material
{
    public:
        Disco();
        Disco(int,std::string, int, std::string);

        //seters
        void setduracion(int dura);
        void setgenero(std::string gen);

        //getters
        int getduracion();
        std::string getgenero();

        void muestraDatos();
        int cantidadDiasPrestamo();

        int getidMaterial();
        std::string gettitulo();
     //   virtual ~Disco() {}


     // Implementar 
    protected:

    private:
        int duracion;
        std::string genero;

};

Disco :: Disco(){
  duracion = 0;
  genero="";
}

Disco :: Disco(int _idMaterial, std::string _titulo,int _duracion,std::string _genero){
  idMaterial=_idMaterial;
  titulo=_titulo;
  duracion = _duracion;
  genero = _genero;
  
}

void Disco :: setduracion(int dura){
  duracion = dura;
}

void Disco :: setgenero(string gen){
  genero = gen;
}

int Disco :: getduracion(){
  return duracion;
}

std::string Disco :: getgenero(){
  return genero;
}

void Disco::muestraDatos(){
  std::cout<< duracion << " " <<genero<<'\n';
}

int Disco::cantidadDiasPrestamo(){
  return 2;
}



//#endif // DISCO_H
