#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<sqrt(n);i++)
    {
        if(!(n%i)) sum+=(i+n/i);
    }
    printf("%d",sum);
    return 0;
}
