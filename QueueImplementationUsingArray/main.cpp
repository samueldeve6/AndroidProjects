#include <iostream>
#include <stdio.h>
using namespace std;
//array and pointer initialization
int queue[100];
int n=100, front=-1, rear=-1;

void isEmpty(){
	if(rear==-1 && front==-1){
		cout<<"Queue is empty!"<<endl;
	}else{
		cout<<"Queue is not empty!"<<endl;
	}
}

void isFull(){
	if(rear==n-1){
		cout<<"Queue is Full!"<<endl;
	}else{
        cout<<"Queue is not Full"<<endl;	
	}
}

void Peek(){
	if(front==-1 && rear==-1){
		cout<<"There is no element inside the queue to display!"<<endl;
	}else{
		cout<<"The element at the front node is"<<queue[front]<<endl;
	}
}

void Enqueue(){
	int element;
	if(rear==n-1){
		cout<<"Overflow Error"<<endl;
	}else{
		if(front==-1){
			front=0;
		}
		cout<<"Enter the element for Insertion:"<<endl;
	    cin>>element;
	    rear++;
	    queue[rear]=element;
	}
}

void Dequeue(){
	if(front==-1 && rear==-1){
		cout<<"Underflow Error";
	}else if(front==rear){
		front=rear=-1;
	}else{
		cout<<"The deleted element from the queue is:"<<queue[front]<<endl;
		front++;
	}
}

void Display(){
	if(front ==-1){
		cout<<"Queue is Empty!"<<endl;
	}else{
		cout<<"Queue elements are:"<<endl;
		for(int i=front;i<=rear;i++){
			cout<<queue[i]<<" ";
		}
	}
}
int main() {
	int choice;
	
	cout<<"1) Insert element into the queue"<<endl;
	cout<<"2) Delete element into the queue"<<endl;
	cout<<"3) Display all the elements of the queue"<<endl;
	cout<<"4) Display element at the front node without deletion"<<endl;
	cout<<"5) Display if the queue is full or not!"<<endl;
	cout<<"6) Display if the queue is empty or not!"<<endl;
	cout<<"7) Quit"<<endl;
	do{
		cout<<"\nEnter your choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1: Enqueue(); break;
			case 2: Dequeue(); break;
			case 3: Display(); break;
			case 4: Peek(); break;
			case 5: isFull(); break;
			case 6: isEmpty(); break;
			case 7: exit(1);
			default: cout<<"Invalid choice"<<endl;
		}
	}while(choice!=7);
	return 0;
}
