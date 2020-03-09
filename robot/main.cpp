#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n,a,b,s,e,w;

typedef pair<int, int> p;
vector<p> g[101010];

int dist[101010];
int maxi[101010];
int chk[101010];

void dfs(int v, int d, int m){
	dist[v] = d;
	maxi[v] = m;
	chk[v] = 1;
	for(auto i : g[v]){
		if(!chk[i.first]) dfs(i.first, d + i.second, max(m, i.second));
	}
}

int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w});
        g[e].push_back({s,w});
    }
    if(a==b){
        printf("0");
        return 0;
    }
    dfs(a,0,0);
    printf("%d",dist[b]-maxi[b]);
}
