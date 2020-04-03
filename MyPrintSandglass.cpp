#include <stdio.h>

int main(){
    int rec, sum, lef, n = 0;
    char sys;
    scanf("%d %c", &rec, &sys);
    // 找到第n层
    while(rec > sum){
        n++;
        sum = 2*n*n-1;
    }
    if(rec != sum){
    	    // 最大层
	    n--;
	    // 计算余下
	    sum = 2*n*n-1;	
	}
    lef = rec - sum;
    // 打印上半部
    int temp = n;
    while(temp > 0){
        // 打印空格
        for(int i = 0; i < n-temp; i++){
            printf(" ");
        }
        // 打印星星
        for(int i = 0; i < 2*temp-1; i++){
            printf("%c", sys);
        }
        printf("\n");
        temp--;
    }
    // 从第二层开始打印下半部
    temp = 2;
    while(temp <= n){
        // 打印空格
        for(int i = 0; i < n-temp; i++){
            printf(" ");
        }
        // 打印星星
        for(int i = 0; i < 2*temp-1; i++){
            printf("%c", sys);
        }
        printf("\n");
        temp++;
    }
    printf("%d\n", lef);
    return 0;
}
