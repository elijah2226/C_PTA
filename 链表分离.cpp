#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L ) {
	struct ListNode *p = L;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	struct ListNode *L, *Odd;
	L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
	printlist(L);

	return 0;
}

/* 你的代码将被嵌在这里 */
typedef struct ListNode ListNode;
struct ListNode *readlist() {
//创建一个没有数据的头节点(随便指向一个地方，反正链表也不是临近存放)
//创建一个指向当前链表(已建立的最后一个)结点的指针
	struct ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode *last = head;
	while(1) {
		int temp;
		scanf("%d", &temp);
		if(temp != -1) {
//			新建一个结点
		    struct ListNode *now = (ListNode*)malloc(sizeof(ListNode));
			now -> data = temp;
			now -> next = NULL;
//			更新结点信息
			last -> next = now;
			last = last -> next;
		} else {
			break;
		}
	}
	return head -> next;
}
struct ListNode *getodd( struct ListNode **L ) {
//	删除原链太麻烦了
	struct ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode *last = head;
	struct ListNode *ohead = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode *olast = ohead;
	while(1){
		struct ListNode *now = (ListNode*)malloc(sizeof(ListNode));
		now -> data = (*L) -> data;
		now -> next = NULL;
		if((*L)->data%2){
			olast->next = now;
			olast = olast -> next;
		}else{
			last -> next = now;
			last = last -> next;
		}
		if(!((*L)->next)){
			break;
		}else{
			(*L) = (*L) -> next;
		}
	}
	*L = head -> next;
	return ohead -> next;
}
