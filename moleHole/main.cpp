#include <iostream>

using namespace std;

int cnt,n,arr[30][30],SIZE[30];

bool safe(int,int);
void color(int,int,int);
void locate();

void input;
void output;

int main()
{
    input();
    locate();
    output();
    return 0;
}

void color(int,int,int)
{

}

void locate()
{
    for(int i=0; i<n;i++)
        for(int j=0;j<n;j++)
            if(arr[i][j]==1)
            {
                cnt++;
                color(i,j,cnt+1);
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(arr[i][j])
                SIZE[arr[i][j]-2
    std::sort(SIZE,SIZE+cnt);

}

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void output()
{
    printf("%d",cnt);
    for(int j=0;j<cnt;j++)
    {
        printf("%d",SIZE[j]);
    }
}

bool safe(int a,int b)
{
    return (0<=a && a<n) && (0<=b && b<n);
}
