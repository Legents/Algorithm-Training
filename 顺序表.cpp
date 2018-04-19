#include<stdio.h>
#define LISTSIZE 100
typedef struct{
    int items[LISTSIZE];
    int length;
}SqList;
void PrintList(SqList *L);//打印线性表
void InitList(SqList *L);//初始化线性表
void InsertList(SqList *L,int pos,int item);//往线性表指定位置插入指定元素
void DeleteList(SqList *L,int pos);//删除指定位置的元素
int main()
{
    SqList L;
    int x;
    printf("请选择：\n 1:初始化链表\n 2:插入元素\n 3:删除元素\n 0:退出\n");
    while(scanf("%d",&x)&&x!=0){
    	switch(x){
		case 1: InitList(&L);
    			printf("初始化后的顺序表为：\n");
    			PrintList(&L);
    		    break;
    	case 2: InsertList(&L,6,6);
    			printf("插入元素后的顺序表为：\n");
    			PrintList(&L);
    		   	break;
    	case 3: DeleteList(&L,3);
			    printf("删除元素后的顺序表为：\n");
			    PrintList(&L);
    		   break;
    	default:exit(0);
			}
	}
    return 0;
}
void PrintList(SqList *L)
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%d   ",L->items[i]);
    printf("\n");
}
void InitList(SqList *L)
{
    int i;
   L->length = 5;
   for(i=0;i<L->length;i++)
   {
       L->items[i]=i+1;
   }
}
void InsertList(SqList *L,int pos,int item)
{
    int i;
    if(L->length>=LISTSIZE)//判断顺序表是否已满
        printf("顺序表已满！\n");
    if(pos<=0||pos>L->length+1)//判断插入位置的合法性,如果不合法 则退出程序
        {
            printf("插入位置不合法！\n");
            exit(0);
        }
    for(i=L->length-1;i>=pos-1;i--)
        L->items[i+1]=L->items[i];
    L->items[pos-1]=item;
    L->length++;

}
void DeleteList(SqList *L,int pos)
{
    int i;
    if(L->length == 0){
            printf("线性表为空  无法删除\n");
            exit(0);
    }
    if(pos<=0||pos>L->length+1)//判断删除位置的合法性,如果不合法 则退出程序
        {
            printf("删除位置不合法！\n");
            exit(0);
        }
    for(i=pos-1;i<L->length-1;i++)
        L->items[i]=L->items[i+1];
    L->length--;
}
