	#include <iostream>
	using namespace std;
	
	class Node {
	private:
		int data;
		Node *next;
	    friend class LinkedList;
	};
	
	class LinkedList{
		public:
			LinkedList();
			int getFront() const;
			void addFront(int dt);
			void removeFront();
			~LinkedList();
			void printAll() const;
		private:
			Node *head;
	};
	int main() {
		LinkedList lista;
		lista.addFront(1);
		lista.addFront(3);
		lista.addFront(5);
		lista.addFront(7);
		//cout<<lista.getFront();
		lista.printAll();
		lista.~LinkedList();
		return 0;
	}

	LinkedList::LinkedList(){
		head=NULL;
		
	}
	int LinkedList::getFront() const{
		return head->data;
	}
	void LinkedList::addFront(int dt){
	    Node *ptr = new Node;
	    ptr->data=dt;
		ptr->next=head;
		head=ptr;
	}
	void LinkedList::removeFront(){
	    Node *ptr = head->next;
		delete head;
		head=ptr;	
	}
	LinkedList::~LinkedList(){
	    while(head!=NULL){
	    	removeFront();
		}	
	}
	void LinkedList::printAll() const{
		Node *ptr=head;
		while(ptr!=NULL){
			cout<<"->"<<ptr->data;
			ptr=ptr->next;
		}
	}
