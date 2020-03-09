/*#include <iostream>

using namespace std;

int main()
{
    int num,area,a[6][2],x=0,y=0,m=0,n=0;
    FILE *input;
    FILE *output;
    input=fopen("INPUT.TXT","r");
    output=fopen("OUTPUT.TXT","w");
    fscanf(input,"%d",&num);
    for(int i=0;i<6;i++)
    {
        fscanf(input,"%d %d",a[i][0],a[i][1]);
        if(a[i][0]==4){
            x++;
        }
        else(a[i][0]==3){
            y++;
        }
        if(a[i][1]==1){
            m++;
        }
        else(a[i][1]==2){
            n++;
        }
    }

    if(x>y){
            x=4;
        }
    else{
        x=3;
    }
    if(m>n){
            m=1;
        }
    else{
        m=2;
    }

    fprintf(output,"%d",num*area);
    fclose(input);
    fclose(output);
}*/
#include <stdio.h>

int where[6][2];
void line(void);
int size(void);
int main(void)
{
    int k, i, sum;

    scanf("%d", &k);

    for(i=0; i<6; i++)
    {
        scanf("%d", &where[i][0]);
        scanf("%d", &where[i][1]);
    }

    line();
    sum=size();

    printf("%d", sum*k);

    return 0;
}
void line(void)
{
    int i, num[4]={0}, n[2], k=0, temp1, temp2;

    for(i=0; i<6; i++)
    {
        num[where[i][0]]++;

        if(num[where[i][0]]==2)
            n[k++]=where[i][0];
    }

    while(where[5][0]!=num[0] && where[5][0]!=num[1])
    {
        temp1=where[5][0];
        temp2=where[5][1];

        for(i=4; i>=0; i--)
        {
            where[i+1][0]=where[i][0];
            where[i+1][1]=where[i][1];
        }

        where[0][0]=temp1;
        where[0][1]=temp2;
    }
}
int size(void)
{
    int sum, cut, i, x=0, y=0;

    for(i=0; i<6; i++)
    {
        if(where[i][0]==1)
            x+=where[i][1];

        else if(where[i][0]==3)
            y+=where[i][1];
    }

    sum=x*y;///ÀüÃ¼ ³ÐÀÌ

    for(i=0; i<6; i++)
    {
        where[i][0]--;

        if((where[i][0]/2)==0 && where[i][1]<x)
        {
            cut=where[i+1][1]*where[i+2][1];
            break;
        }

        else if((where[i][0]/2)==1 && where[i][1]<y)
        {
            cut=where[i+1][1]*where[i+2][1];
            break;
        }
    }

    sum-=cut; ///ÆÄÀÎ ºÎºÐ »©±â
    return sum;
}
