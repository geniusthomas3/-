#include <stdio.h>
#include <vector>

using namespace std;

int N;
int cnt;

int node[101];
bool visited[101];
bool cycle[101];

bool DFS(int start, int nodeNum){
    if (visited[nodeNum]) return false;
    visited[nodeNum] = true;
    if (start == nodeNum || DFS(start, node[nodeNum])){
        cnt++;
        cycle[nodeNum] = true;
        return true;
    }
    return false;
}

int main(void){
    scanf("%d",&N);
    for (int i = 1; i <= N; i++) scanf("%d",node+i);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++) visited[j] = cycle[j];
        DFS(i, node[i]);
    }
    printf("%d\n",cnt);
    for (int i = 1; i <= N; i++){
        if (cycle[i]) printf("%d\n",i);
    }
    return 0;
}
