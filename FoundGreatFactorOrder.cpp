#include <stdio.h>
#include <math.h>
int IsPrime(int n){
	int flag = 1;
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0){
			flag = 0;
			break;
		}
	}
	return flag;
}

int main(){
	int N, start, max_len = 0, max_start;
	scanf("%d", &N);
//	判断是否是质数 
	if(IsPrime(N) == 0){
//		从2开始到N的开方
		for(int i = 2; i <= sqrt(N); i++){
//			sum储存连续因子的积 
			int len = 0;
			int j = i, start = j;
			long sum = j;
			while(N%sum == 0){
				len++;
				j++;
				sum *= j;
			}
			if(len > max_len){
				max_len = len;
				max_start = start;
			}
		}
	}else{
		max_start = N;
		max_len = 1;
	}
//	输出
	printf("%d\n", max_len);
	for(int i = 0; i < max_len; i++){
		printf("%d", max_start+i);
		if(i != max_len-1){
			printf("*");
		}
	}
	return 0;
} 
