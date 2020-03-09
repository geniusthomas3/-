#include <stdio.h>
#include <stdlib.h>

int n,tmp;
int arr[100001];
long long int Eq[100001][2];
long long int max;
long long int dp(int i);

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    dp(n);
     max=(long long int)(-1)*100000*200000;
    for(int i=0;i<n;i++){
        if(max<E[i][0]) max=E[i][0];
    }
    printf("%lld",max);
}

long long int dp(int i,long long int**E){
    if(E[i][1]==1) return E[i][0];
    if(i==0){
        E[i][0]=(long long int)arr[i];
        E[i][1]=1;
        return E[i][0];
    }
    if(dp(i-1)>=0){
        E[i][0]=(long long int)arr[i]+dp(i-1);
        E[i][1]=1;
    }
    else{
        E[i][0]=(long long int)arr[i];
        E[i][1]=1;
    } return E[i][0];
}
