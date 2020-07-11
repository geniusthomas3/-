#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>g(26);

int check[26];
int checkprime[26];

int dfs(int a){
    printf("%c",a+'A');
    for(auto x : g[a]){
        if(checkprime[x]==0){
            checkprime[x]=1;
            dfs(x);
        }
    }
    return 0;
}

int main(){
    int n,e;
    char a,b;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        scanf(" %c %c",&a,&b);
        g[a-'A'].push_back(b-'A');
        g[b-'A'].push_back(a-'A');
    }
    for(int i=0;i<26;i++){
        sort(g[i].begin(),g[i].end());
    }
    char k;
    scanf(" %c",&k);
    k=k-'A';
    checkprime[k]=1;
    dfs(k);
    queue<int> q;
    q.push(k);
    check[k]=1;
    printf("\n");
    while(!q.empty()){
        int node=q.front();
        q.pop();
        printf("%c",node+'A');
        for(auto x : g[node]){
            if(check[x]==0){
                check[x]=1;
                q.push(x);
            }
        }
    }
    return 0;
}
