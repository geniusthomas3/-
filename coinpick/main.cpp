#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
int arr[100],dt[100]={0,};

int cost(int a){
    if(dt[a]!=0){
        return dt[a];
    }
    else{
        if(a==0){
            dt[0]=arr[0];
            return dt[0];
        }
        else if(a==1){
            dt[1]=arr[0]+arr[1];
            return dt[1];
        }
        else if(a==2){
            int x=arr[0]+arr[1];
            int y=arr[0]+arr[2];
            int z=arr[1]+arr[2];
            dt[2]=max(max(x,y),z);
            return dt[2];
        }
        else{
            int x,y,z;
            x=arr[a]+arr[a-1]+cost(a-3);
            y=arr[a]+cost(a-2);
            z=cost(a-1);
            dt[a]=max(max(x,y),z);
            return dt[a];
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("%d",cost(n));
    return 0;
}
