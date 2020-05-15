#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct school{
	int ttl_stu;//学生总数 
	int desk_index;//学校当前安排到的座位号 
	int *desk_stu;//每个学生对应的座位号 
}school;

int main(){
	int n;
	scanf("%d", &n);
//	申请n个school结构的数组 
	school scl[n];
//申请一个指针数组（指针的数组），每个指针指向对应的school结构 
//	school *pscl[n];
//	学生总数 
	int stu = 0;
	for(int i = 0; i < n; i++){		
		int temp;
		scanf("%d", &temp);
//		学生总人数初始化 
		scl[i].ttl_stu = 10*temp;
		stu += scl[i].ttl_stu;
//		各个学校的座位表初始化 
		scl[i].desk_stu = (int*)malloc(scl[i].ttl_stu * sizeof(int));
		scl[i].desk_index = 0; 
	}
	int scl_index = 0, desk = 1;
	while(stu){
		if(scl[scl_index].desk_index != scl[scl_index].ttl_stu){
//			当前循环到的学校的学生还没全部安排完就安排当前座位
//			如果前一个同学是本校的
			if(scl[scl_index].desk_stu[scl[scl_index].desk_index-1] == desk-1){
				desk++; 
			}
			scl[scl_index].desk_stu[scl[scl_index].desk_index++] = desk++;
//			安排一个学生后，学生总数（stu）减一 
			stu--;
		}
		scl_index++;
		if(scl_index == n){
			scl_index = 0;
		}
	}
//	输出 
	for(int i = 0; i < n; i++){
		printf("#%d\n", i+1);
		int len = scl[i].ttl_stu;
		for(int j = 0; j < len; j++){
			printf("%d", scl[i].desk_stu[j]);
			if(j%10 != 9){
				printf(" ");
			}else if(i!=n-1 || j!=len-1){
				printf("\n");
			}
		}
	}
	return 0;
}

