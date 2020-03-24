#include <stdio.h>
//一张扑克卡 
static struct SingleCard{ 
	char sys;
	int nub;
}SgCard;
//一副扑克卡 
static struct CardTeam{
//	用数字暂时存储牌,方便重整 
	int card_temp[54];
	struct SingleCard SgCard[54];
	int pos[54];
}Card;

int main(){
	int rep, suf[54];
	char sys[5] = {'S', 'H', 'C', 'D', 'J'};
	scanf("%d", &rep);
	for(int i = 0; i < 54; i++){
//		读入打乱规则 
		int index, nub;
		scanf("%d", &suf[i]);
//		printf("%d\n", suf[i]);
//		初始化数组和位置 
		index = i / 13;
		nub = (i+1) % 13;
		if(nub == 0){
			nub = 13;
		}
		Card.pos[i] = i+1;
		Card.card_temp[i] = i+1;
//		Card.SgCard[i].nub = nub;
//		Card.SgCard[i].sys = sys[index];
//		printf("%d:%c%d\n", Card.pos[i], Card.SgCard[i].sys, Card.SgCard[i].nub);		
	}
//	打乱
	while(rep > 0){
		for(int i = 0; i < 54; i++){
			Card.pos[i] = suf[i];
		}
//		重整
		int temp;
		for(int i = 0; i < 54; i++){
			temp = Card.card_temp[i];
			printf("use temp to save the card(%d) of the No.%d\n", temp, i+1); 
			for(int y = 0; y < 54; y++){
				if(Card.pos[y] == i+1){
//					交换卡牌并且交换位置值 
					Card.card_temp[i] = Card.card_temp[y];
					Card.card_temp[y] = temp;
					int postemp = Card.pos[i];
					Card.pos[i] =  Card.pos[y];
					Card.pos[y] = postemp;
					printf("found the No.%d and swipe: now No.%d is %d, No.%d is %d\n", y+1, i+1, Card.card_temp[i], y+1, Card.card_temp[y]); 
					break;
				}
			}
		}
		
		rep--;
	}
    return 0;
}
