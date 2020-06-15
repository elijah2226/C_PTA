#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
typedef struct node{
	int value;
	struct node *next;
}node;

typedef struct{
    node *head;
    node *tail;
}List;

List list_create();
void list_free(List *list);

void list_append(List *list, int v);
void list_insert(List *list, int v);

void list_set(List *list, int index, int v);
int list_get(List *list, int index);

int list_size(List *list);

int list_find(List *list, int v);
void list_remove(List *list, int v);

void list_iterate(List *list, void (*func)(int v));
#endif
