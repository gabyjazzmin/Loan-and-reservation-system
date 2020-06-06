#include <iostream>
#include <string>
#include "Material.h"

using namespace std;

//Clase hija de Material
class Software : public Material
{
    public:
        //Defaults
        Software();
        Software(int,std::string, int, std::string);

        //setters
        void setversion(int version);
        void setSO(string SO);

        //getters
        int getversion();
        string getSO();

        //Los que se deben de incluir
        void muestraDatos();
        int cantidadDiasPrestamo();

        int getidMaterial();
        std::string gettitulo();

    protected:

    private:
        int version;
        string SO;
};

Software :: Software(){
  version = 0;
  SO="";
}

Software :: Software(int _idMaterial, std::string _titulo,int _version, std::string _SO){
  idMaterial = _idMaterial;
  titulo = _titulo;
  version = _version;
  SO = _SO;
}

void Software :: setversion(int version) {
  this->version=version;
}

void Software :: setSO(string SO){
  this ->SO=SO;
}

int Software :: getversion(){
  return version;
}

string Software :: getSO(){
  return SO;
}

void Software :: muestraDatos() {
  std::cout<< version << " " << SO <<'\n';
}

int Software ::cantidadDiasPrestamo(){
  return 1;
}
