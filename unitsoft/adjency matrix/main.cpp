#include <stdio.h>

int arr[1000][1000];
int n,m;
int a,b;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        arr[a-1][b-1]=1;
        arr[b-1][a-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
