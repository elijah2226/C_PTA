#include <stdio.h>

int read_esc_char(char *line, int len);

#define  LINE_LEN 80

int main()
{
	char line[LINE_LEN];
    printf("%d\n", read_esc_char(line, LINE_LEN));
    printf("%s\n", line);
}

/* 请在这里填写答案 */
#include <stdlib.h> 
int read_esc_char(char *line, int len){
	char *acp = (char*)malloc(1<<10*sizeof(char));
	scanf("%s", acp);
  	int count = 0, acp_i = 0, i = 0;
//  	“接受字符串”(*acp)内还有内容并且“返回字符串”(line)下标还未超过要求 
	while(acp[acp_i] && i < len){
//		找到转义符 (默认找到转义符即找到控制字符)
		if(acp[acp_i] == '\\'){
//			检查转义符后面的字符 
			switch(acp[acp_i+1]){
				case('n'):
					line[i++] = '\n';
					acp_i += 2; 
					break;
				case ('r'):
					line[i++] = '\r';
					acp_i += 2; 
					break;
				case ('t'):
					line[i++] = '\t';
					acp_i += 2; 
					break;
				case ('b'):
					line[i++] = '\b';
					acp_i += 2;
					break;
				default:
//					转义符后不为0（‘\0’）， 
					if(char temp = 16*(acp[acp_i+1]-'0') + (acp[acp_i+2]-'0')){
						line[i++] = temp;
						acp_i += 3; 
					}else{
						goto out;
					}
					break;
			}
		}else{
			line[i++] = acp[acp_i++];
		}
	}
	out:
		if (i >= len){
			i = len - 1;
		}
		line[i] = '\0'; 
  	return i;
}

