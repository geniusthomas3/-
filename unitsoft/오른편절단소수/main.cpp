#include <stdio.h>

int tmp[10];
int n;
int cnt=0;

int isprime(int a){
    if(a==0||a==1) return 0;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return 0;
    }
    return 1;
}

int cutprime(int l,int k){
    if(l>n){
        printf("%d\n",k);
        cnt++;
        return 0;
    }
    for(int i=0;i<=9;i++){
        if(isprime(10*k+i)) cutprime(l+1,10*k+i);
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    cutprime(1,0);
    printf("%d",cnt);
    return 0;
}
