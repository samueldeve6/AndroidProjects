#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   Node *next;
} *ultimo;
Node *head = NULL;
void insert(){
	    Node *new_node = (Node*) malloc(sizeof(Node));
	    cout<<"Digite valor: ";
	    cin>>new_node->data; 
		if(head==NULL){
			head=new_node;
			head->next=NULL;
			ultimo=new_node;
			
		}else{
			ultimo->next=new_node;
			new_node->next=NULL;
			ultimo=new_node;
		}
}
void display() {
   Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
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
   cout<<"The linked list is: ";
   display();
   
   return 0;
}


