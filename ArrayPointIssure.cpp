#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}
/* 你的代码将被嵌在这里 */

//#include <string.h>
//char *getmonth( int n ){
//	char *month[12]={
//    "January",
//    "February",
//    "March",
//    "April",
//    "May",
//    "June",
//    "July",
//    "August",
//  	"September",
//    "October",
//    "November",
//    "December"
//  };
//  char *p = NULL;
//  if(n <= 12){
//		p = month[n-1];
//  }
//  return p;
//}

//	主程序输出时有错误
#include <string.h>
char *getmonth( int n ){
	char month[12][10]={
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
  	"September",
    "October",
    "November",
    "December"
  };
  char *p = NULL;
  if(n <= 12){
		p = month[n-1];
  }
  return p;
} 
