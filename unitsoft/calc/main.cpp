#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int num;
    char cal;
    struct Node *next;
    struct Node *before;
}Node;

typedef struct List {
    int node_cnt;
    Node *head,*tail;
}List;

Node *new_Num(int);
Node *new_Char(char);
List *new_List();
char *exp;

int main()
{
    List *list=new_List();
    gets(exp);
    int flag=0,num;
    char cal;
    Node * cur=list->head;
    Node * p;
    for(int i=0;;i++){
        if(!flag){
            sscanf(exp,"%d%*s",&num);
            exp+=(num+20)/10;
            p=new_Num(num);

        }
        if(flag){
            sscanf(exp,"%c%*s",&cal);
            exp+=2;
            p=new_Char(cal);
        }
        flag=!flag;
        cur->next=p;
        p->before=cur;
        cur=cur->next;
        if(flag&&strlen(exp)<=2){
            sscanf(exp,"%d",&num);
            p=new_Num(num);
            cur->next=p;
            p->before=cur;
            p->next=list->tail;
            list->tail->before=p;
            break;
        }
    }
    cur=list->head;
    for(;;){
        if(0)
        {
            if(cur->cal=='*')
            num=cur->next->num*cur->before->num;
            p=new_Num(num);

            cur->before->before->next=p;
            p->before=cur->before->before;

            p->next=cur->next->next;
            cur->next->next;
        }
    }

    return 0;
}

Node * new_Num(int num){
    Node *node=(Node*)malloc(sizeof(Node));
    node->num = num;
    node->cal = NULL;
    node->next = NULL;
    node->before = NULL;
    return node;
}

Node * new_Char(char cal){
    Node *node=(Node*)malloc(sizeof(Node));
    node->num = NULL;
    node->cal = cal;
    node->next = NULL;
    node->before = NULL;
    return node;
}

List *new_List(){
    List *list=(List*)malloc(sizeof(List));
    list->head=new_Num('\0');
    list->tail=new_Num('\0');
    list->head->cal=NULL;
    list->tail->cal=NULL;
    list->node_cnt=0;
    return list;
}
