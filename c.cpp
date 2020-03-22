#include <stdio.h>
#include <math.h> 
//判断一个数是否是素数，是则返回1 
int isPrime(int a){
	int prime = 1;
	if (a > 2){
//		判断a开方以下的数 
		for(int i = 2; i <= sqrt(a*1.0); i++){
			if(a%i == 0){
				prime = 0;
				break;
			}
		}
	}
	return prime;
}
//寻找数组内的非素数，修改其值为0 
int arrPrime(int number[], int start, int end, int len){
//	从start开始寻找 
	int check = start;
	for(int i = 0; i < len; i++,check++){ 
//		寻找标记的素数
		if(number[i] == 1){
//			printf("found number[%d](%d)\n", i, start+i); 
//			判断是否为素数	
			if(isPrime(check) == 1){
//				printf("%d is a prime\n", check);
			}else{
				number[i] = 0; 
//				printf("%d is not a prime\n", check);
			}
//			把check的倍数全部标记为非素数 
			int next = i + check;
//			防止i=0 
			while(next <= end && check != next){
				if(number[next] == 1){
					number[next] = 0;
//					printf("number[%d](%d) is not a prime\n", next, next+start);
				}
				next += check;			
			}	
		}
	}
	return 1;
}

int main(){
	int min, max, nub = 0, sum = 0;
	scanf("%d %d", &min, &max);
	int len = max - min + 1, number[len];
//	先标记全部是素数 
	for(int i = 0; i < len; i++){
		number[i] = 1;
	}
//	检查是否成功结束 
	if(arrPrime(number, min, max, len) == 1){
		for(int i = 0; i < len; i++){
			if(number[i] == 1){
				sum += min + i;
				nub++;
				printf("%d is a prime, add to sum %d, prime number is %d\n", min+i, sum, nub);
			}
			else{
				printf("%d is not a prime\n", min+i);
			}
		} 
	}
	printf("%d %d", nub, sum); 
    return 0;
}
