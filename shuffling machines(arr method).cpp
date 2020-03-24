#include <stdio.h>

int main(){
	int org[54], temp[54], suf[54], suftm;
	char sys[6] = {'S', 'H', 'C', 'D', 'J'};
	scanf("%d", &suftm);
	//	读入打乱规则和初始化牌组 
	for(int i = 0; i < 54; i++){
		scanf("%d", &suf[i]);
		org[i] = i+1;
	}
	while(suftm > 0){
	//	寻找第1到第54位牌，按顺序放入temp数组中 
		for(int i = 0; i < 54; i++){
			for(int y = 0; y < 54; y++){
				if(suf[y] == i+1){
					temp[i] = org[y];
					break;
				}
			}
		}
	//	temp数组转移到org数组，temp数组置0 
		for(int i = 0; i < 54; i++){
			org[i] = temp[i];
			temp[i] = 0;
		}
		suftm--;
	}
//	输出
	int nub, sybl;
	for(int i = 0; i < 54; i++){
		nub = org[i] % 13;
		sybl = org[i] / 13;
		if(nub == 0){
			nub = 13;
			sybl--;
		}
		if(i != 53){
        	printf("%c%d ", sys[sybl], nub);
        }
        else{
            printf("%c%d", sys[sybl], nub);
        }
	
	} 
	return 0;
}
