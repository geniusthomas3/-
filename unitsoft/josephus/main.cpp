#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

typedef struct List {
    int node_cnt;
    Node *head,*tail;
}List;

Node *new_Node(int);
List *new_List();
void List_Stat(List *);
void Insert(List *, int, int);
void Delete(List *,int);
int Search_k(List *, int);
int Search_Num(List *,int);

int main(){
    List *list = new_List();
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=-1;i<n-1;i++){
        Insert(list,i+2,i);
    }
    list->tail->link=list->head;
    Node *p=list->head;
    m-=2;
    while(m--) p=p->link;
    Node *tmp=p;
    while(list->node_cnt>1){
        tmp=p->link;
        printf("%d ",tmp->data);
        p->link=tmp->link;
        list->node_cnt--;
        for(int i=0;i<k-1;i++){
            p=p->link;
        }
    }
    printf("\n%d",p->data);
}

Node * new_Node(int data)
{
    Node *node=(Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}

List *new_List(){
    List *list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->node_cnt=0;
    return list;
}

void List_Stat(List *list){
    Node *p=list->head;
    while(p->link!=NULL){
        printf("%d->",p->data);
        p=p->link;
    }
    ///One node left
    printf("%d\n",p->data);
}

void Insert(List *list, int data, int k){
    if(k >list->node_cnt){
        printf("%d번째 원소는 존재하지 않음\n",k);
        return;
    }
    list->node_cnt++;
    Node *node = new_Node(data);///CREATE NEW NODE & INSERT data
    if(list->head == NULL && list->tail == NULL){///EMPTY_LIST
        list->head = node;
        list->tail = node;
        return;
    }
    else {
        Node *p = list->head;
        while(k-- && p->link !=NULL) p=p->link;
        if(p->link != NULL){
            node->link = p->link;
            p->link=node;
        }
        else {
            p->link = node;
            list->tail=node;
        }
    }
}

void Delete(List *list,int k){
    if(list->head == list->tail){
        list->head=NULL;
        list->tail=NULL;
    }
    else if(list->head->link==list->tail){
        if(!k){
            Node* p=list->head;
            list->head->link = NULL;
            list->head = list->tail;
            free(p);
        }
        else{
            Node *p = list->tail;
            list->head->link= NULL;
            list->tail = list->head;
            free(p);
        }
    }
    else{
        Node *p=list->head;
        if(!k){
            list->head=p->link;
            p->link=NULL;
            free(p);
        }
        else{
            while(--k) p= p->link;
            Node *x = p->link;
            if(p->link!=list->tail) p->link= p->link->link;
            else p->link = NULL;
            free(x);
        }
    }
    list->node_cnt--;
}

int Search_k(List *list, int k){
    if(k>list->node_cnt){
        printf("kth element does not exist.\n");
        return -1;
    }
    Node *p=list->head;
    while(k--) p=p->link;
    return p->data;
}

int Search_Num(List *list,int num){
    int k=0;
    Node *p = list->head;
    while(p->data != num && p->link != NULL) p=p->link, k++;
    return k;
}
