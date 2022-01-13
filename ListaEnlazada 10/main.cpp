#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
 
typedef struct Node
{
    int data;
    struct Node *next;
}*LinkedList,LNode;
 
void CreatLinkedList (LinkedList & L, int n) // Método de interpolación de cola para crear una lista vinculada individualmente;
{
         L = (LinkedList) malloc (sizeof (LNode)); // inicialización;
    L->next = NULL;
    L->data = 0;
         LinkedList Tail = L; // Puntero de cola;
    cout<<"Enter "<<n<<" number(s)"<<endl;
    for(int i = 0 ; i < n; i++)
    {
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        cin>>Temp->data;
        Tail->next = Temp;
        Tail = Temp;
        Temp = NULL;
                 L-> data ++; // count;
    }
    Tail->next = NULL;
}
 
 bool GetElem (int & e, int i, LinkedList L) // Obtener nodo;
{
    while(L != NULL && i > 0)
    {
        i--;
        L = L->next;
    }
         if (i == 0 && L!= NULL) // Cuando i = 1, también es posible satisfacer la condición de salir al mismo tiempo;
    {
        e = L->data;
        return true;
    }
    else return false;
}
 
 bool InsertElem (int e, int i, LinkedList L) // Insertar nodo;
{
    if(i > L->data+1 || i < 1)    return false;
    else
    {
        L->data++;
        while(i > 1)
        {
            i--;
            L = L -> next;
        }
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        Temp->data = e;
        Temp->next = L->next;
        L->next = Temp;
        Temp = NULL;
        return true;
    }
}
 
 bool DeleteElem (int i, LinkedList L) // Eliminar nodo;
{
    if(i > L->data || i < 1)    return false;
    else
    {
        L->data--;
        while(i > 1)
        {
            i--;
            L = L->next;
        }
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        Temp = L->next;
        L->next = Temp->next;
        free(Temp);
        Temp = NULL;
        return true;
    }
}
 
 bool DestoryLinkedList (LinkedList & L) // Destruye la lista enlazada individual;
{
    if(L->next != NULL)
        DestoryLinkedList(L->next);
    free(L);
    L = NULL;
    return true;
}
 
 bool ClearLinkedList (LinkedList & L) // Lista enlazada única vacía;
{
    DestoryLinkedList(L->next);
    L->next = NULL;
    L->data = 0;
    return true;
}
 
 void GetLinkedList (LinkedList L) // Recorrer la lista enlazada individualmente;
{
    LinkedList Head = L->next;
    while(Head != NULL)
    {
        cout<<Head->data<<endl;
        Head = Head->next;
    }
}
 
int main()
{
    int n,i,Elem;
    bool Flag;
    LinkedList L;
    cout<<"How many Elem(s) do you want to creat?"<<endl;
    cin>>n;
    CreatLinkedList(L,n);
    cout<<"Here is what they look like:"<<endl;
    GetLinkedList(L);
    cout<<"Which position of Elem do you want?"<<endl;
    cin>>i;
    Flag = GetElem(Elem,i,L);
    if(Flag == true)
        cout<<Elem<<endl;
    else
        cout<<"No maching Elem"<<endl;
    cout<<"What Elem you wanna insert , and where?"<<endl;
    cout<<"Elem :";
    cin >>Elem;
    cout<<"Position :";
    cin>>i;
    Flag = InsertElem(Elem,i,L);
    if(Flag == true)
    {
        cout<<"Succeeded!"<<endl;
        GetLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    cout<<"Which position of Elem do you want to delete :"<<endl;
    cin>>i;
    Flag = DeleteElem(i,L);
    if(Flag == true)
    {
        cout<<"Succeeded!"<<endl;
        GetLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    if(ClearLinkedList(L))   cout<<"LinkedListed Cleared!"<<endl;
         GetLinkedList (L); // Verifique que se borre;
    if(DestoryLinkedList(L))    cout<<"LinkedList Destoryed!"<<endl;
         if (L == NULL) cout << "Verificar" << endl; // Verificar si está destruido;
    return 0;
}
