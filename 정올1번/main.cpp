#include <stdio.h>

int k,sum=0,arr[13],flag[2600000]={0,},tmp=0;

int recur(int a,int idx){
    if(idx==0)
    {
        if(a>0) flag[a]=1;
        return 0;
    }
    recur(a+arr[idx-1],idx-1);
    recur(a,idx-1);
    recur(a-arr[idx-1],idx-1);
}

int main()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",arr+i);
        sum+=arr[i];
    }
    recur(0,k);
    for(int i=1;i<=sum;i++)
    {
        if(flag[i]==0) tmp++;
    }
    printf("%d",tmp);
    return 0;
}
