#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 987654321
using namespace std;

int len,max_value;
string permutationWithoutSpace;

bool visited[MAX];
vector<int> v;

void dfs(int ind){
    if(ind == len){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        exit(0);
    }
    string p = "";
    int ptoi = 0;
    for(int i=ind; i<=ind+1; i++){
        p += permutationWithoutSpace[i];
        ptoi = stoi(p);

        if(ptoi > max_value) continue;
        if(visited[ptoi]) continue;

        v.push_back(ptoi);
        visited[ptoi] = true;
        dfs(i+1);
        visited[ptoi] = false;
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> permutationWithoutSpace;
    len = (int) permutationWithoutSpace.size();
    if(len < 10){
        max_value = len;
    }else{
        max_value = (len - 9) / 2 + 9;
    }
    memset(visited, false, sizeof(visited));
    dfs(0);
    return 0;
}
