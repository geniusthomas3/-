/*#include <iostream>

int count[101];
int main()
{
    int arr[10],sum=0,flag=0;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        count[arr[i]/10]++;
    }


    int max=1;
    for(int i=1;i<101;i++)
    {
        if(count[max]<count[i])
        {
            max=i;
        }
    }
    printf("%d\n",sum/10);
    printf("%d\n",max*10);
    return 0;
}


FIFIle
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///c:가로 r: 세로
    int c,r;
    scanf("%d %d",&c,&r);
    int seat[c][r]={0, };
    int man;
    scanf("%d",&man);
    if(man>c*r)
    {
        printf("0");
    }
    int inc=1;
    int col,row,value=1,i;

    for (i = 0; i < n; i++)
    {
        col += inc;
        arr[row][col] = value++;
    }
    n--;
    if (n == 0) break;
    for (i = 0; i < n; i++)
    {
        row += inc;
        arr[row][col] = value;
        value++;
    }
    inc *= -1;


    for(int i=0;i<;i++)
    {
        for(int j=;j<;j+=inc)
        {
            seat[i][j]=count++;
        }
        for(int k=;k<;k+=inc)
        {
            seat[][]
        }
    }







}*/
#include <stdio.h>

int main(){
    int h,m,s;
    int time;
    scanf("%d %d %d %d",&h,&m,&s,&time);
    int count=0;
    time=h*3600+m*60+s+time;
    h=time/3600;
    m=(time%3600)/60;
    s=time%60;
    printf("%d %d %d",h%24,m,s);
}
