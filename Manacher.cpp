#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//	马拉车算法 
void AddSeparator(char* s, char* t, char Sep);
int GenerateP(char *s, int p[], int len);

int main(){
	char str_org[1001], str[2002];
	gets(str_org);
	AddSeparator(str_org, str, '#');
//	printf("%s\n", str);
	int len = strlen(str);
  	int* p = (int*)calloc(len, sizeof(int));
	printf("%d", GenerateP(str, p, len));
	return 0;
}

//	预处理：添加分隔符
void AddSeparator(char* s, char* t, char Sep){
	int len = strlen(s);
	if(!len){
		s[0] = '\0';
	}
	int n = 0;
	for(int i = 0; i < len; i++){
		t[n++] = Sep;
		t[n++] = s[i];
	}
	t[n++] = Sep;
	t[n] = '\0';
}

//	使用辅助数组p存储以每个字符为中心的回文子串的长度
int GenerateP(char *s, int p[], int len){
	int maxRight = 0, maxCenter = 0, left, right, mirror, maxlen = 0;
	for(int i = 0; i < len; i++){
//		如果i在最长回串右端（maxRight）内，即已经在最大回文串内，可以借助i关于最长回串中点（maxCenter）对称点（mirror）的信息（p[mirror]） 
		if(i < maxRight){
			mirror = 2*maxCenter-i;
			p[i] = p[mirror]<maxRight-i?p[mirror]:maxRight-i;
		}
//		更新左右下标 
		left = i-p[i]-1;
		right = i+p[i]+1;
//		模拟继续进行
		while(left>=0 && right<len && s[left]==s[right]){
			p[i]++;
			left--;
			right++;
		}
		printf("P[%d]:%d\n", i, p[i]);
//		更新最长回文串中心和其右端
		if(i+p[i] > maxRight){
			maxRight = i + p[i];
			maxCenter = i;
		}
//		判断p[i]不能大于原字符串长，#为中心的回文串可能会长 
		if(p[i] > maxlen ){
			maxlen = p[i];
		}
	}
	return maxlen;
}


