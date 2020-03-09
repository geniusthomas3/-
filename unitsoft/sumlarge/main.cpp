#include <stdio.h>

int arr[3001][3001];
int sum[3001][3001];
int* part;

int main(){
    int n;
    int i1,i2,j1,j2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+arr[i][j];
        }
    }

}

void recur()
