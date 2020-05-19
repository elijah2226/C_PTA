#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);
	int nub[n], max;
	for(int i = 0; i < n; i++){
		scanf("%d", &nub[i]);
		if(!i){
			max = nub[i];
		}else if(nub[i] > max){
			max = nub[i];
		}
	}
	int* mark = (int*)calloc(max+1, sizeof(int));
	for(int i = 0; i < n; i++){
		if(!mark[nub[i]]){
			if(!i){
				printf("%d", nub[i]);
			}else{
				printf(" %d", nub[i]);
			}
			mark[nub[i]] = 1;
		}
	}
    return 0; 
}

