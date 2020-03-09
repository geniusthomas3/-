#include <stdio.h>

int main()
{
    int a[10],b[10],c[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%d",b+i);
    }
    int aw=0;
    for(int i=0;i<10;i++)
    {
        if(a[i]>b[i])
        {
            aw++;
        }
        else if(a[i]<b[i])
        {
            aw--;
        }
    }
    if(aw>0)
    {
        printf("A");
    }
    else if(aw==0)
    {
        printf("D");
    }
    else
    {
        printf("B");
    }
    return 0;
}
