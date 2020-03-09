#include <stdio.h>
#include <math.h>

void divide(int n){
    for(int i=n ;i>=1;i--){
        if(n==i){
            printf("%d\n",i);
        }
        else {
            printf("%d+",i);
            divide(n-i);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    divide(n);
}
