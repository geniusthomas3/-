#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int check[101];

int main(){

    int n,k,a,b;
    scanf("%d %d",&n,&k);
    vector<vector<int>>g(n+1);
    for(int i=0;i<k;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue <int> q;
    q.push(1);
    check[1]=1;
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x : g[node]){
            if(check[x]==0){
                check[x]=1;
                cnt++;
                q.push(x);
            }
        }
    }
    printf("%d",cnt);
}
