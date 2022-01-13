#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node *next;
}*head;
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertPosition(int value, int pos);
void removeBeginning();
void removeEnd();
void removePosition(int pos);
void display();

int main(){
	int choice, value, choice1, pos, del;
	while(true){
		printf("\n\n-------MENU---------\n");
		printf("1. Insert at beginning\n2. Insert at End\n3. Insert at location\n4. Delete at beginning\n5. Delete at end\n6. Delete at location\n7. Display\n8. Exit\n\nEnter your choice:  ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the value to be insert: ");
			        scanf("%d",&value);
			        insertAtBeginning(value);
			        break;
			case 2: printf("Enter the value to be insert: ");
			        scanf("%d", &value);
			        insertAtEnd(value);
			        break;
			case 3: printf("Enter the value to be insert: ");
			        scanf("%d", &value);
			        printf("Enter the position after which you want to insert: ");
			        scanf("%d", &pos);
			        insertPosition(value,pos);
			        break;
			case 4: removeBeginning();
			        break;
			case 5: removeEnd();
			        break;
			case 6: printf("Enter the  value which you want to delete: ");
			        scanf("%d", &pos);
			        removePosition(pos);
			        break;
			case 7: display();
			        break;
			case 8: exit(0);
			default : printf("\nWrong Input. Please try again!\n\n");
		}
	}
}


void insertAtBeginning(int value){
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	if(head == NULL){
		newNode->next = NULL;
		head = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
	printf("\nNode inserted successfully at beginning\n");
}

void insertAtEnd(int value){
	Node *newNode;
	newNode->data = value;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
	}else{
		Node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
			temp->next = newNode;
		}
		printf("\nNode inserted successfully at end\n");
	}
}

void insertPosition(int value, int pos){
	int i=0;
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	if(head == NULL){
		newNode->next = NULL;
		head = newNode;
	}else{
		Node *temp = head;
		for(i=0; i<pos-1;i++){
			temp=temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	printf("\nNode inserted successfully\n");
}

void removeBeginning(){
     if(head == NULL){
     	printf("\n\nList is already Empty!");
	 }else{
	 	Node *temp = head;
	 	if(head->next == NULL){
	 		head = NULL;
	 		free(temp);
		 }else{
		 	head = temp->next;
		 	free(temp);
		 	printf("\nNode deleted at the beginning\n\n");
		 }
	 }
}

void removeEnd(){
	if(head == NULL){
		printf("\nList is Empty\n");
	}else{
		Node *temp1 = head, *temp2;
		if(head->next == NULL){
			head == NULL;
		}else{
			while(temp1->next != NULL){
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = NULL;
		}
		free(temp1);
	    printf("\nNode deleted as the end\n\n");
	}
}

void removePosition(int pos){
	int i,flag = 0;
	Node *temp1 = head, *temp2;
	if(pos == 1){
		head = temp1->next;
		free(temp1);
		printf("\nNode deleted\n\n");
	}else{
		for(i=0;i<pos-1;i++){
			if(temp1->next != NULL){
				temp2 = temp1;
				temp1 = temp1->next;
			}else{
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			temp2->next = temp1->next;
			free(temp1);
			printf("\nNode deleted\n\n");
		}else{
			printf("Position exceeds linked list. Please try again");
		}
	}
}

void display(){
	for(Node *ptr=head;ptr!=NULL;ptr=ptr->next){
		cout<<"->"<<ptr->data;
	}cout<<endl;
}
