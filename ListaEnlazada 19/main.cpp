#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct Node {
   int data;
   Node *next;
} *tail;
Node *head = NULL;
void insert(){
	    int number;
	    cout<<"Ingrese un valor: ";
	    cin>>number; 
	    if(tail!=NULL){
			tail->next = (Node*)malloc(sizeof(Node));
			tail->next->data=number;
			tail=tail->next;
			tail->next=NULL;
		}
		if(head==NULL){
			head = (Node*)malloc(sizeof(Node));
			head->data=number;
			head->next=NULL;
		    tail=head;
		}
	
}
void display() {
	for(Node *ptr=head; ptr != NULL; ptr = ptr->next){
		cout<<"->"<<ptr->data;
	}cout<<endl;}
int main() {
	char op;
	insert();
	cout<<"Desea otro nodo(s/n): "<<endl;
	cin>>op;
	while(op=='s'){
		insert();
		cout<<"Desea otro nodo(s/n): "<<endl;
	    cin>>op;
	    if(op=='n')break;
	}    
   cout<<"La lista enlazada es: ";
   display();
   return 0;}
