#include "linkedlist.h"
#include <stdlib.h>
//typedef node node;
//	新建 
List list_create(){
	List *l = (List*)malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	return *l;
}
//	释放 
void list_free(List *list){
	node *now;
	node *next = list->head;
	while(next){
		now = next;
		next = next->next;
		free(now);
	}
	list->head = NULL;
	list->tail = NULL;
}
//	加到后面 
void list_append(List *list, int v){
	node *p = (node*)malloc(sizeof(node));
	p->value = v;
	if(!list->head){
		list->head = p;
		list->tail = p;
	}else{
		list->tail->next = p;
		list->tail = p; 
	}
	list->tail->next = NULL;
}
//	加到前面 
void list_insert(List *list, int v){
	node *p = (node*)malloc(sizeof(node));
	p->value = v;
	p->next = list->head;
	list->head = p;
	if(!list->tail){
		list->tail = p;
		list->tail->next = NULL;
	}
}
//	第index结点设值 
void list_set(List *list, int index, int v){
	int i;
	node *p = list->head;
	for(i = 0; i < index; i++){
		p = p->next;
	}
	p->value = v;
}
//	获取第index结点的值 
int list_get(List *list, int index){
	int i;
	node *p = list->head;
	for(i = 0; i < index; i++){
		p = p->next;
	}
	return p->value; 
} 
//	获取大小 
int list_size(List *list){
	node *p = list->head;
	int count = 0;
	while(p){
		count++;
		p = p->next;
	}
	return count;
}
//	寻找值为v的结点 
int list_find(List *list, int v){
	int index = 0, res = -1;
	node *p = list->head;
	while(p){
		if(p->value == v){
			res = index;
			break;
		}else{
			p = p->next;
			index++;
		}
	}
	return res;
}
//	去除值为v的结点 ,自己写的有问题 
//void list_remove(List *list, int v){
//	node *now = list->head, *last = list->head;
//	while(now){
//		if(now->value == v){
//			if(now != list->head){
//				last->next = now->next;
//				free(now);
//				now = last->next;
//			}else{
//				list->head = now->next;
//				free(now);
//				last = list->head;
//				now = list->head;
//			}
//		}else{
//			now = now->next;
//			if(now != list->head){
//				last = last->next;
//			}
//		}
//	}
//}
//	参考其他人 
void list_remove(List* list, int v) {
    node* p = list->head, * q = p->next;
    if (p->value == v) {
        if (q) {
            list->head = q;
            free(p);
        }
        else {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    else {
        while (q)
        {
            if (q->value == v) {
                p->next = q->next;
                if (!q->next) {
                    list->tail = p;
                }
                free(q);
                break;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
    }
}
//	遍历，对每个结点的值做func函数 
void list_iterate(List *list, void (*func)(int v)){
	node *p = list->head;
	while(p){
		(*func)(p->value);
		p = p->next;
	}
}
