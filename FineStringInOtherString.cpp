#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");
    return 0;
}

/* 你的代码将被嵌在这里 */
#include <string.h>

char *search( char *s, char *t ){
	char *res = NULL;
	if(strlen(s)<strlen(t)){
		goto out;
	}
	for(int i = 0; i <= strlen(s)-strlen(t); i++){
		int i2 = i;
		for(int x = 0; x < strlen(t); x++, i2++){
			if(s[i2] != t[x]){
				break;
			}
			if(x == strlen(t)-1){
				res = &s[i];
				goto out;
			}
		}
	}
	return res;
}
