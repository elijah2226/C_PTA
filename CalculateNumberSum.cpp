#include <stdio.h>
#include <math.h>
//	用结构体比较清晰 
struct nub{
	long son;
	long mor;
}arr_nub[100];

//	辗转相除法，以后补充图片 
long gcd(long son, long mor){
	long res;
	if(mor == 0){
		res = son;
	}else{
		res = gcd(mor, son%mor);
	}
	return res;
}

int main(){
	int N;
	long son, mor, gcd_nub;
	scanf("%d", &N);
//	先约分，再存入数组 
	for(int i = 0; i < N; i++){
		scanf("%ld/%ld", &son, &mor);
		gcd_nub = gcd(son,mor);
		son /= gcd_nub;
		mor /= gcd_nub;
		arr_nub[i].son = son;
		arr_nub[i].mor = mor;
	}
//	先用第一个数定义sum
	struct nub sum;
	sum.mor = arr_nub[0].mor;
	sum.son = arr_nub[0].son;
//	通分相加 
	for(int i = 1; i < N; i++){
//		取出已经计算和待计算的分子分母 
		long aSon = sum.son, aMor = sum.mor, bSon = arr_nub[i].son, bMor = arr_nub[i].mor;
//		printf("%ld/%ld + %ld/%ld\n", aSon, aMor, bSon, bMor);
		gcd_nub = gcd(aMor, bMor);
//		分母通分
		aMor /= gcd_nub;
		bMor /= gcd_nub;
//		存储一下 
		int tempa = aMor, tempb = bMor;
		aMor *= tempb*gcd_nub;
		bMor *= tempa*gcd_nub;
//		分子通分
		aSon *= tempb;
		bSon *= tempa;
//		两数相加
		aSon += bSon;
//		相约
		gcd_nub = gcd(aSon, aMor);
		aSon /= gcd_nub;
		aMor /= gcd_nub;
//		储存 
		sum.son = aSon;
		sum.mor = aMor;
//		printf("res: %ld/%ld\n", sum.son, sum.mor);
	}
//	输出 
	if(sum.son != 0){
		if(sum.son%sum.mor != 0){
			if(sum.son > sum.mor){
				long dig = sum.son/sum.mor;
				sum.son %= sum.mor;
				printf("%ld %ld/%ld", dig, sum.son, sum.mor);
			}else{
				printf("%ld/%ld", sum.son, sum.mor);
			}
		}else{
			long dig = sum.son/sum.mor;
			printf("%ld", dig);
		}
	}else{
		printf("0\n");
	}
	return 0;
} 
