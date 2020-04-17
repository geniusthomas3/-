#include <stdio.h>

int h,w;
int dp[11][11];

int dfs(int x,int y){
    //printf("%d %d\n",x,y);
    if(y*h>x*w){
        //printf("C\n");
       /// printf("x:%d y:%d h:%d w:%d n",x,y,h,w);
        return 0;
    }
    if(dp[x][y]!=0) return dp[x][y];
    if(x==0){
        dp[0][y]=1;
        return dp[x][y];
       // printf("A\n");
    }
    if(y==0){
        dp[x][0]=1;
        return dp[x][y];
        //printf("B\n");
    }

    else{
        dp[x][y]=dfs(x-1,y)+dfs(x,y-1);
        return dp[x][y];
        //printf("D\n");
    }
}

int main(){
    scanf("%d %d",&h,&w);
    printf("%d",dfs(h,w));
}
