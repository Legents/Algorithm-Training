#include<stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
int main()
{
    int N,i;
    LinkList p,h;
    do{
        scanf("%d",&N);
    }while(N<0||N>1000);
    h=(LinkList)malloc(sizeof(Node));
    if(!h)
        {
            printf("³õÊ¼»¯Á´±í´íÎó£¡\n");
            exit(0);
        }
    h->next=h;
    for(i=N;i>0;i--)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=i;
        p->next=h->next;
        h->next=p;
    }
    p=h;
    while(p->data!=NULL)
    {

        printf("%d  ",p->data);
        p=p->next;
    }
      return 0;

}
