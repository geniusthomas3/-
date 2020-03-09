#include <stdio.h>

using namespace std;

int n,k;
typedef struct{
    int x1,y1,d1;
    int x2,y2,d2;

}Domain;
Domain domain[50];
int space[50],sum;

Domain inter(Domain a,Domain b){
    Domain tmp;
    tmp.x1=(a.x1>b.x1 ? a.x1:b.x1);
    tmp.y1=(a.y1>b.y1 ? a.y1:b.y1);
    tmp.d1=(a.d1>b.d1 ? a.d1:b.d1);
    tmp.x2=(a.x2<b.x2 ? a.x2:b.x2);
    tmp.y2=(a.y2<b.y2 ? a.y2:b.y2);
    tmp.d2=(a.d2<b.d2 ? a.d2:b.d2);
    return tmp;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d %d %d",&domain[i].x1,&domain[i].y1,&domain[i].d1,&domain[i].x2,&domain[i].y2,&domain[i].d2);
        sum+=(domain[i].x2-domain[i].x1)*(domain[i].y2-domain[i].y1)*(domain[i].d2-domain[i].d1)
    }
    int cnt=0;
    for(int i=n;i>0;i--){

    }
    return 0;
}



5536
