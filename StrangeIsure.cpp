#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dstr_readword();

int main()
{
	char *s = dstr_readword();
//	int len = strlen(s);
	printf("%lu-%s\n", strlen(s), s);
	return 0;
}

/* 请在这里填写答案 */
//char *dstr_readword(){
//	char *s = (char*)calloc(10,sizeof(char)), temp;
//	int i = 0, flag = 0;
//	scanf("%c", &temp);
//	while(temp!=' ' && temp!='\n' &&temp!='\t' && temp!='\r' && temp!='\0' ){
//		s[i] = temp;
//    if(!((i+1)%10)){
//		int nub = (i+1)/10;
//      	s = (char*)realloc(s,sizeof(char)*10*(nub+1));
//    }
//		scanf("%c", &temp);
//		i++;
//	};
//	s[i] = '\0';
////	printf("%s", s);
//	return s;
//}

char *dstr_readword(){
 int size = 1,len = 0;
 char *str = (char*)malloc(size*(sizeof(char)));
 char c;
 while(1){
// 	长度和大小一样的时候就扩展 
  if(len==size){
   str = (char*)realloc(str,(++size)*sizeof(char));
  }
  if(scanf("%c",&c)==EOF  || c=='\n' || c=='\t' || c==' '){
   str[len++] = '\0';
   break; 
  }
  str[len] = c;
  len++; 
 }
 return str;
} 

