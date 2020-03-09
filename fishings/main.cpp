#include <iostream>

using namespace std;

int main()
{
    int ans=0,sum=0,n,w,arr[100];
    scanf("%d %d",&n,&w);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-w+1;i++)
    {
        sum=0;
        for(int j=0;j<w;j++)
        {
            sum+=arr[i+j];
        }
        if(sum>ans) ans=sum;
    }
    printf("%d", ans);
    return 0;
}
