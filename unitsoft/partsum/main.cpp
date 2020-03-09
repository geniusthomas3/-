#include <stdio.h>
#include <stdlib.h>

int n,m,arr[1000001],cmd[1000000][2],sum,tmp;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",tmp);
        sum+=tmp;
        arr[i]=sum;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&cmd[i][0],&cmd[i][1]);
    }
    for(int i=0;i<m;i++){
        sum=arr[cmd[i][1]]-arr[cmd[i][0]-1];
        printf("%d\n",sum);
    }
}
