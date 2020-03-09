#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct{
    long int x1,x2,y1,y2;
} box;

box p,q;

int main()
{
    scanf("%ld %ld %ld %ld",&p.x1,&p.y1,&p.x2,&p.y2);
    scanf("%ld %ld %ld %ld",&q.x1,&q.y1,&q.x2,&q.y2);
    if (p.x1 == q.x2 || p.x2 == q.x1)
    {
        if (p.y1 == q.y2 || p.y2 == q.y1)
            printf("POINT");
        else if ((p.y2 - p.y1)+(q.y2 - q.y1) > max(q.y2-p.y1, p.y2-q.y1))
            printf("LINE");
        else
            printf("NULL");
    }
    else if ((p.x2 - p.x1)+(q.x2 - q.x1) > max(q.x2-p.x1, p.x2-q.x1))
    {
        if (p.y1 == q.y2 || p.y2 == q.y1)
            printf("LINE");
        else if ((p.y2 - p.y1)+(q.y2 - q.y1) > max(q.y2-p.y1, p.y2-q.y1))
            printf("FACE");
        else
            printf("NULL");
    }
    else
        printf("NULL");

    return 0;
}
