#include <iostream>
#define MAX 50
using namespace std;

int n,ans,coll[MAX+1],down[MAX*2+2],up[MAX*2+2];

int solve(int r)
{
    if(r>n)
    {
        ans++;
        return ans;
    }
    for(int i=1;i<=n;i++)
    {
        if(!coll[i] && !up[r+i] && !down[n+(r-i)+1])
        {
            coll[i]=up[r+i]=down[n+(r-i)+1]=1;
            solve(r+1);
            coll[i]=up[r+i]=down[n+(r-i)+1]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    solve(1);
    printf("%d",ans);
    return 0;
}
