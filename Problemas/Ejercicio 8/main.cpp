#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int matriz[5][5];
	int numerosCero=0,numerosArriCero=0,numerosAbajoCero=0;
	
	for (int i=0;i<=4;i++){
		for(int j=0;j<=4;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>matriz[i][j];
		}
		 
	}
	for (int i=0;i<=4;i++){
	for(int j=0;j<=4;j++){
		if (matriz[i][j] > 0) {
		numerosArriCero += 1;
		}
		if (matriz[i][j] < 0) {
		numerosAbajoCero += 1;
		}
		if (matriz[i][j] == 0) {
		numerosCero += 1;
		}
	}
	 
}
	cout<<"Numeros Arriba de cero: "<<numerosArriCero<<"\n"<<"Numeros Abajo de cero: "<<numerosAbajoCero<<"\n"<<"Numeros que son cero: "<<numerosCero<<"\n";
	return 0;
	
}
