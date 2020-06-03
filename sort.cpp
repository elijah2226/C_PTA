#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
//	快读
int rd(){
	int res=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res;
} 

void sort ( int a[], int len );


int main(void) {
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		a[i] = rd();
	}
	sort(a, n);
	for ( int i = 0; i < n; i++ ) {
		printf("%d\n", a[i]);
	}
	return 0;
}

/* 请在这里填写答案 */
//	选择排序：从左依次选取，比较有无比它小的数，有则交换
//	（大规模数据超时）
//void sort ( int a[], int len ){
//	int temp;
//	for(int i = 0; i < len-1; i++){
//		for(int j = i+1; j < len; j++){
//			if(a[j] < a[i]){
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}

//	插入排序：从左第二个依次选取，比较左边有无比它大的数
//	(大规模数据超时)
//void sort ( int a[], int len ){
//	int temp;
//	for(int i = 1; i < len; i++){
//		temp = a[i];
//		int y = i - 1;
//		for(; y>=0 && a[y]>temp; y--){
//			a[y+1] = a[y];
//		}
//		a[y+1] = temp;
//	}
//}

//	冒泡排序
//	（大数据超时）
//void sort ( int a[], int len ){
//	int temp;
//	for(int i = 0; i < len-1; i++){
//		for(int y = 0; y < len-1-i; y++){
//			if(a[y] > a[y+1]){
//				temp = a[y];
//				a[y] = a[y+1];
//				a[y+1] = temp;
//			}
//		}
//	}
//}

/*上方三种排序方法时间复杂度都是（n^2）*/

//	哈希排序(升级版插入排序)
//	能通过
//void sort ( int a[], int len ){
//	int temp;
//	for(int gap = len/2; gap > 0 ; gap /= 2){
////		控制递增量
//		for(int i = gap; i < len ; i++){
////			在第一组的第二个元素开始
//			int temp = a[i], y = i - gap;
//			for(; y>=0 && a[y]>temp; y-=gap){
////			此处判断中的temp不能换成a[i]，因为交换后a[i]指向的是大的数字，即只交换一次就结束了
//// 			如果组内前面的元素大
//				a[y+gap] = a[y];
//			}
//			a[y+gap] = temp;
//		}
//	}
//}

//	归并排序
//void MergeSort(int arr[], int left, int right);
//void Merge(int arr[], int left, int center, int right);
//
//void sort(int a[], int len) {
//	int left = 0, right = len-1;
//	MergeSort(a, left, right);
//}
//
//void MergeSort(int arr[], int left, int right) {
//	if(left < right) {
//		int center = (left+right)/2;
////		左边
//		MergeSort(arr, left, center);
////		右边
//		MergeSort(arr, center+1, right);
////		治
//		Merge(arr, left, center, right);
//	}
//}
//
//void Merge(int arr[], int left, int center, int right) {
//	int temp[right-left+1];
//	int i = left, j = center+1, index = 0;
////	两个指针都要在范围内
//	while(i<=center && j<=right) {
//		if(arr[i] <= arr[j]) {
//			temp[index++] = arr[i++];
//		} else {
//			temp[index++] = arr[j++];
//		}
//	}
////	右指针还在里面
//	while(j <= right) {
//		temp[index++] = arr[j++];
//	}
////	左指针还在里面
//	while(i <= center) {
//		temp[index++] = arr[i++];
//	}
////	改变
//	index = 0;
//	for(int i = left; i <= right; i++) {
//		arr[i] = temp[index++];
//	}
//}

//	快速排序（中轴排序）
int partion(int a[], int min, int max);
void quickSort(int a[], int left, int right);

void sort ( int a[], int len ) {
	quickSort(a, 0, len-1);
}
//	递归调用
void quickSort(int a[], int left, int right) {
	int center;
	if(left < right) {
//		得到中轴坐标
		center = partion(a, left, right);
//		左边
		quickSort(a, left, center-1);
//		右边
		quickSort(a, center+1, right);
	}
}

//	单向遍历（版本1，V1）
//int partion(int a[], int min, int max){
////	中轴元素选择第一个，i指向下一个小数存放的位置（左边），j来遍历找到小数
//	int mid = a[min], i = min+1, temp;
//	for(int j = i; j <= max; j++){
//		if(a[j] <= mid){
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//			i++;
//		}
//	}
////	中轴与最后的小数交换
//	temp = a[--i];
//	a[i] = mid;
//	a[min] = temp;
////	返回中轴坐标
//	return i;
//}

//	双向遍历（版本2，V2）
//	updata(随机快排)
//int partion(int a[], int min, int max){
////	生成随机数 
//	int rd = rand()%(max-min+1)+min, temp = a[rd];
//	a[rd] = a[min];
//	a[min] = temp;
////	i指向小数，j指向大数
//	int mid = a[min], i = min+1, j = max;
//	while(1){
////		i<=j必须要判断，因为不判断的话可能会越界（特殊的情况，全等？）
//		/*而且不能判断i<j，即两指针触碰时停止
//		（因而跳出“大”的条件也相应改成i==j，
//		因此不能判断i、j（指向相同的值）指向的是大数还是小数，
//		导致后面中轴值无法判断与谁交换） */ 
//		while(i <= j && a[i] <= mid){
//			i++;
//		}
//		while(i <= j && a[j] > mid){
//			j--;
//		}
//		if(i > j){
//			break;
//		}
//		int temp = a[i];
//		a[i++] = a[j];
//		a[j--] = temp;
//	}
//	temp = a[j];
//	a[j] = mid;
//	a[min] = temp;
//	return j;
//}

//	三路随机快排，避免有多次重复项导致递归爆栈 
 void swap(int a[], int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int a[], int min, int max){
//	生成随机数
	int rd = rand()%(max-min+1)+min;
	swap(a, rd, min); 
//	i指向小数，j指向大数 
	int mid = a[min], i = min+1, q = i, j = max, p = j;
	while(1){
		while(i <= j && a[i] <= mid){
			if(a[i] == mid){
				swap(a, i, q);
				q++;
			}
			i++;
		}
		while(i <= j && a[j] > mid){
			if(a[j] == mid){
				swap(a, j, p);
				p--;
			}
			j--;
		}
		if(i > j){
			break;
		}
		swap(a, i++, j--);
	}
	q--;
	i--;
	while(q >= min){
		swap(a, i--, q--);
	}
	if(p != max){
		p++;
		j++;
		while(p <= max){
			swap(a, p++, j++);
		}
	}
	return (i+j)/2;
}







//	堆排序
//#include <D:\Desktop\C_PTA\heap.h>
//void sort ( int a[], int len ){
////	先构建二叉堆（最大） 
//	cstHeap(a, len);
//	int temp;
//	for(int i = len-1; i > 0; i--){
////		把堆顶放在最后 
//		temp = a[0];
//		a[0] = a[i];
//		a[i] = temp;
//		downAdjust(a, 0, i);
//	}
//}

//	计数排序
//void sort(int a[], int len){
////	寻找最大最小值 
//	int min = a[0], max = a[0];
//	for(int i = 0; i < len; i++){
//		if(a[i] > max){
//			max = a[i];
//		}
//		if(a[i] < min){
//			min = a[i];
//		}
//	}
////	计数 
//	int count[max-min+1] = {0};
//	for(int i = 0; i < len; i++){
//		count[a[i]-min]++;
//	}
////	安排,先遍历count数组，根据count的值来多次写入原数组 
//	int i = 0;
//	for(int index = 0; index < max-min+1; index++){
//		for(int j = count[index]; j > 0; j--){
//			a[i++] = index+min; 
//		}
//	}
//}


//	桶排序（计数排序升级版+插入其他排序方法）

