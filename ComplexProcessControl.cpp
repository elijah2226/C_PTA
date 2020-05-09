#include <stdio.h>
#include <string.h>

int main(){
	char in[80];
  	gets(in);
  	int len = strlen(in), n = -1, min, flag;
	char out[len];
  	while(1){
    	if(n != -1){
    		flag = 0;
    		for(int i = 0; i < len; i++){
//    			初始化第一个，min还未改变时 
    			if(in[i]>out[n] && min==out[n]){
    				min = in[i];
    				flag = 1;
				}
//				元素要比out中的最后一个元素大，并且小于min 
				if(in[i]>out[n] && in[i]<min){
					min = in[i];
				}
				if(i==len-1 && !flag){
					goto out;
				}
			}
			out[++n] = min; 
		}else{
//			out数组中的第一个
			min = in[0];
			for(int i = 1; i < len; i++){
				if(in[i] < min){
					min = in[i];
				}
			}
			out[++n] = min;
		}
  	}
  	out:
  		out[++n] = '\0';
		printf("%s", out); 
	return 0;
}
