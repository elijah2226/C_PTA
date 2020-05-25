#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
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
	head -> next = NULL;
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

struct ListNode *deletem( struct ListNode *L, int m ){
    struct ListNode *check = L;
    struct ListNode *done = L;
    while(1){
        if(check->data == m){
//        	删除 
			struct ListNode *del = check;
            if(check == L){
//            	头节点
				L = L->next; 
			}else{
				done -> next = done -> next -> next;
			}
			if(check->next == NULL){
				break;
			}
			check = check -> next;
			free(del);
        }else{
//        	不删除
			done = check;
			if(check->next == NULL){
				break;
			}
			check = check -> next; 
		}
    }
    return L;
}
