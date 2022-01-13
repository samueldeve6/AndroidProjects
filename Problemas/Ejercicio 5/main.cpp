#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

	float matriz[100][33];
	char nombre[100][30] ;
	int filas;
	int dias=5;
	float diasArrProm=0;
	int acumuladorProdMes=0;
	int acumuladorDiasArriProm=0;


	
	cout<<"Digite el numero de obreros: ";
	cin>>filas;

	
	
    for(int i=0;i<filas;i++){
    		cout<<"Digite el nombre del obrero: ";
    		cin>>nombre[i];
    	for (int j=0;j<dias;j++){    	
    		cout<<"Ingrese la producción de cada día ["<<1+j<<"]: ";
    		cin>> matriz[i][j];
		}
	}
	//calcula valor promedio dia, produccion mes.
    for (int i=0;i<filas;i++){
    	
		for (int j=0;j<dias;j++){
			//Produccion del mes
    		matriz[i][dias] += matriz[i][j];
    		//Total produccion mes  
    		acumuladorProdMes += matriz[i][j]; 
    		
		}
		//Promedio dia 
		matriz[i][dias+1] = matriz[i][dias] /dias;
	
	} 
	
	//calcula valor dias Arriba del Promedio.
	
	 for (int i=0;i<filas;i++){
	 	
    	for (int j=0;j<dias;j++){
   
			if (matriz[i][j]>matriz[i][dias+1]){
				
			diasArrProm++;
			}
			
		}
		//Dias arriba del promedio 
		matriz[i][dias+2]=diasArrProm;
		acumuladorDiasArriProm += diasArrProm;
		diasArrProm=0;
		
		
	} 
	cout<<"\n"<<"Nombre"<<"\t"<<"Prod. Mes"<<"\t"<<"Prom Diario"<<"\t"<<"Dias Arriba del prom."<<"\n";
	//mostar matriz
	
	for (int i=0;i<filas;i++){
		
		cout<<nombre[i]<<"\t";
		
    	for (int j=dias;j<dias+3;j++){
    		
   			cout<<matriz[i][j]<<"\t"<<"\t";

		}
		cout<<"\n";
	}
	//Impresion de Totales.
	cout<<"\n"<<"Total"<<"\n"<<filas<<"\t"<<acumuladorProdMes<<"\t"<<"\t"<<"\t"<<"\t"<<acumuladorDiasArriProm; 

	return 0;
}
