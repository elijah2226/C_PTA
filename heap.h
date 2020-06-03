//下沉操作
void downAdjust(int a[], int parent, int len){
//	缓存要下沉的结点，先左子结点 
	int temp = a[parent], child = 2*parent+1;
	while(child < len){
//		右子结点更大,需判断右子结点是否存在 
		if(child+1<len && a[child+1]>a[child]){
			child++;
		}
//		更下沉结点比较 
		if(a[child] <= temp){
			break;
		}
//		单向赋值,子节点上移
		a[parent] =  a[child];
		parent = child;
		child = 2*parent+1;
	}
	a[parent] = temp; 
} 

//构建二叉堆（最大堆） 
void cstHeap(int a[], int len){
	for(int i = (len-2)/2; i >= 0; i--){
		downAdjust(a, i, len); 
	} 
}
