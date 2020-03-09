#include <stdio.h>
#include <stdlib.h>

int recur(int n){
    if(n==0||n==1) {printf("%d",n);}
    else{
        recur(n/2);
        printf("%d",n%2);
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    recur(n);
}
