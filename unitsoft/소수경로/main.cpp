#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string>
using namespace std;


int check[100000];

int isprime(int a){
    for(int i=1;i*i<a;i++){
        if(!a%i) return 0;
    }
    return 1;
}

int to_int(string num){
    int ret = 0;
    for(int i=0; i<4; i++){
        ret = ret * 10 + (num[i] - '0');
    }
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        queue <int> que;
        que.push(a);
        check[a]=0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int i=0; i<4; i++){
                string node_s = to_string(node);
                for(int j=0; j<10; j++){
                    node_s[i] = j + '0';
                    int next = to_int(node_s);
                    if(next >= 1000 && isprime(next) && check[next] == -1){
                        check[next] = check[node] + 1;
                        que.push(next);
                    }
                }
            }
        }
        if(check[b] != -1){
            printf("%d\n", check[b]);
        }
        else{
            printf("Impossible\n");
        }
    }
}
