#pragma once
#include <iostream>
#include <string.h>

using namespace std;
/*
#ifndef MATERIAL_H
#define MATERIAL_H
*/

class Material
{
    public:
        Material();

        //setters
        void setidMaterial(int idM);
        void settitulo(std::string titu);
        //////////
        void setclave(string clave);


        //getters
        int getidMaterial();
        std::string gettitulo();
        std::string getclave();

        virtual void muestraDatos() = 0;
        virtual int cantidadDiasPrestamo() = 0;

    protected:
        int idMaterial;
        std::string titulo;
        std::string clave;

};

Material :: Material(){
  idMaterial = 0;
  titulo = "";
  clave = "";

}

void Material :: setidMaterial(int idM){
  idMaterial = idM;
}

void Material :: settitulo(std::string titu){
  titulo = titu;
}

void Material :: setclave(std::string clave){
  this->clave = clave;
}

int Material :: getidMaterial(){
  return idMaterial;
}

std::string Material :: gettitulo(){
  return titulo;
}

string Material :: getclave(){
  return clave;
}
//#endif // MATERIAL_H
