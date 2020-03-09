#include <stdio.h>

using namespace std;

int n,m;
int day[101]={1,};
int cost[101][101]={0,};

int dfs(int currentday,int coupon){
    int mincost=987654321;
    if(coupon>=3){
        dfs(currentday+1,coupon-3);
        dfs(currentday+3,coupon+1);
        dfs(currentday+5,coupon+2);
    }
    else{
        dfs(currentday+1,coupon);
        dfs(currentday+3,coupon+1);
        dfs(currentday+5,coupon+2);
    }
    cost[start_day][num_coupon] = min_cost;
    return min_cost;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0,int j;i<m;i++){
        scanf("%d",&j);
        day[j]=0;
    }
    return 0;
}
