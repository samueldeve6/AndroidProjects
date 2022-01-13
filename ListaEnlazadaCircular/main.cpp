#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
 
typedef struct LNode
{
    int data;
    struct LNode *next;
}*CircleLinkedList,LNode;
 
 void CreatLinkedList (CircleLinkedList & L, int n) // método de interpolación de cola para crear una lista circular vinculada;
{
         L = (CircleLinkedList) malloc (sizeof (LNode)); // inicialización;
    L->next = NULL;
    L->data = 0;
         CircleLinkedList Tail = L; // Puntero de cola;
    cout<<"Enter "<<n<<" number(s)"<<endl;
    for(int i = 0 ; i < n; i++)
    {
        CircleLinkedList Temp = (CircleLinkedList)malloc(sizeof(LNode));
        cin>>Temp->data;
        Tail->next = Temp;
        Tail = Temp;
        L->data++;
    }
    Tail->next = L;
}
 
 bool GetElem (int & e, int i, CircleLinkedList L) // Obtener nodo;
{
    CircleLinkedList Head = L;
    while(L->next != Head && i > 0)
    {
        i--;
        L = L->next;
    }
         if (i == 0 && L!= Head) // Cuando i = 1, también es posible satisfacer la condición de salir al mismo tiempo;
    {
        e = L->data;
        return true;
    }
    else return false;
}
 
 bool InsertElem (int e, int i, CircleLinkedList L) // Insertar nodo;
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
        CircleLinkedList Temp = (CircleLinkedList)malloc(sizeof(LNode));
        Temp->data = e;
        Temp->next = L->next;
        L->next = Temp;
        return true;
    }
}
 
 bool DeleteElem (int i, CircleLinkedList L) // Eliminar nodo;
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
        CircleLinkedList Temp = (CircleLinkedList)malloc(sizeof(LNode));
        Temp = L->next;
        L->next = Temp->next;
        free(Temp);
        Temp = NULL;
        return true;
    }
}
 
 bool DestoryCircleLinkedList (CircleLinkedList & L, CircleLinkedList Head) // Destruye la lista circular vinculada;
{
    if(L->next != Head)
        DestoryCircleLinkedList(L->next,Head);
    free(L);
    L = NULL;
    return true;
}
 
 bool ClearCircleLinkedList (CircleLinkedList & L, CircleLinkedList Head) // Borrar la lista circular vinculada;
{
    DestoryCircleLinkedList(L->next,Head);
    L->next = Head;
    L->data = 0;
    return true;
}
 
 void GetCircleLinkedList (CircleLinkedList L) // Atraviesa la lista circular vinculada;
{
    CircleLinkedList Head = L;
    L = L->next;
    while(L != Head)
    {
        cout<<L->data<<endl;
        L = L->next;
    }
}
 
int main()
{
    int n,i,Elem;
    bool Flag;
    CircleLinkedList L;
    cout<<"How many Elem(s) do you want to creat?"<<endl;
    cin >>n;
    CreatLinkedList(L,n);
    cout<<"Here is what they look like:"<<endl;
    GetCircleLinkedList(L);
    cout<<"Which position of Elem do you want?"<<endl;
    cin >>i;
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
        GetCircleLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    cout<<"Which position of Elem do you want to delete :"<<endl;
    cin>>i;
    Flag = DeleteElem(i,L);
    if(Flag == true)
    {
        cout<<"Succeeded!"<<endl;
        GetCircleLinkedList(L);
    }
    else
        cout<<"Failed!"<<endl;
    if(ClearCircleLinkedList(L,L))   cout<<"CircleLinkedListed Cleared!"<<endl;
         GetCircleLinkedList (L); // Verifique que se borre;
    if(DestoryCircleLinkedList(L,L))    cout<<"CircleLinkedList Destoryed!"<<endl;
         if (L == NULL) cout << "Verificar" << endl; // Verificar si está destruido;
    return 0;
}
