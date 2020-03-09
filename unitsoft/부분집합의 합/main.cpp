#include <stdio.h>

int arr[20];
int n,s,cnt;

void dfs(int idx,int sum){
    if(idx==n) return;
    dfs(idx+1,sum);
    if(sum+arr[idx]==s) cnt++;
    dfs(idx+1,sum+arr[idx]);
    return;
}

int main()
{
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    dfs(0,0);
    printf("%d",cnt);
    return 0;
}
