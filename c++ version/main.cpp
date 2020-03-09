#include <stdio.h>
#include <algorithm>

int n;
long long int mon=0;
int dist[100000],price[100000];

int solve(int);
long long int distsum(int,int);

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d",dist+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",price+i);
    }
    solve(0);
    printf("%lld",mon);
}

int solve(int current){
    if((current>n-2)) return 0;
    int i;
    for(i=0;i<n;i++){
        if(price[current]>price[i]) break;
    }
    mon+=(long long int)(price[current])*distsum(current,i);
    solve(i);
}

long long int distsum(int s,int e){
    long long int sum=0;
    for(int i=s;i<e;i++){
        sum+=(long long int)dist[i];
    }
    return sum;
}
