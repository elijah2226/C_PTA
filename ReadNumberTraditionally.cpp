#include <stdio.h>
int CountDig(int n){
	int count = 1;
	while(n > 9){
		n /= 10;
		count++;
	}
	return count;
}
struct nub{
	char c;
	int n;
}n2c[10] = {
	{'a', 0},
	{'b', 1},
	{'c', 2},
	{'d', 3},
	{'e', 4},
	{'f', 5},
	{'g', 6},
	{'h', 7},
	{'i', 8},
	{'j', 9}
};

int main(){
	int n;
	scanf("%d", &n);
	int count = CountDig(n), nub[count];
	char unit[8] = {'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'};
	if(n == 0){
		printf("a");
	}
//	写入数组,位数大在前 
	for(int i = count-1; i >= 0; i--){
		nub[i] = n%10;
		n /= 10;
	}
//	读出
	for(int i = 0; i < count; i++){
//		找出数字对应的字符输出，用flag当前是不是零（用于判断单位要不要输出） 
		int flag = 1; 
 		for(int y = 0; y < 10; y++){
 			if(nub[i] == n2c[y].n){
// 				判断：不是零直接输出
				if(y!=0){
	 				printf("%c", n2c[y].c);	
				}else{
					flag = 0;
//					检查下一位是不是零并且自己不是最后以为 
					if(i!=count-1 && nub[i+1] != 0){
						printf("a");
					}
				}
				break;
			}
		}
//		零不输出单位，除非万位！！！ 
		if(flag || count-1-i == 4){
			int index = count-i-2;
			printf("%c", unit[index]); 			
		}
	}
	return 0;
} 
