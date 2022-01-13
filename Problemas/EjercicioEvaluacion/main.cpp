#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char trabajadores;
	char salida = '*';
	int horasExtras,horasNormales;
	int obreros;
	int sueldoHorasNormales;
	int sueldoHorasExtra;
	int sueldoHoEx;
	int salario;
	int horasMenoresQueDiez;
	
	cout<<"digite el numero de trabajadores: ";
	cin>>obreros;
	

	
	for(int i=0;i<obreros;i++){
		
				cout<<"Digite el nombre del trabajador: ";
	cin>>trabajadores;
	
	if(trabajadores == salida ){
		cout<<"Fin del programa";
    	break;
	}
	

	for(int j=0;j<1;j++){
	cout<<"Digite el numero de horas normales trabajadas: ";
	cin>>horasNormales;
	cout<<"Digite el numero de horas extra trabajadas: ";
	cin>>horasExtras;
	}
	
    sueldoHorasNormales = horasNormales*6000;
    
    if(horasExtras>10){
    	sueldoHorasExtra =  (horasExtras-10)*10500;
    	horasMenoresQueDiez = 10*8000;
        salario = sueldoHorasExtra+horasMenoresQueDiez;	
    	
	}  
	else{	
	    	sueldoHorasExtra = horasExtras*8000;
	    	salario=sueldoHorasExtra;
    }

     salario = salario+sueldoHorasNormales;
     cout<<"Su salario es: "<<salario<<"\n";
}

	return 0;
}
