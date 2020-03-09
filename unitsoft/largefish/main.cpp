#include <stdio.h>
#include <stdlib.h>

int n,m,w,h,pond[100][100],max,sum;

int main(){
    scanf("%d %d",&n,&m);
    scanf("%d %d",&w,&h);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&pond[i][j]);
        }
    }
    max=0;
    for(int i=0;i<n+1-w;i++){
        for(int j=0;j<m+1-h;j++){
            sum=0;
            for(int x=0;x<w;x++){
                for(int y=0;y<h;y++){
                    sum+=pond[i+x][j+y];
                }
            }
            if(max<sum) max=sum;
        }
    }
    printf("%d",max);

}
/*
n=3 m=6
w=1 h=2
3 6
1 2
1 0 2 0 4 0
3 4 0 2 0 1
5 2 3 1 7 2
*/
