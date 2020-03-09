#include <stdio.h>
#include <algorithm>

int n,m,upperlimit,sum=0;
int cost[100000];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",cost+i);
        sum+=cost[i];
    }
    scanf("%d",&m);
    std::sort(cost,cost+n);
    if(m>=sum){
        printf("%d",cost[n-1]);
    }
    else{
        for(upperlimit=cost[n-1];upperlimit>=cost[0];upperlimit--){
            int tmp=sum;
            for(int i=0;i<n;i++){
                if(cost[i]>upperlimit){
                    tmp-=(cost[i]-upperlimit);
                }
            }
            if(tmp<=m){
                printf("%d",upperlimit);
                return 0;
            }
        }
    }
}
