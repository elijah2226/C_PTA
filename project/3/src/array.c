#include"array.h" 
#include<stdlib.h>
//	创建 
Array array_create(){
	Array a;
	a.content = (int*)malloc(sizeof(int)*BLOCK_SIZE);
	a.	size = BLOCK_SIZE;
	return a; 
}
//	释放、删除 
void array_free(Array* array){
	free(array->content);
	array->content = NULL;
	array->size = 0;
}
//	求大小 
int array_size(const Array *array){
	return array->size; 
}
//	扩张 
void array_inflate(Array *array){
	int *p = (int*)malloc(sizeof(int) * (array->size+BLOCK_SIZE));
	int i;
	for(i = 0; i < array->size; i++){
		p[i] = array->content[i];
	}
	free(array->content);
	array->content = p;
	array->size += BLOCK_SIZE;
}
//	求指定位置值 
int array_get(const Array *array, int index){
	return array->content[index]; 
}
//	设置指定位置的值 
void array_set(Array *array, int index, int value){
	array->content[index] = value;
} 
//	复制一个数组 
Array array_clone(const Array *array){
	Array a;
	a.content = (int*)malloc(sizeof(int)*(array->size));
	int i;
	for(i = 0; i < array->size; i++){
		a.content[i] = array->content[i];
	}
	a.size = array->size;
	return a;
}
