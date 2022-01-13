#include<iostream>
using namespace std;
#define M 4
#define N 4
#define MaxSize 100
int mg[M + 2][N + 2] = {
{1,1,1,1,1,1},
{1,0,0,0,1,1},
{1,0,1,0,0,1},
{1,0,0,0,1,1},
{1,1,0,0,0,1},
{1,1,1,1,1,1}}
;
struct {
	int i, j;
	int di;
} St[MaxSize], Path[MaxSize];
int top = -1;
int count = 1;
int minlen = MaxSize;
void dispapath() {
	int k;
	printf("%5d: ", count++);
	for(k = 0; k <= top; k++)
		printf("(%d, %d)", St[k].i, St[k].j);
	cout << endl;
}
void dispminpath() {
	
}
void mgpath(int xi, int yi, int xe, int ye) {
	int i, j, i1, j1, di; 
	bool find;			  
	top++; 
	St[top].i = xi;
	St[top].j = yi;
	St[top].di = -1; mg[xi][yi] = -1;
	while(top > -1) {
		i = St[top].i; j = St[top].j;
		di = St[top].di;
		if(i == xe && j == ye) {
			dispapath();
			mg[i][j] = 0;
			top--;
			i = St[top].i; j = St[top].j;
			di = St[top].di;
		}
		find = false;
		while(di < 4 && !find) {
			di++;
			switch(di) {
				case 0: i1 = i - 1; j1 = j; break;
				case 1: i1 = i; j1 = j + 1; break;
				case 2: i1 = i + 1; j1 = j; break;
				case 3: i1 = i; j1 = j - 1; break;
			}
			if(mg[i1][j1] == 0) find = true;
		}
		if(find) {
			St[top].di = di;
			top++; St[top].i = i1; St[top].j = j1;
			St[top].di = -1;
			mg[i1][j1] = -1;
		} else {
			mg[i][j] = 0;
			top--;
		}
	}
	dispminpath();
}
int main() {
	cout << "El camino del laberinto es el siguiente:" << endl;
	mgpath(1, 1, M, N);
}
