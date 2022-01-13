#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int totNum;
	int num=0,suma;
	float promedio;
	int mayor=0;
	int menor=9999;
	
	cout<<"digite el total de numeros a ingresar: ";
    cin>>totNum;	

    for(int i=0;i<totNum;i++)
    {
    	cout<<"Digite un valor numerico: ";
	    cin>>num;
	    suma = suma + num;
	    promedio = suma/totNum;
	    if(num>mayor){
	    	mayor=num;
		}
		if(num<menor){
			menor=num;
			
		}
	}
 /*   for(int i=0;i<totNum;i++)
    {
         
	}*/	
	cout<<"El total es: "<<suma<<"\n"<<"El promedio es: "<<promedio<<"\n";
	cout<<"El numero menor es:"<<menor<<"\n"<<"El numero mayor es: "<<mayor;
	return 0;
}
