#include <stdio.h>
#include <queue>

using namespace std;

int n,map[50][50],dp[50][50];

void input();
void output();
bool safe(int,int);

int bfs(int,int);

int main(){
    input();

    output();
}

void input(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&map[i][j]);
        }
    }
}

void output(){
    printf("%d",dp[n-1][n-1]);
}

int bfs(int a,int b){

}

bool connected

bool safe(int a,int b){
    return (0<=a && a<n) && (0<=b && b<n);
}
