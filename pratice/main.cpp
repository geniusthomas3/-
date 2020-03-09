#include <iostream>
#include <algorithm>

int n,list[10000],max;

int total(int tmp){
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(list[i]>tmp) sum+=tmp;
        else sum+=list[i];
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",list+i);
    }
    scanf("%d",&max);
    std::sort(list,list+n);
    int tmp=list[n-1];
    for(;;tmp--)
    {
        if(total(tmp)<=max) break;
    }
    printf("%d",tmp);
    return 0;
}
