#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
	} list;


// инициализация пустого списка
void init(list *l) 
{
	l->head = NULL;
}

// удалить все элементы из списка
void clean(list *l)
{
	if (l->head != NULL)
	{
		node *be = NULL;
		while (l->head->next)
		{
			be = l->head;
			l->head = l->head->next;
			free(be);
		}
		free(l->head);
		be = NULL;
		l->head = NULL;
	}
	else
		printf("Ошибка");
}

// проверка на пустоту списка
bool is_empty(list *l)
{
	if (l->head)
		return true;
	else
		return false;
}

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value)
{
	node *be = l->head;
	while ((be != NULL) && (be->value != value))
		be = be->next;
	if (be == NULL)
	{
		printf("0 ");
		return NULL;
	}
	else
	{
		printf("1 ");
		be = NULL;
	}
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
	if (l->head != NULL)
	{
		node *be = l->head;
		while (be->next != NULL)
		    be = be->next;
		be->next = malloc(sizeof(node));
		be->next->value = value;
		be->next->next = NULL;
		be = NULL;
		return 0;
	}
	else
	{
		node *be = malloc(sizeof(node));
		be->value = value;
		be->next = l->head;
		l->head = be;
		be = NULL;
		return 0;
	}
}


// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
 {
	node *be = malloc(sizeof(node));
	be->value = value; 
	be->next = l->head;
    l->head = be;
	be = NULL;
	return(0);
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
{
	if (n!=NULL)
	{
	node *be = malloc(sizeof(node));
	be->value = value;
	be->next = n->next;
	n->next = be;
	be = NULL;
	return 0;
	}
	else
	{
		printf("Ошибка");
		return 2;
	}
}


// поиск элемента по индексу
node *list_index(list *l, int j)
{
	node *be = l->head;
	int index = 0;
	while (index != j - 1 && be != NULL)
	{
		be = be->next;
		++index;
	}
	return be;
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value)
{
	if (l->head == NULL)
		return 1;
	else
	{
		node *be = l->head;
		node *am = NULL;
		while (be != NULL)
		{
			if (be->value == value)
			{
				if (am == NULL)
				{
					l->head = be->next;
					free(be);
					be = NULL;
					return 0;
				}
				am->next = be->next;
				free(be);
				be = NULL;
				return 0;
			}
			am = be;
			be = be->next;
		}
		return 1;
	}
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l)
{
	node *be = l->head;
	while (be != NULL)
	{
		printf("%d ", be->value);
		be = be->next;
	}
}


int main() 
{
	// количество элементов n
	int n;
	(void)scanf("%d", &n);

	// пустой список
	list l;
	init(&l);

	// занесение n элементов a в список
	int a;
	for (int i = 1; i <= n; ++i)
	{
		(void)scanf("%d", &a);
		push_back(&l, a);
	}

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// поиск элементов по значению
	for (int k = 1; k <= 3; ++k)
	{
		(void)scanf("%d", &a);
		find(&l, a);
	}
	printf("\n");

	// добавление элемента в конец списка
	int m;
	(void)scanf("%d", &m);
	push_back(&l, m);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// добавление в начало
	int t;
	(void)scanf("%d", &t);
	push_front(&l, t);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// добавление элемента после указанного узла
	int j, x;
	(void)scanf("%d", &j);
	(void)scanf("%d", &x);
	node *usel = list_index(&l, j);
	insert_after(usel, x);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// удаление элемента из списка
	int z;
	(void)scanf("%d", &z);
	remove_node(&l, z);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// очистка списка
	clean(&l);

	// проверка на пустоту
	bool b = is_empty(&l);
	return 0;
}
