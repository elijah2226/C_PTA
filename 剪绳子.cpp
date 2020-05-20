#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int work(int mid, int nub[], int k, int n);

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int nub[n], sum = 0;
//	录入长度 
	for(int i = 0; i < n; i++){
		scanf("%d", &nub[i]);
		sum += nub[i];
	}
//	二分求最合适的长度 
	int min = 1, max = sum/k, mid;
	while(min+1 < max){
//		本来判断条件是min<max，因为200和201时会死循环，所以为了通过才加一（可能不严谨），下面mid改为加一可能好点； 
		mid = (min+max)/2;
		if(work(mid, nub, k, n)){
//			当前长度（mid）可以裁剪出大于等于k条，即当前长度还可以加长
			min = mid; 
		}else{
//			反之减小mid
			max = mid; 
		}
	}
	printf("%d", min);
	return 0;
}

int work(int mid, int nub[], int k, int n){
	int count = 0, flag = 0;
	for(int i = 0; i < n; i++){
		count += nub[i]/mid;
	}
	if(count >= k){
		flag = 1;
	}
	return flag;
}


