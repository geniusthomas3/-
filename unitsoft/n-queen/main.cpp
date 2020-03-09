#include <stdio.h>
#define MAX 9

int n,cnt,up[MAX*2],down[MAX*2],coll[MAX+1];

int solve(int k){
    if(k>n){
        return ++cnt;
    }
    for(int i=1;i<=n;i++){
        if(!coll[i]&&!up[n+i-k]&&!down[n+n-i-k+1]){
            coll[i]=up[n+i-k]=down[n+n-i-k+1]=1;
            solve(k+1);
            coll[i]=up[n+i-k]=down[n+n-i-k+1]=0;
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    solve(1);
    printf("%d",cnt);
}
