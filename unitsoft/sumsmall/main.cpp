#include <stdio.h>

int main(){
    int n,m,sum;
    int i1,i2,j1,j2;
    int arr[51][51],ans[50];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        sum=0;
        scanf("%d %d %d %d",&i1,&j1,&i2,&j2);
        for(int x=i1;x<=i2;x++){
            for(int y=j1;y<=j2;y++){
                sum+=arr[x][y];
            }
        }
        ans[i]=sum;
    }
    for(int i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
}
