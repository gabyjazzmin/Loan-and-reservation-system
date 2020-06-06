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
    Fecha fdate, defdate;
    Libro libro;
    ofstream finReservar;
    Reserva Raux;
    Material* aux;

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
  int dia2, mes2, anio2;
  int verf = 0;
  char claseMaterial;
  bool fechaOcupada = false;
  bool tieneReservacion = false; 
  int numMaterial=0;
  int idMaux=0;
  Fecha endRes;
  

    
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

        arrDataMaterial[filas] = new Disco(idMaterial, titu, duracion, genero);
      

     }else{
      archMaterial >> idMaterial >> titu >> clave[filas] >> version >> SO;
      if(idMaux==idMaterial){
          break;
        }
        else{
          idMaux=idMaterial;
        }
////// Error guardando version ////////////
      arrDataMaterial[filas] = new Software(idMaterial, titu, version, SO);
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

  //----------------------------------------------------------

  while(opcion == true){
    cout << " " << endl;
    cout << "-|-|-|-|-|-|-|-|-|-|-|-|-|-|"<< endl;
    cout << "Bienvenido al menú de opciones del sistema de reserva" << endl;
    cout << "-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;
		cout << " 1- Mostrar lista de materiales." << endl;
		cout << " 2- Mostrar lista de reservaciones." << endl;
		cout << " 3- Mostrar la reservación de un material." << endl;
		cout << " 4- Mostrar la reservación de una fecha." << endl;
		cout << " 5- Hacer una reservación. " << endl;
		cout << " 6- Finalizar el programa. " << endl;
		cin >> menu;
    
    switch(menu){
//------------------------------------------------------------
      case 1:
      for(int x = 0; x<numMaterial; x++){
        arrDataMaterial[x]->muestraDatos();
      }
      break;
//------------------------------------------------------------      
      case 2:
      for(int x = 0; x<numReservas; x++){
        Fecha aux=arrDataReservacion[x].getfechaReservacion();
        mat = arrDataReservacion[x].getidMaterial();
        cout<<mat<<endl;
      //En caso de que el material esté entre 100 y 200
        if(mat>=100 && mat<200){
          dias = 7;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout << "Reservación del titulo:" << endl;
              cout<<arrDataMaterial[y]->gettitulo()<< endl;
              cout << " Fecha "<< aux << endl;
              cout << " Fecha Final " << tFecha << endl;
              cout << " -----------------------------" << endl;
            }
          }

        }
        //En caso de que el material esté entre 200 y 300
        else if(mat>=200 && mat<300){
          dias = 2;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            //cout<<y<<endl;
            //cout<<arrDataReservacion[x].getidMaterial()<<"   "<<arrDataMaterial[y]->getidMaterial()<<endl;
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout<<"Fecha de reservación " << endl;
              cout <<arrDataMaterial[y]->gettitulo()<< endl;
              cout << " Fecha Inicial"<<" "<< aux <<endl;
              cout << " Fecha Final " <<tFecha << endl;
              cout << " -----------------------------" << endl;
            }
          }

        }

        //En caso de que el material sea mayor a 300
        else if(mat>=300){
          dias = 1;
          Fecha tFecha = arrDataReservacion[x].setcalculaFechaFinReserva(dias);
          for(int y=0; y<numMaterial; y++){
            if(arrDataReservacion[x].getidMaterial()==arrDataMaterial[y]->getidMaterial()){
              cout<<arrDataMaterial[y]->gettitulo()<< " Fecha Inicial"<<" "<< aux << " Fecha Final " <<" "<<tFecha << endl;
              cout << " -----------------------------" << endl;
            }
          }

        }


      }

      break;

//------------------------------------------------------------
      case 3:
      cout << "Introduce el ID del material" << endl;
      cin >> buscaId;
      valorEncontrado = false;

      for(int il = 0; il < 50; il++){
        if(arrDataReservacion[il].getidMaterial() == buscaId){
          arrDataReservacion[il].getfechaReservacion();
          for(iV = 0; iV <20; iV++){
            if(arrDataReservacion[il].getidMaterial() == arrDataMaterial[iV]->getidMaterial()){
              titulo = arrDataMaterial[iV]->gettitulo();
              cout << "El titulo del material es: " << titulo << endl;
								 if (arrDataReservacion[il].getidMaterial() >= 100 && arrDataReservacion[il].getidMaterial() < 200) {

									 
									 fdate= arrDataReservacion[il].setcalculaFechaFinReserva(7);
									 cout << "Deadline: ";
									 fdate.muestraDatos();
									 valorEncontrado = true;
								 }
								 else if(arrDataReservacion[il].getidMaterial() >= 200 && arrDataReservacion[il].getidMaterial() < 300) {


									 fdate = arrDataReservacion[il].setcalculaFechaFinReserva(2);
									 cout << "Deadline: ";
									 fdate.muestraDatos();
									 valorEncontrado = true;
								 }
								 else if (arrDataReservacion[il].getidMaterial() >= 300 && arrDataReservacion[il].getidMaterial() < 400) {


									 fdate = arrDataReservacion[il].setcalculaFechaFinReserva(1);
									 cout << "Deadline: ";
									 fdate.muestraDatos();
									 valorEncontrado = true;
								 }
								 
							 }
							

						}
						
					}
						
				}

				if (valorEncontrado == false) {
					cout << "ID no encontrado " << endl << endl;
				}


    break;
//------------------------------------------------------------
      case 4:
				cout << "-Proceso de fecha-" << endl;
				cout << "Introduce el dia:  ";
				cin >> dia2;
				cout <<endl << "Introduce el mes: ";
				cin >> mes2;
				cout << endl << "Introduce el año: ";
				cin >> anio2;
				cout << endl;
				defdate.setdd(dia2);
				defdate.setmm(mes2);
				defdate.setaa(anio2);
				for(int x=0;x<numReservas; x++){
          Fecha f(arrDataReservacion[x].getfechaReservacion());
          if(arrDataReservacion[x].getfechaReservacion()==defdate){
            
            Raux=arrDataReservacion[x];
            for(int x=0; x<numMaterial; x++){
              if(Raux.getidMaterial()==arrDataMaterial[x]->getidMaterial()){
                aux=arrDataMaterial[x];
              }
            }
            switch(aux->getclave()[0]){
              case 'L':
                dias=7;
                break;
                case 'D':
                dias=2;
                break;
                case 'S':
                dias=1;
                break;
            }
            cout << "Fecha : ";
								Raux.getfechaReservacion().muestraDatos();
								cout << "Titulo: " << aux->gettitulo()<< endl;
								cout << "Id cliente: " << Raux.getidCliente() << endl;
                Raux.getfechaReservacion()+dias;
								cout <<"Deadline: " << endl;
                Raux.getfechaReservacion().muestraDatos();
								cout << endl;
          }
        }
        
        
				/*for (int i = 0; i < numReservas; i++) {
					
					if (arrDataReservacion[i].getidMaterial() > 100 && arrDataReservacion[i].getidMaterial() < 200) {
						dias = 7;
					}
					else if (arrDataReservacion[i].getidMaterial() > 200 && arrDataReservacion[i].getidMaterial() < 300) {
						dias = 2;
					}
					else if (arrDataReservacion[i].getidMaterial() > 300 && arrDataReservacion[i].getidMaterial() < 400) {
						dias = 1;
					}

					endRes = arrDataReservacion[i].getReservacion2() + dias;
					
					 
					if (defdate >= arrDataReservacion[i].getReservacion2() && defdate <= endRes) {
						for (int j = 0; j < 20; j++) {
							
							if (arrDataMaterial[j]->getidMaterial() == arrDataReservacion[i].getidMaterial()) {
								cout << "Fecha inicial: ";
								arrDataReservacion[i].getReservacion2().muestraDatos();
								cout << "Titulo: " << arrDataMaterial[j]->gettitulo() << endl;
								cout << "Id cliente: " << arrDataReservacion[i].getidCliente() << endl;
								cout <<"Deadline: "<< endRes << endl;
								cout << endl;
							

							}
							
						}
						
						
						
					}
				}*/
					


    break;
//------------------------------------------------------------
      case 5:
      {


      fechaOcupada = false;
      tieneReservacion = false;

      	cout << "-Proceso de hacer una reservación-" << endl;
				cout << "Introduce tu ID de cliente : " << endl;
				cin >> cID;
				cout << "Introduce tu ID del material: " << endl;
				cin >> materialId;
        bool conf=0;
        for(int x=0; x<numMaterial; x++){
          if(materialId==arrDataMaterial[x]->getidMaterial()){
            conf=1;
          }
        }
        if(!conf){
          cout << "El Material no existe";
          break;
        }
        
				cout << "-Proceso de fecha del material-" << endl;
				cout << "Día:" << endl;
				cin >> dia;
				defdate.setdd(dia);
				cout << "Mes: " << endl;
				cin >> mes;
				defdate.setmm(mes);
				cout << "Año:" << endl;
				cin >> anio;
				defdate.setaa(anio);

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
					else {};
        }
      
    for (int i = 0; i < 50; i++) { //ENTRA EN UN CICLO POR TODAS LAS RESERVACIONES

					if (arrDataReservacion[i].getidMaterial() == idMaterial) { //SI EL MATERIAL ID DE LA RESERVACION COINCIDE
						tieneReservacion = true;
						if ((arrDataReservacion[i].getReservacion2() >= defdate) && (arrDataReservacion[i].setcalculaFechaFinReserva(dias)<= defdate)) {
							cout << "Ya está reservado. " << endl;
							fechaOcupada = true;

						}
						else {
						}
					}
				}
if (tieneReservacion && !fechaOcupada)
					{
						cout << "Reservado Correctamente"<<endl;
           // cout << cID << materialId << dia << mes << anio << endl;
            cout << "A continuación regresarás al menú" << endl;
						Reserva finalReserve(idMaterial, cID, defdate);
						arrDataReservacion[numReservas] = finalReserve;
						numReservas++;
					}
					else {};	
				
				if (!tieneReservacion)
				{
					cout << "Reservado Correctamente"<<endl;
					Reserva finalReserve(materialId, cID, defdate);
					arrDataReservacion[numReservas] = finalReserve;
					numReservas++;
				}
				
				break;
    }
//------------------------------------------------------------
      case 6:
      opcion = false;
      break;

    }
  }


    return 0;
 }
}
