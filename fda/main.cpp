#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

int k,c,arr[100000][3];

int solve();

int main(){
    scanf("%d %d",&k,&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    solve();
    for(int i=0;i<c;i++)
    {
        printf("%d\n",arr[i][2]);
    }
}

int solve(){
    for(int i=0;i<c;i++)
    {
        int a=arr[i][0],b=arr[i][1];
        int gap = a-b;
        int remain = k - std::max(a, b);

        if (a == b) {
            arr[i][2]=1;
        } else if (a < b) {
            if (gap - remain <= 1) {
                arr[i][2]=1;
            } else {
                arr[i][2]=0;
            }
        } else {
            if (gap - remain <= 2) {
                arr[i][2]=1;
            } else {
                arr[i][2]=0;
            }
        }
    }
}
