#include <math.h>
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,potencia;
	cout<<"Digite el valor de x: ";
	cin>>x;
	potencia = pow(x,3);
	cout<<potencia;
	return 0;
}
