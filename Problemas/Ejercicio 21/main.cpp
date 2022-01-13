#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int matriz[5][4];
	int contador=0;
	
	for(int i=0;i<5;i++){
		for (int j=0;j<4;j++){
	        cout<<"Digite un numero ["<<i<<"]["<<j<<"]: "; 
    		cin>>matriz[i][j];
		}	
		
 	}
 	for(int i=0;i<5;i++){
		for (int j=0;j<4;j++){
			cout<<matriz[i][j];
			if(matriz[i][j]==0){
				contador++;
			}
		}
		cout<<"\n";
 	}
 	if(contador == 20){
            	cout<<"La matriz es nula";
	} 
	else {
		cout<<"La matriz no es nula";
	}
   
	return 0;
}


