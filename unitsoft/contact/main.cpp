#include <stdio.h>
#include <vector>

int m,n;
int adj[101][101];
int flag[101];
int color=1,tmp=0;
int dfs(int a);
using namespace std;

vector<int> graph[101];
vector<int> group[101];


int main(){
    scanf("%d %d",&n,&m);
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(dfs(i)) color++;
    }
    printf("%d\n",color-1);
    for(int i=1;i<=n;i++){
        group[flag[i]].push_back(i);
    }
    for(int i=1;i<color;i++){
        for(auto x:group[i]){
            printf("%d ",x);
        }
        printf("\n");
    }
}

int dfs(int a){
    if(flag[a]) return 0;
    flag[a]=color;
    for(auto x: graph[a]){
        dfs(x);
    }
    return 1;
}
