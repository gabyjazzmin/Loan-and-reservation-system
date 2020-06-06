#include <iostream>
#include <string.h>
#include <fstream>
//#include "Material.h" //Este no se incluye al final
#include "Reserva.h"
#include "Libro.h"
#include "Software.h"
//#include "Fecha.h"
#include "Disco.h"


using namespace std;

int main()
{
  //Arreglos 
    //Arreglo de material
    Material* arrDataMaterial[30];

    //Arreglo de reservación
    Reserva arrDataReservacion[50]; 
    int filas=0, columnas=0;

    //Libro arrLibros[30];
    //Disco arrDisco[30];

  //Datos de Libro
    ifstream archLibro;
    int idMaterial;
    string titu;
    int numPag;
    string autor;
    char clave[20];
    int mat;
    //Fecha endReserv;

  //Datos de Disco
    ifstream archDisco;
    int duracion;
    string genero;

  //Datos de Reservacion 
    ifstream archReserva;
    int dia, mes, anio, idM, cID;
    Reserva reservar;
    Fecha fdate, defDate;
    Libro libro;
    ofstream finReservar;

  //Software variables 
    int version;
    string SO;

  //Operadores de ayuda
  int buscaId;
  int materialId;

  //Valores iniciales

  int menu;
  bool opcion = true;
  int dias = 0;
  bool valorEncontrado = false;
  int iV = 0;
  string titulo;
  int dia1, mes2, anio2;
  int verf = 0;
  char claseMaterial;
  bool fechaOcupada = false;
  bool tieneReservacion = false; //Cambiar nombre
  int numMaterial=0;
  int idMaux=0;
  

    
    ifstream archMaterial;
    archMaterial.open("Material.txt");
    int cont = 0;
    while(!archMaterial.eof()){
      /*
      int idM;
      string titu;
      string clave;
      int data1;
      int data2;
      */
    for(filas = 0; filas <30; filas++){

      if(filas <10){

      archMaterial >> idMaterial >> titu >> clave[filas] >> numPag >> autor;

      arrDataMaterial[filas] = new Libro(idMaterial,titu, numPag, autor);

      } else if((filas>=10)&&(filas <15)){

        archMaterial >> idMaterial >> titu >> clave[filas] >> duracion >> genero;
        
///////////////////Error con duracion///////////

        arrDataMaterial[filas] = new Disco(idMaterial, titulo, duracion, genero);
      

     }else{
      archMaterial >> idMaterial >> titu >> clave[filas] >> version >> SO;
      if(idMaux==idMaterial){
          break;
        }
        else{
          idMaux=idMaterial;
        }
////// Error guardando version ////////////
      arrDataMaterial[filas] = new Software(idMaterial, titulo, version, SO);
    }
    numMaterial++;
  } archMaterial.close();
//Guardando datos de Reserva txt

  
  int numReservas = 0;
  int reservasIniciales = 0;
  archReserva.open("Reserva.txt");
  while (!archReserva.eof()){
    {
      archReserva >> dia >> mes >> anio >> idM >> cID;
      
      arrDataReservacion[numReservas] = Reserva(idM, cID,Fecha(dia, mes, anio));
      numReservas++;
      reservasIniciales++;
    }
  } archReserva.close();
  while(opcion == true){
    cout << "Bienvenido al menú de opciones del sistema de reserva" << endl;
    cout << "-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;
		cout << " 1- Display the list of Materials " << endl;
		cout << " 2- Display the list of Reservation " << endl;
		cout << " 3- Display the reservation of a Material " << endl;
		cout << " 4- Display the reservation of a Date" << endl;
		cout << " 5- Do a reservation " << endl;
		cout << " 6- End program " << endl;
		cin >> menu;
    
    switch(menu){
      case 1:
      for(int x = 0; x<numMaterial; x++){
        arrDataMaterial[x]->muestraDatos();
      }
      case 2:
      for(int x = 0; x<numReservas; x++){
        Fecha aux=arrDataReservacion[x].getfechaReservacion();
        mat = arrDataReservacion[x].getidMaterial();
        cout<<mat<<endl;
        if(mat>=100 && mat<200){
          dias = 7;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout<<arrDataMaterial[y]->gettitulo()<<" "<<aux<<" "<<tFecha;
            }
          }

        }
        if(mat>=200 && mat<300){
          dias = 2;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            //cout<<y<<endl;
            //cout<<arrDataReservacion[x].getidMaterial()<<"   "<<arrDataMaterial[y]->getidMaterial()<<endl;
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout<<arrDataMaterial[y]->gettitulo()<<" "<<aux<<" "<<tFecha;
            }
          }

        }
        if(mat>=300){
          dias = 1;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout<<arrDataMaterial[y]->gettitulo()<<" "<<aux<<" "<<tFecha;
            }
          }

        }


      }

      case 3:

      case 4:

      case 5:
/*
{
      fechaOcupada = false;
      tieneReservacion = false;

      	cout << "Let's do a reservation!" << endl;
				cout << "Introduce your client ID: " << endl;
				cin >> cID;
				cout << "Introduce the Material ID:" << endl;
				cin >> idMaterial;
				cout << "Introduce the Date of Reservation " << endl;
				cout << "Day:" << endl;
				cin >> dia;
				defDate.setdd(dia);
				cout << "Month: " << endl;
				cin >> mes;
				defDate.setmm(mes);
				cout << "Year:" << endl;
				cin >> anio;
				defDate.setaa(anio);

for (int l = 0; l < 20; l++) { //ENTRA EN UN CICLO POR TODOS LOS MATERIALES PARA CONSEGUIR EL NUMERO DE DIAS

					if (arrDataMaterial[l]->getidMaterial() == materialId) {

						if (materialId > 100 && materialId < 200) {
							dias = 10;
						}
						else if (materialId > 200 && materialId < 300) {
							dias = 3;
						}
						else if (materialId > 300 && materialId < 400) {
							dias = 1;
						}
					}
					else {}
          
}
*/
      case 6:
      opcion = false;
      break;

    }
  }

  
      /*
      if(clave == "L"){
        //Poner un nuevo contador para cada caso, L, D, S
        arrDataMaterial[cont] = &arrLibros[cont];
        arrLibros[cont].setidMaterial(idM);


      } else if(clave == "D"){
        arrDataMaterial[cont] = &arrDisco[cont];
      } else if(clave == )
    }
    */
/*
    arrLibros[0].setidMaterial(1);
    arrLibros[0].settitulo("hola");
    arrLibros[0].setclave("a");
    arrLibros[0].setAutor("Pedro");
    arrLibros[0].setnumPag(20);

    arrDataMaterial[0] = &arrLibros[0];
    arrDataMaterial[0]->muestraDatos();
*/
    // ifstream archMaterial;
    // archMaterial.open("Material.txt");
    // int cont=0;
    // while(!archMaterial.eof()){
    //     int idM;
    //     string titu;
    //     string clave; //Aqui es L, D ó S 
    //     int data1;
    //     string data2;

    //     archMaterial >> idMaterial >> titu >> clave >> data1 >> data2;

    //     arrDataMaterial[cont].setidMaterial(idM);
    //     arrDataMaterial[cont].settitulo(titu);
      
    //     if(data1 == 'L'){

    //       arrDataMaterial[cont].setclave(clave);
    //     } else if(data1 == 'D'){
    //       arrDataMaterial[cont].setclave(clave);
    //     }else if 
      
    // }

    // Reserva arrDataReserva[60];

    // Libro librito;
    return 0;
}
}
