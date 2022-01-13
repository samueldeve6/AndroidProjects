#include <iostream>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	string cadena="";
	char caracter1;
	char caracter2;
	cout<<"Ingrese una cadena: ";
	getline(cin,cadena);
	cout<<"Ingrese el caracter que desea reemplazar: ";
	cin>>caracter1;
	cout<<"Ingrese el caracter que lo reemplazara: ";
	cin>>caracter2;
	for(int i=0;i<cadena.size();i++){
		
		if(cadena[i]==caracter1){
			cadena[i]=caracter2;
		}
	}
	cout<<cadena;
	
	getch();
	return 0;
}
