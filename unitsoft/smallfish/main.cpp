#include <stdio.h>
#include <stdlib.h>

int n,w,arr[100],max=0;

int main(){
    scanf("%d %d",&n,&w);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
        if(i<w) sum+=arr[i];
    }
    if(max<sum) max=sum;
    for(int i=w;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-w];
        if(max<sum) max=sum;
    }
    printf("%d",max);
}

