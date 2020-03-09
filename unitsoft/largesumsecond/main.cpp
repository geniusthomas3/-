#include <stdio.h>

int arr[3001][3001];
long long int sum[3001][3001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+(long long int)arr[i][j];
        }
    }

}
