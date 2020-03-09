#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
    struct Node *before;
}Node;

typedef struct List {
    int node_cnt;
    Node *head,*tail;
    Node *cur;
}List;

Node *new_Node(char);
List *new_List();
void Insert(List *list, char data, int k);
void List_Stat(List *list);

char string[100001];

int main()
{
    List *list=new_List();
    scanf("%s", string);
    Node *current=list->head;
    for(int i=0;string[i]!='\0';i++){
        Node *p=new_Node(string[i]);
        current->next=p;
        p->before=current;
        current=current->next;
    }
    current->next=list->tail;
    list->tail->before=current;
    ///문자열 생성
    list->tail->before->next=list->cur;
    list->cur->before=list->tail->before;
    list->cur->next=list->tail;
    list->tail->before=list->cur;
    ///set cursor
    int n;
    char add,tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&tmp);
        if(tmp=='L'){
            if(list->cur->before==list->head) continue;
            list->cur->next->before=list->cur->before;
            list->cur->before->next=list->cur->next;
            list->cur->next=list->cur->before;
            list->cur->before=list->cur->before->before;
            list->cur->next->before=list->cur;
            list->cur->before->next=list->cur;
        }
        else if(tmp=='D'){
            if(list->cur->next==list->tail) continue;
            list->cur->before->next=list->cur->next;
            list->cur->next->before=list->cur->before;
            list->cur->before=list->cur->next;
            list->cur->next=list->cur->next->next;
            list->cur->before->next=list->cur;
            list->cur->next->before=list->cur;
        }
        else if(tmp=='B'){
            if(list->cur->before==list->head) continue;
            Node *p=list->cur->before;
            list->cur->before=list->cur->before->before;
            list->cur->before->next=list->cur;
            free(p);
        }
        else if(tmp=='P'){
            scanf(" %c",&add);
            Node *p=new_Node(add);
            list->cur->before->next=p;
            p->before=list->cur->before;
            p->next=list->cur;
            list->cur->before=p;
        }
    }
    List_Stat(list);
    return 0;
}

Node * new_Node(char data){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->before= NULL;
    return node;
}

List *new_List(){
    List *list=(List*)malloc(sizeof(List));
    list->head=new_Node('/0');
    list->tail=new_Node('/0');
    list->cur=new_Node('/0');
    list->node_cnt=0;
    list->head->next=list->tail;
    list->tail->before=list->head;
    return list;
}

void List_Stat(List *list){
    if(list->head->next==list->tail) return;
    Node *p=list->head->next;
    while(p->next!=list->tail){
        if(p!=list->cur) printf("%c",p->data);
        p=p->next;
    }
    ///One node left
    if(p==list->cur) return;
    printf("%c",p->data);
}
