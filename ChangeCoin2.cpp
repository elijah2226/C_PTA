#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
//	nub数组储存使用硬币个数，max_nub储存最多硬币个数， sum数组储存还有多少钱 
	int nub[3] = {1,1,1}, max_nub[2] = {30}, sum[3] = {150}, count = 0;
	for(; nub[0] <= max_nub[0]; nub[0]++){
//		用了5分还剩多少钱 
		sum[1] = sum[0]-nub[0]*5;
		max_nub[1] = 100-nub[0]-1;
		for(nub[1] = 1; nub[1] <= max_nub[1]; nub[1]++){
//			用了2分还剩多少钱 
			sum[2] = sum[1]-nub[1]*2;
			nub[2] = 100-nub[0]-nub[1]; 
			if(sum[2] == nub[2]){
				count++;
				printf("%d %d %d\n", nub[0], nub[1], nub[2]);
				if(count == n){
					goto out;
				}
				break;
			}
			
		}
	}
	out:
    return 0;
}
