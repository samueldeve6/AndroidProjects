#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int value;
	struct node *next;
}node;

node *head = NULL;

// Crear un nodo
node *mk_node(int value)
{
	node *p = (node *)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("malloc failed!\n");
		exit(1);
	}
	
	p->value = value;
	p->next = NULL;
	
	return p;
}

// Liberar nodo
void free_node(node *p)
{
	free(p);
}

// Insertar nodo
void insert_node(node *p)
{
	p->next = head;
	head = p;
}

// atraviesa los nodos
void traverse(node *head)
{
	node *p = head;
	
	while (p != NULL)
	{
		printf("%d ", p->value);
		p = p->next;		
	}
	printf("\n");
}

// Destruye la lista vinculada
void destroy_link()
{
	node *p = head;
	
	while (head != NULL)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}

// Encuentra nodos
node *search_node(int value)
{
	node *p = head;
	
	while (p != NULL)
	{
		if (p->value == value)
		{
			return p;
		}

		p = p->next;
	}
	
	return NULL;
}

// Eliminar nodo (rm significa eliminar, no es necesario liberar, liberar solo)
void rm_node(node *p)
{
	node *pre = head;
	
	if (p == head)
	{
		head = head->next;
		p->next = NULL;
		//free_node(p);
		return;
	}
	
	while (pre->next != NULL)
	{
		if (pre->next == p)
		{
			pre->next = p->next;
			p->next = NULL;
			//free_node(p);
			return;
		}
		
		pre = pre->next;
	}
}

// lista inversa
void reverse_list()
{
	node *p = head;
	node *nhead = NULL;
	
	if (p == NULL || p->next == NULL)// Presta atención al pedido, cortocircuito
	{
		return;
	}
	
	while (head != NULL)
	{
		p = head;
		head = head->next;
		
		p->next = nhead;
		nhead = p;
	}
	
	head = nhead;
}

// Eliminar el nodo con valor = x (necesita ser liberado)
void dele_x_node1(int x)
{
	node *p;

	while ((p = search_node(x)) != NULL)
	{
		rm_node(p);
		free_node(p);
	}
}

// Eliminar el nodo con valor = x (necesita ser liberado)
void dele_x_node2(int x)
{
	node *pre = head;
	node *p;
	
	if (head == NULL)
	{
		return;
	}
	
	while (pre->next != NULL)
	{
		p = pre->next;
		if (p->value == x)
		{
			pre->next = p->next;
			free_node(p);
			continue;
		}
		
		pre = pre->next;
	}
	
	if (head->value == x)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}


// Inserción de secuencia
void insert_node_sort(node *p)
{
	//node *p;
	node *pre = head;
	
	if (head == NULL || p->value < head->value)
	{
		p->next = head;
		head = p;
		return;
	}
	
	while (pre->next != NULL)
	{
		if (p->value < pre->next->value)
		{
			break;
		}
			
		pre = pre->next;
	}
	
	p->next = pre->next;
	pre->next = p;
}

// desorden por encargo
void insert_sort(node *&head)
{
	node nhead = {0, NULL};
	node *pre = head;
	node *p = head;
	
	while (head != NULL)
	{
		p = head;
		head = head->next;
		
		pre = &nhead;
		while (pre->next != NULL)
		{
			if (p->value < pre->next->value)
			{
				break;
			}
			
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
	}
	
	head = nhead.next;
}

int main()
{
	int i = 0;
	int value = 0;
	node *p;
	
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		value = rand() % 100 + 1;
		if (i < 5)
		{
			value = 20;
		}
		else
		{
			value = i + 1;			
		}

		p = mk_node(value);
		insert_node(p);
		insert_node_sort(p);
	}
	traverse(head);
	
	insert_sort(head);
	traverse(head);
	
	p = search_node(9);
	if (p == NULL)
	{
		printf("can't find!\n");
	}
	else
	{
		rm_node(p);	
		free_node(p);
	}
	traverse(head);
	
	reverse_list();
	traverse(head);
	
	dele_x_node2(20);
	traverse(head);
	
	
	destroy_link();
	traverse(head);
	
	return 0;
}
