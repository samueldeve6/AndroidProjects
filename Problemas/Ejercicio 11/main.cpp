#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
   int matriz[6][6];  
   int col=0;
	// Almacenando los datos en la matriz
    for(int i=0;i<=5;i++){
    	for(int j=0;j<=5;j++){
    		cout<<"Digite un numero ["<<i<<"]["<<j<<"]: "; 
    		cin>>matriz[i][j];
		}
	}
	cout<<"Columna 1"<<"\t"<<"Columna 2"<<"\t"<<"Columna 3"<<"\t"<<"Columna 4"<<"\t"<<"Columna 5"<<"\t"<<"Columna 6"<<"\t"<<"\n";
	//Mostrando la matriz
	for (int i=0;i<=5;i++){
    	for(int j=0;j<=5;j++){
    		cout<<matriz[j][i];
    		cout<<"\t"<<"\t";
		}
		
		cout<<"\n";
	}
	cout<<"Total"<<"\t"<<"\t"<<"Total"<<"\t"<<"\t"<<"Total"<<"\t"<<"\t"<<"Total"<<"\t"<<"\t"<<"Total"<<"\t"<<"\t"<<"Total"<<"\t"<<"\t"<<"\n";
		//calcular valor columna
		for (int i=0;i<=5;i++){
    	for(int j=0;j<=5;j++){
    	col+=matriz[i][j];    	
    	
		}
		cout<<col;
		col=0;
		cout<<"\t"<<"\t";
	}
//getch();
	return 0;
}
