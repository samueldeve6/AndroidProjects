#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   Node *next;
} *tail, *head=NULL;
void insert(Node *&);
void display();

int main() {
   insert(head);
   cout<<"La lista enlazada es: ";
   display();
   return 0;}

void insert(Node *&head){
	    int number;
        cout<<"Ingrese -1 para terminar"<<endl;
	while(true){
	    cout<<"Ingrese un valor: ";
	    cin>>number; 
	    if(number==-1)break;
	    if(tail!=NULL){
			tail->next = (Node*)malloc(sizeof(Node));
			tail->next->data=number;
			tail=tail->next;
		}
		if(head==NULL){
			head = (Node*)malloc(sizeof(Node));
			head->data=number;
		    tail=head;
		}
	}
	tail->next=NULL;
}
void display() {
	for(Node *ptr=head;ptr!=NULL;ptr=ptr->next){
		cout<<"->"<<ptr->data;
	}cout<<endl;}
   
