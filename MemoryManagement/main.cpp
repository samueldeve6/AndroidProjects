#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int *ptr1;
	int *ptr2;
	int *ptr3;
	int avg;
	
	ptr1 = new int;
	ptr2 = new int;
	ptr3 = new int;
	
	cout<<"Enter first number: ";
	cin>>*ptr1;
	cout<<"Enter the second number: ";
	cin>>*ptr2;
	cout<<"Enter the third number: ";
	cin>>*ptr3;
	avg = (*ptr1+*ptr2+*ptr3)/3;
	cout<<"El promedio es: "<<avg;
	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}
