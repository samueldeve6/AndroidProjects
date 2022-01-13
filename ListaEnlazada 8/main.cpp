#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct node {
	int data;
	struct node * next;
}ElemSN;
ElemSN * CreatLink (int arr [], int n); // Crea una lista vinculada
 void PrintLink (ElemSN * head); // lista enlazada de salida
int main(void){
	int arr[N];
	ElemSN * head;
	for(int i=0;i<N;arr[i]=i,++i);
	head = CreatLink(arr,N);
	PrintLink(head);
} 
ElemSN * CreatLink(int arr[],int n){
	ElemSN * p, * head, *tail;
	head=NULL;
	for(int i=0;i<n;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->data=arr[i];
		p->next=NULL;
		if(!head)	head=tail=p;
		else tail=tail->next=p;
	}
	return head;
}
void PrintLink(ElemSN * head){
	ElemSN * p;
	for(p=head;p;printf("%3d",p->data),p=p->next);
}
