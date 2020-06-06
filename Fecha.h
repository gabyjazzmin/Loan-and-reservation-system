//#ifndef FECHA_H
//#define FECHA_H

using namespace std;

class Fecha

{

//Defaults
    public:
        Fecha();
        Fecha (int, int, int);
        void muestraDatos();
//seters 
        void setdd(int dia);
        void setmm(int mes);
        void setaa(int anio);
        void setFecha(int fecha);
//getters
        int getdd();
        int getmm();
        int getaa();
        int getFecha();
// operadores para realizar consultas
        friend bool operator > (Fecha, Fecha);
        friend bool operator>=(Fecha, Fecha);
        friend bool operator<(Fecha, Fecha);
        friend bool operator<=(Fecha, Fecha);
        friend bool operator==(Fecha, Fecha);
        friend std::istream& operator>>(std::istream&, Fecha&);
        friend std::ostream& operator<<(std::ostream&, Fecha&);
        Fecha operator+(int dias);

    protected:

    private:
        int dia;
        int mes;
        int anio;

};

Fecha :: Fecha(){
  dia = 1;
  mes = 1;
  anio = 1;
}

Fecha :: Fecha (int dia, int mes, int anio){
  this -> dia = dia;
  this -> mes = mes;
  this -> anio = anio;

}

void Fecha :: setdd(int dia){
   this -> dia = dia;
}

void Fecha :: setmm(int mes){
  this -> mes = mes;
}

void Fecha :: setaa(int anio){
  this -> anio = anio;
}


int Fecha :: getdd(){
    return dia;
}

int Fecha :: getmm(){
    return mes;
}

int Fecha :: getaa(){
    return anio;
}





bool operator>=(Fecha dia, Fecha fDay){
  if(dia.getaa() >= fDay.getaa()){
    if(dia.getmm() >= fDay.getmm()){
      if(dia.getdd() >= fDay.getdd()){
        return true;
      }
    }
  }
  return false;
  
}

bool operator<=(Fecha dia, Fecha fDay){
  if(dia.getaa() >= fDay.getaa()){
    if(dia.getmm() >= fDay.getmm()){
      if(dia.getdd() >= fDay.getdd()){
        return true;
      }
    }
  }
  return false;
  
}

Fecha Fecha ::operator+(int dias){

  if( (mes <13) || (mes>0) ){
    dia += dias;
    switch(mes){
//Casos para cada mes
      case 1:
      if(dia <= 31){
        return *this;
      } else{
        dia -= 31;
        mes += 1;

        return *this;
      }
      break;

      case 2:
        if(anio % 4 == 0){
          if(dia<=29){
            return *this;
          }
        }

        if(dia <=28){
          return *this;
        } 
        else {
          dia -=28;
          mes +=1;

          return *this;
        }

      break;
case 3:
			if (dia <= 31) {
				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				return *this;
			}
			break;

		case 4:
			if (dia <= 30) {


				return *this;
			}
			else {

				dia -= 30;
				mes += 1;
				
				return *this;
			}

			break;
		case 5:
			if (dia <= 31) {

				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				return *this;
			}
			break;
		case 6:
			if (dia <= 30) {

				
				return *this;
			}
			else {

				dia -= 30;
				mes += 1;
				
				return *this;
			}
			break;
		case 7:
			if (dia <= 31) {


				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				return *this;
			}
			break;
		case 8:
			if (dia <= 31) {


				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				return *this;
			}
			break;
		case 9:
			if (dia <= 30) {


				return *this;
			}
			else {

				dia -= 30;
				mes += 1;
				;
				return *this;
			}
			break;
		case 10:
			if (dia <= 31) {


				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				return *this;
			}
			break;
		case 11:
			if (dia <= 30) {


				return *this;
			}
			else {

				dia -= 30;
				mes += 1;
				
				return *this;
			}
			break;
		case 12:
			if (dia <= 31) {


				return *this;
			}
			else {

				dia -= 31;
				mes += 1;
				
				
			}
			if (mes > 12) {

				anio += 1;
				mes = 1;

				return *this;
			}
			break;
		}
		return *this;
	}
  return *this;
}
  



bool operator>(Fecha dia, Fecha fDay){

  if(dia.getaa() > fDay.getaa()){
    if(dia.getmm() > fDay.getmm()){
      if(dia.getdd() > fDay.getdd()){
        return true;
      }
    }
  }
  return false;
}

bool operator<(Fecha dia, Fecha fDay){
  if(dia.getaa() < dia.getaa()){
    if(dia.getmm() < dia.getmm()){
      if(dia.getdd() < dia.getdd()){
        return true;
      }
    }
  }
  return false;
}

bool operator==(Fecha dia, Fecha fDay){
  if(dia.getaa() < dia.getaa()){
    if(dia.getmm() < dia.getmm()){
      if(dia.getdd() < dia.getdd()){
        return true;
      }
    }
  }
  return false;
}

std::istream& operator >> (std::istream& in, Fecha &f){

	int tempDia;
	int tempMes;
	int tempAnio;
	
	std::cout << "Introduce Month: " << std::endl;
	in >> tempMes;
	f.setmm(tempMes);
	std::cout << "Introduce Year: " << std::endl;
	in >> tempAnio;
	f.setaa(tempAnio);

	if ((f.anio % 4 != 0) && (f.mes == 2)) {
		std::cout << "Introduce Day " << std::endl;

		in >> tempDia;
		f.setdd(tempDia);
		if (f.dia <= 28) {

			return in;

		}
		else {
			std::cout << "Try Agin with a valid date " << std::endl;
		}


	}

	if ((f.anio%4==0)&&(f.mes==2)) {
		std::cout << "Introduce Day " << std::endl;
		in >> tempDia;
		f.setdd(tempDia);
		if (f.dia <=29) {

			return in;

		}
		else {
			std::cout << "Try Agin with a valid date " << std::endl;
		}


	}
	
	if(f.mes==1||f.mes==3||f.mes==5||f.mes==7||f.mes==8||f.mes==10||f.mes==12){
		
		std::cout << "Introduce Day:" << std::endl;
		in >> tempDia;
		f.setdd(tempDia);
		
		if(f.dia<31)
		{
			return in;
			
		}
		else {
			std::cout << "Try again with a valid Date" << std::endl;
			
		}
	}
	if (f.mes==4|| f.mes == 6|| f.mes == 9|| f.mes == 11){

		std::cout << "Introduce Day:" << std::endl;
		in >> tempDia;
		f.setdd(tempDia);

		if (f.dia < 30)
		{
			return in;

		}
		else {

			std::cout << "Try again with a valid Date" << std::endl;

		}

	}
}

std::ostream& operator << (std::ostream& out, Fecha& dias){
  out << dias.dia;
  out << "/" << dias.mes << "/" << dias.anio << endl;
  return out;
}

void Fecha :: muestraDatos(){

  std::cout << dia << "/" << mes << "/" << anio << std::endl;

}

//#endif // FECHA_H
