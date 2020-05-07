#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int prt_esc_char(const char* s);

int main()
{
//	char *line = (char*)malloc(1024*sizeof(char));
	char line[] = {0x08, 0x09, 0x0A, 0x0D, 0x10, 't', '\0'};
//	gets(line);
	int len = prt_esc_char(line);
	printf("%d\n", len);
	return 0;
}
#include <string.h>
#include <ctype.h>
int prt_esc_char(const char *s){
	int count = 0, flag, len = strlen(s);
//	之前循环条件是s[i]是否为空字符'/0'或EOF,但是不用这么麻烦 
	for(int i = 0; i < len; i++){
    	if(iscntrl((int)s[i])){
//    		如果是控制字符 
    		flag = 1;
    		switch(s[i]){
    			case(8):
    				fprintf(stdout, "\\b");
    				break;
    			case(9):
    				fprintf(stdout, "\\t");
    				break;
    			case(10):
    				fprintf(stdout, "\\n");
    				break;
    			case(13):
    				fprintf(stdout, "\\r");
    				break;
    			default:
//    				之前卡在这里，误以为题目要16进制转换成10进制 
    				fprintf(stdout, "\\%X", s[i]);
    				flag = 0;
    				break;
				}
//			计数 
			if(flag){
				count += 2;
			}else{
				count += 3;
			}
		}else{
//			不是控制字符 
			fprintf(stdout, "%c", s[i]);
			count ++;
		}
	}
  return count;
}
//
//////	别人正确的
//#include<string.h> 
//int prt_esc_char(const char *s)
//{
//	int i,size=strlen(s),count=0;
//	char p[3];
////	循环遍历 
//	for(i=0;i<size;i++)
//	{
////		非控制字符 
//		if(s[i]>=0x20)
//		{
//			putchar(s[i]);
//			count++;
//		}
////		控制字符 
//		else if(s[i]<32)
//		{
//			if(s[i]=='\n')
//			{
//				putchar('\\');
//				putchar('n');
//				count+=2;
//			}
//			else if(s[i]=='\t')
//			{
//				putchar('\\');
//				putchar('t');
//				count+=2;
//			}
//			else if(s[i]=='\b')
//			{
//				putchar('\\');
//				putchar('b');
//				count+=2;
//			}
//			else if(s[i]=='\r')
//			{
//				putchar('\\');
//				putchar('r');
//				count+=2;
//			}
//			else
//			{
//				sprintf(p,"%X",s[i]);
//				putchar('\\');
//				count+=3;
//				if(s[i]<0x10)
//				{
//					putchar('0');
//					putchar(p[0]);
//				}
//				else
//				{
//					putchar(p[0]);
//					putchar(p[1]);
//				}
//				
//			}
//		}
//	}
//	return count;
//}


