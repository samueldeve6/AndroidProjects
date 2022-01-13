#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
 
typedef struct LNode
{
    int data;
    struct LNode *pre;
    struct LNode *next;
}*DoubleLinkedList,LNode;
 
 void CreatDoubleLinkedList (DoubleLinkedList & L, int n) // Método de interpolación de cola para crear una lista de doble enlace;
{
    L = (DoubleLinkedList)malloc(sizeof(LNode));
    L->pre = NULL;
    L->next = NULL;
    L->data = 0;
    DoubleLinkedList Tail = L;
    cout<<"Enter "<<n<<" Elem(s) :"<<endl;
    for(int i = 0; i < n; i++)
    {
        DoubleLinkedList Temp = (DoubleLinkedList)malloc(sizeof(LNode));
        cin>>Temp->data;
        Tail->next = Temp;
        Temp->pre = Tail;
        Tail = Temp;
        L->data++;
    }
    Tail->next = NULL;
}
 
 bool GetElem (int & e, int i, DoubleLinkedList L) // Obtener nodo;
{
    while(L != NULL && i > 0)
    {
        i--;
        L = L->next;
    }
    if(i == 0 && L != NULL)
    {
        e = L->data;
        return true;
    }
    else return false;
}
 
 bool InsertElem (int e, int i, DoubleLinkedList L) // Insertar nodo;
{
    if(i > L->data+1 || i < 1)
        return false;
    else
    {
        L->data++;
        while(i > 1)
        {
            L = L->next;
            i--;
        }
        DoubleLinkedList Temp = (DoubleLinkedList)malloc(sizeof(LNode));
        Temp->data = e;
        if(L->next != NULL)
        {
            Temp->next = L->next;
            Temp->pre = L;
            L->next->pre = Temp;
            L->next = Temp;
        }
        else
        {
            Temp->pre = L;
            L->next = Temp;
            Temp->next = NULL;
        }
    }
}
 
 bool DeleteElem (int i, DoubleLinkedList L) // Eliminar nodo;
{
    if(i > L->data || i < 1)
        return false;
    else
    {
        L->data--;
        while(i > 1)
        {
            L = L->next;
            i--;
        }
        DoubleLinkedList Temp = (DoubleLinkedList)malloc(sizeof(LNode));
        Temp = L->next;
        if(L->next->next != NULL)
        {
            L->next->next->pre = L;
            L->next = L->next->next;
        }
        else
            L->next = NULL;
        free(Temp);
        Temp = NULL;
        return true;
    }
}
 
 bool DestoryDoubleLinkedList (DoubleLinkedList & L) // Destruye la lista de enlaces dobles;
{
    if(L->next != NULL)
        DestoryDoubleLinkedList(L->next);
    free(L);
    L = NULL;
    return true;
}
 
 bool ClearDoubleLinkedList (DoubleLinkedList & L) // Borrar la lista de doble enlace;
{
    DestoryDoubleLinkedList(L->next);
    L->next = NULL;
    L->data = 0;
    return true;
}
 
 void GetDoubleLinkedList (DoubleLinkedList L) // Recorrer la lista enlazada individual;
{
    DoubleLinkedList Head = L->next;
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
    DoubleLinkedList L;
    cout<<"How many Elem(s) do you want to creat?"<<endl;
    cin>>n;
    CreatDoubleLinkedList(L,n);
    cout<<"Here is what they look like:"<<endl;
    GetDoubleLinkedList(L);
    cout<<"Which position of Elem do you want?"<<endl;
    cin>>i;
    Flag = GetElem(Elem,i,L);
    if(Flag == true)
        cout<<Elem<<endl;
    else
        cout<<"No maching Elem"<<endl;
    cout<<"What Elem you wanna insert , and where?"<<endl;
    cout<<"Elem :";
    cin>>Elem;
    cout<<"Position :";
    cin>>i;
    Flag = InsertElem(Elem,i,L);
    if(Flag == true)
    {
        cout<<"Succeeded!"<<endl;
        GetDoubleLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    cout<<"Which position of Elem do you want to delete :"<<endl;
    cin>>i;
    Flag = DeleteElem(i,L);
    if(Flag == true)
    {
        cout<<"Succeeded!"<<endl;
        GetDoubleLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    if(ClearDoubleLinkedList(L))   cout<<"DoubleLinkedListed Cleared!"<<endl;
         GetDoubleLinkedList (L); // Verifique que se borre;
    if(DestoryDoubleLinkedList(L))    cout<<"DoubleLinkedList Destoryed!"<<endl;
         if (L == NULL) cout << "Verificar" << endl; // Verificar si está destruido;
    return 0;
}
