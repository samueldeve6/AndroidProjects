#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generarMatriz();

int main(){
	int c;
	while(c!=-1)
	generarMatriz();
	cout<<"-1 para terminar de ingresar muros";
	cin>>c;
    return 0;
}

void generarMatriz(){
	int x,y;
    char matriz[15][15];
    
    cout<<"Ingresar muro en x,y";
    cin>>x>>y;
    
    for (int fila = 0; fila < 15; fila++){
        for (int columna = 0; columna < 15; columna++){
        	if(matriz[fila][columna]==matriz[x][y]){
        		matriz[x][y]='#';
			}
			else if(matriz[fila][columna]=='#'){
			   matriz[fila][columna]='#';
			}
			else{
				matriz[fila][columna]='|';
			}
            cout << matriz[fila][columna] << " ";
        }
    cout<<endl;
	}
	cout << "*********************************************************" << endl;
    system("pause");
}




