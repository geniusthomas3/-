#include <stdio.h>

int n,m;
int num[20];
int a=0;

using namespace std;

int dfs(int cnt,int sum){
    if(cnt>m-1){
        if(sum==n) a++;
        return 0;
    }
    dfs(cnt+1,sum+num[cnt]);
    dfs(cnt+1,sum-num[cnt]);
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",num+i);
        }
    dfs(0,0);
    printf("%d",a);
    return 0;
}
