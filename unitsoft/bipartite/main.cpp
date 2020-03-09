#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int v,e;
int a,b;
int flag[20001];
int check[20001];
int lgflag=0;
vector<int> graph[20001];

int dfs(int k){
    if(check[k]) return 0;
    for(auto x: graph[k]){
        if(!flag[x]){
            flag[x]=(-1)*flag[k];
            dfs(x);
        }
        else if(flag[x]==flag[k]){
            lgflag=1;
            break;
        }
    }
    check[k]=1;
    return 1;
}

int main(){
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    flag[1]=1;
    dfs(1);
    if(lgflag) printf("NO");
    else printf("YES");
}
