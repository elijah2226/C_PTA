#include<cstdio>
#include<cmath>
using namespace std;
int a,len=0;
int f(int n,int b,int l){//剩余被除数，因子，长度
    if(n%b==0) return f(n/b,b+1,l+1);
    else return l;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n%i==0){
            int t=f(n,i,0);
            if(t>len){
                len=t;
                a=i;
            }
        }
    }
    if(len==0){
        printf("%d\n%d\n",1,n);
    }
    else{
        printf("%d\n",len);
        for(int i=1;i<=len;i++){
            printf("%d%c",a+i-1,"*\n"[i==len]);
        }
    }
    return 0;
}
