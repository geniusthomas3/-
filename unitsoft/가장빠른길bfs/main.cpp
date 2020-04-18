#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

typedef struct{
    int first;
    int second;
    int cnt=0;
}foo;

queue <foo> que;

int n,m;
int arry[103][103];
int flag[103][103];

int main(){
    scanf("%d %d",&n,&m);
    ///border
    for(int i=0;i<=m+1;i++){
        arry[0][i]=1;
    }
    for(int i=0;i<=m+1;i++){
        arry[n+1][i]=1;
    }
    for(int i=0;i<=n+1;i++){
        arry[i][0]=1;
    }
    for(int i=0;i<=n+1;i++){
        arry[i][m+1]=1;
    }
    ///fill
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&arry[n-i+1][j]);
        }
    }
    foo tmp;
    tmp.first=1;
    tmp.second=1;
    tmp.cnt=1;
    que.push(tmp);
    ///[1][1]-->[n][m]
    for(;;){
        tmp=que.front();
        que.pop();
        if(tmp.first==n&&tmp.second==m){
            printf("%d",tmp.cnt);
            break;
        }
        tmp.cnt++;
        if(!arry[tmp.first+1][tmp.second]&&(flag[tmp.first+1][tmp.second]>tmp.cnt||flag[tmp.first+1][tmp.second]==0)){
            tmp.first++; que.push(tmp); tmp.first--;
            flag[tmp.first+1][tmp.second]=tmp.cnt;
        }
        if(!arry[tmp.first-1][tmp.second]&&(flag[tmp.first-1][tmp.second]>tmp.cnt||flag[tmp.first-1][tmp.second]==0)){
            tmp.first--; que.push(tmp); tmp.first++;
            flag[tmp.first-1][tmp.second]=tmp.cnt;
        }
        if(!arry[tmp.first][tmp.second+1]&&(flag[tmp.first][tmp.second+1]>tmp.cnt||flag[tmp.first][tmp.second+1]==0)){
            tmp.second++; que.push(tmp); tmp.second--;
            flag[tmp.first][tmp.second+1]=tmp.cnt;
        }
        if(!arry[tmp.first][tmp.second-1]&&(flag[tmp.first][tmp.second-1]>tmp.cnt||flag[tmp.first][tmp.second-1]==0)){
            tmp.second--; que.push(tmp); tmp.second++;
            flag[tmp.first][tmp.second-1]=tmp.cnt;
        }
    }
    return 0;
}
