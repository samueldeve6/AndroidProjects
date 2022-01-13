#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	 int numeros[] = {1,2,3,4,5};
     int inf,sup,mitad,dato;
     char band = 'F';
     
     dato = 3;
     
     //Algoritmo de Busqueda Binaria
     inf=0;
     sup=5;
     while(inf <= sup){
     	mitad = (inf+sup)/2;
     	
     	if(numeros[mitad] == dato){
     		band = 'V';
     		break;
		 }
		if(numeros[mitad] > dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(numeros[mitad] < dato){
			inf=mitad;
			mitad= (inf+sup)/2;
		}
	 }
	if(band=='V'){
		cout<<"El numero encontrado es: "<<numeros[mitad]<<" en la posicion: "<<mitad<<endl;
	}
	else{
		cout<<"El numero no existe en la lista";
	}

	return 0;
}
