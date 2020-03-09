#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int n,k,m;
char arr[100000][30];
int num[50];
int path[100000];
///int connect[100000][100000];
stack<int> stk;


int compare(int ,int );
int search(int ,int);

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",num[i]);
    }
    for(int i=0;i<m;i++)
    {
        search(1,,1)
    }
}

int compare(int a,int b)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        if(arr[a-1][i]!=arr[b-1][i])
        {
            sum++;
        }
    }
    if(sum==1) return 1;
    else return 0;
}

int search(int start,int finish,int count)
{
    if(start==finish) return 0;
    if(count>=n) return -1;
    for(int j=0;j<n;j++)
        {
            if(compare(start,j+1))
            {

                ///search(j+1,finish,count+1);
            }
        }

}
