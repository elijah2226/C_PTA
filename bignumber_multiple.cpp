#include <stdio.h>
#include <string.h>

int main(){
//	用字符串存储大数,整型数组接受 
	char bnub[21];
	scanf("%s", &bnub);
	int len = strlen(bnub), org[len];
	for(int i = 0, y = len -1; i < len, y >= 0; i++, y--){
		org[y] = bnub[i] - '0';
	}
//	判断第一个数字
	int jug, dblen;
	if(org[len-1] > 4){
		jug = 0;
		dblen = len+1;
	}else{
		jug = 1;
		dblen = len;
	}
//	用数组存入double后的大数 
	int dbl[dblen], flag = 0;
	for(int i = 0; i < len; i++){
		dbl[i] = 2*org[i]%10+flag;
		flag = 2*org[i]/10;
	}
	if(dblen > len){
		dbl[dblen-1] = 1;
	}
//	判断,按位取双倍数组每一个数字和原数组比较 
	if(jug == 1){
		for(int i = 0; i < dblen; i++){
			for(int y = 0; y < len; y++){
				if(dbl[i] == org[y]){
					org[y] = -1;
					break;
				}
				if(y==len-1 && dbl[i]!=org[y]){
					jug = 0;
					goto out;
				}
			}
		}
	}
	out:
	printf("%s\n", (jug == 1) ? "Yes" : "No");
	for(int i = dblen-1; i >= 0; i--){
		printf("%d", dbl[i]);
	}
	return 0;	
}

