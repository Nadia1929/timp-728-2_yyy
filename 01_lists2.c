#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;		   // значение, которое хранит узел
	struct node *next; // ссылка на следующий элемент списка
	struct node *prev; // ссылка на предыдущий элемент списка
} node;

typedef struct list
{
	struct node *head; // начало списка
	struct node *tail; // конец списка
} list;

// инициализация пустого списка
void init(list *l)
{
	l->head = NULL;
	l->tail = NULL;
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
			be->next = NULL;
			l->head->prev = NULL;
		}
		free(l->head);
		l->head->prev = NULL;
		l->head->next = NULL;
		l->head = NULL;
		l->tail = NULL;
		be = NULL;
	}
	else
		printf("Ошибка");
}

// проверка на пустоту списка
bool is_empty(list *l)
{
	if (l->head != NULL)
		return false;
	else
		return true;
}

// поиск элемента по значению. вернуть NULL, если элемент не найден
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

// вставка значения в конец списка. вернуть 0, если успешно
int push_back(list *l, int value)
{
	if (l->head != NULL)
	{
		l->tail->next = malloc(sizeof(node));
		l->tail->next->value = value;
		l->tail->next->next = NULL;
		l->tail->next->prev = l->tail;
		l->tail = l->tail->next;
		return 0;
	}
	else
	{
		l->head = malloc(sizeof(node));
		l->head->value = value;
		l->head->prev = NULL;
		l->head->next = NULL;
		l->tail = l->head;
		return 0;
	}
}

// вставка значения в начало списка. вернуть 0, если успешно
int push_front(list *l, int value)
{
	node *be = malloc(sizeof(node));
	be->value = value;
	be->next = l->head;
	be->prev = NULL;
	l->head->prev = be;
	l->head = be;
	be = NULL;
	return 0;
}

// вставка значения после указанного узла. вернуть 0, если успешно
int insert_after(list *l, node *n, int value)
{
	if (n != NULL)
	{
		node *be = malloc(sizeof(node));
		be->value = value;
		be->next = n->next;
		be->prev = n;
		if (n->next != NULL)
			n->next->prev = be;
		else
			l->tail = be;
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

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value)
{
	if (n != NULL)
	{
		node *be = malloc(sizeof(node));
		be->value = value;
		be->next = n;
		be->prev = n->prev;
		if (n->prev != NULL)
			n->prev->next = be;
		else
			l->head = be;
		n->prev = be;
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

// удалить первый элемент из списка с указанным значением. вернуть 0, если успешно
int remove_first(list *l, int value)
{
	if (l->head == NULL)
		return 1;
	else
	{
		node *be = l->head;
		while (be->next != NULL)
		{
			if (be->value == value)
			{
				if (be->prev == NULL)
				{
					l->head = be->next;
					l->head->prev = NULL;
					free(be);
					be = NULL;
					return 0;
				}
				be->prev->next = be->next;
				be->next->prev = be->prev;
				free(be);
				be = NULL;
				return 0;
			}
			be = be->next;
		}
		if (be->value == value)
		{
			l->tail = be->prev;
			l->tail->next = NULL;
			free(be);
			be = NULL;
			return 0;
		}
		return 1;
	}
}

// удалить последний элемент из списка с указанным значением. вернуть 0, если успешно
int remove_last(list *l, int value)
{
	if (l->head == NULL)
		return 1;
	else
	{
		node *be = l->tail;
		while (be->prev != NULL)
		{
			if (be->value == value)
			{
				if (be->next == NULL)
				{
					l->tail = be->prev;
					l->tail->next = NULL;
					free(be);
					 be= NULL;
					return 0;
				}
				be->next->prev = be->prev;
				be->prev->next = be->next;
				free(be);
				be = NULL;
				return 0;
			}
			be = be->prev;
		}
		if (be->value == value)
		{
			l->head = be->next;
			l->head->prev = NULL;
			free(be);
			be = NULL;
			return 0;
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

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l)
{
	node *be = l->tail;
	while (be != NULL)
	{
		printf("%d ", be->value);
		be = be->prev;
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

	// добавление в конец списка
	int m;
	(void)scanf("%d", &m);
	push_back(&l, m);

	// вывод содержимого списка в обратном порядке
	print_invers(&l);
	printf("\n");

	// добавление в начало списка
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
	insert_after(&l, usel, x);

	// вывод содержимого списка в обратном порядке
	print_invers(&l);
	printf("\n");

	// добавление элемента перед указанным узлом
	int u, y;
	(void)scanf("%d", &u);
	(void)scanf("%d", &y);
	node *xsel = list_index(&l, u);
	insert_before(&l, xsel, y);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// удаление первого элемента списка
	int z;
	(void)scanf("%d", &z);
	remove_first(&l, z);

	// вывод содержимого списка в обратном порядке
	print_invers(&l);
	printf("\n");

	// удаление последнего элемента
	int r;
	(void)scanf("%d", &r);
	remove_last(&l, r);

	// вывод содержимого списка
	print(&l);
	printf("\n");

	// очистка списка
	clean(&l);

	// проверка на пустоту
	bool b = is_empty(&l);

	return 0;
}