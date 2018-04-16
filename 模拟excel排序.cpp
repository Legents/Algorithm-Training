#include <stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct node *Node;
struct node {
    int numberClass;
    char Name[9];
    int Score;
}*Students[100001];

int cmp_numberClass(const void*a,const void*b);
int cmp_Name(const void*a,const void*b);
int cmp_Score(const void*a,const void*b);

int main() {
    int n,operate;
    scanf("%d%d",&n,&operate);

    for(int i=0; i<n; i++) {
        Students[i]=(Node)malloc(sizeof(struct node));
        scanf("%d%s%d",&Students[i]->numberClass,&Students[i]->Name,&Students[i]->Score);
    }

switch(operate){
    case 1:qsort(Students,n,sizeof(Node),cmp_numberClass);break;
    case 2:qsort(Students,n,sizeof(Node),cmp_Name);break;
    case 3:qsort(Students,n,sizeof(Node),cmp_Score);break;
    default :break;
}
for(int i=0;i<n;i++){
    printf("%06d ",Students[i]->numberClass);
    printf("%s",Students[i]->Name);
    printf(" %d\n",Students[i]->Score);
}
    return 0;
}


int cmp_numberClass(const void*a,const void*b) {
    Node x=*(Node*)a;
    Node y=*(Node*)b;
    return x->numberClass-y->numberClass;
}
int cmp_Name(const void*a,const void*b) {
    Node x=*(Node*)a;
    Node y=*(Node*)b;
    int result=strcmp(x->Name,y->Name);
    if(result)return result;
    else return cmp_numberClass(a,b);
}
int cmp_Score(const void*a,const void*b){
    Node x=*(Node*)a;
    Node y=*(Node*)b;
    int result=x->Score-y->Score;
    if(result)return result;
    else return cmp_numberClass(a,b);
}
