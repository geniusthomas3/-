#include <stdio.h>

int n,m,table[15][15],x,xn,xm;
long long factorial(int);
long long path(int,int);

int main()
{
    scanf("%d %d %d",&n,&m,&x);
    xn=(x-1)/m;
    xm=(x-1)%m;
    ///printf("%d %d\n",xn,xm);
    printf("%lld",path(xn,xm)*path(n-xn-1,m-xm-1));
    return 0;
}

long long factorial(int i){
    if(i<=0) return 1;
    else return factorial(i-1)*i;
}

long long path(int x,int y){
    return factorial(x+y)/(factorial(x)*factorial(y));
}
