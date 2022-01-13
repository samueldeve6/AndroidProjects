#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int matriz[10][10];
	
	for(int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			if (i<j){
				matriz[i][j] = 0;	
			}
			if (i==j){
				matriz[i][j] = 0;	
			}
			if (i>j){
				matriz[i][j] = 1;
		    }
		
		}	
 	}
 		for(int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			cout<<matriz[i][j];
		}
		cout<<"\n";
 	}
   
	return 0;
}
