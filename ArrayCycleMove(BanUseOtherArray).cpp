#include <stdio.h>

int main(){
//	N:数组的个数
	int N, M; 
  	scanf("%d %d", &N, &M);
  	int nub[N];
//  读入数据 
 	for(int i = 0; i < N; i++){
    	scanf("%d", &nub[i]);
  	}
//  先把M控制在N以内, 如果M为0，即不用移动 
	M %= N;
	if(M){
//  dir:移动的方向：M不大于N/2则为1，否则-1；
//	gap:移动的距离（令其总是不大于N/2） 
//  time:一个元素经过多少次会改变自己（即这一个元素的改变过程会改变多少个元素） 
//	gtime:一共要几轮，即元素总数（N）除以time（一次改变的元素个数） 
		int dir = 1, gap = M, time = 2, gtime;
		if(M > N/2){
			dir = -1;
		}
		if(M > N/2){
			gap = N - M;
		}
		for(; time <= N; time++){
			if(time*gap%N == 0){
				gtime = N/time;
				break;
			}
		}
//	开始移动,stemp缓存代替的元素,ttemp缓存被替代的元素(无法只用一个) 
		int stemp, ttemp;
		for(int i = 0; i < gtime; i++){
//			移动gtime轮 
//			s为待移动元素下标，t为待替换元素下标 
			int s = i, t;
			stemp = nub[s];
			for(int j = 0; j < time; j++){
//				一轮移动time次 
//				获取t下标 
				t = s+dir*gap;
//				越界处理 
				if(t > N-1){
					t %= N;  
				}else if(t < 0){
					t += N;
				}
//				缓存被替换元素 
				ttemp = nub[t];
//				替换 
				nub[t] = stemp;
//				缓存更新
				stemp = ttemp;
//				下标更新
				s = t;
			}
		}
	}
	for(int i = 0; i < N; i++){
		printf("%d", nub[i]);
		if(i != N-1){
			printf(" ");
		}
	}
  	return 0;
}
