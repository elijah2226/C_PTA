#include <stdio.h>
#include <string.h>

int main(){
	int money, five = 0, two = 0, one = 0, count = 0;
	scanf("%d", &money);
	if(money != 0){
		int temp5 = money;
		five = temp5/5;
		do{
			int temp2 = temp5 - 5*five;
			two = temp2/2;
			do{
				int temp1 = temp2-2*two;
				if(temp1 != 0){
					one = temp1;
					temp1 = 0;
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", five, two, one, five+two+one);
					count++; 					
				}
				two--;
			}while(two > 0);
			five--;
		}while(five > 0);
		printf("count = %d", count);
	}else{
		printf("count = %d", count);
	}
    return 0;
}
