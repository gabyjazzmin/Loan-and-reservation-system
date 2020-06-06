//#ifndef RESERVA_H
//#define RESERVA_H
#pragma once
#include "Fecha.h"
#include "Material.h"


class Reserva
{
    public:
        //Defaults
        Reserva();
        Reserva(int idMaterial, int idCliente, Fecha fechaReservacion);

        //Setters
        void setidMaterial(int idM);
        void setidCliente(int idC);
        void setfechaReservacion(Fecha fechaR);
        Fecha setcalculaFechaFinReserva(int dias);

        //Getters
        int getidMaterial();
        int getidCliente();
        Fecha getfechaReservacion();
        Material getcalculaFechaFinReserva();

    protected:

    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;

};

Reserva :: Reserva(){
        this -> idMaterial=0;
        this -> idCliente=0;
}


Reserva :: Reserva(int idMaterial, int idCliente, Fecha fechaReservacion){
  this -> idMaterial = idMaterial;
  this ->idCliente =idCliente;
  this -> fechaReservacion = fechaReservacion;
}

void Reserva :: setidMaterial(int idM){
    idMaterial = idM;
}

void Reserva :: setidCliente(int idC){
    idCliente = idC;
}
void Reserva :: setfechaReservacion(Fecha fechaR){
    fechaReservacion = fechaR;
}

int Reserva :: getidMaterial(){
    return idMaterial;
}

int Reserva :: getidCliente(){
    return idCliente;
}

//Calcula la fecha de reservacion 
Fecha Reserva :: getfechaReservacion(){
    return fechaReservacion;
}


Fecha Reserva :: setcalculaFechaFinReserva(int dias){
  return fechaReservacion + dias;
}


//#endif // RESERVA_H
