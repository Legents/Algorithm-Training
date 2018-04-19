#include<stdio.h>
#define LISTSIZE 100
typedef struct{
    int items[LISTSIZE];
    int length;
}SqList;
void PrintList(SqList *L);//��ӡ���Ա�
void InitList(SqList *L);//��ʼ�����Ա�
void InsertList(SqList *L,int pos,int item);//�����Ա�ָ��λ�ò���ָ��Ԫ��
void DeleteList(SqList *L,int pos);//ɾ��ָ��λ�õ�Ԫ��
int main()
{
    SqList L;
    int x;
    printf("��ѡ��\n 1:��ʼ������\n 2:����Ԫ��\n 3:ɾ��Ԫ��\n 0:�˳�\n");
    while(scanf("%d",&x)&&x!=0){
    	switch(x){
		case 1: InitList(&L);
    			printf("��ʼ�����˳���Ϊ��\n");
    			PrintList(&L);
    		    break;
    	case 2: InsertList(&L,6,6);
    			printf("����Ԫ�غ��˳���Ϊ��\n");
    			PrintList(&L);
    		   	break;
    	case 3: DeleteList(&L,3);
			    printf("ɾ��Ԫ�غ��˳���Ϊ��\n");
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
    if(L->length>=LISTSIZE)//�ж�˳����Ƿ�����
        printf("˳���������\n");
    if(pos<=0||pos>L->length+1)//�жϲ���λ�õĺϷ���,������Ϸ� ���˳�����
        {
            printf("����λ�ò��Ϸ���\n");
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
            printf("���Ա�Ϊ��  �޷�ɾ��\n");
            exit(0);
    }
    if(pos<=0||pos>L->length+1)//�ж�ɾ��λ�õĺϷ���,������Ϸ� ���˳�����
        {
            printf("ɾ��λ�ò��Ϸ���\n");
            exit(0);
        }
    for(i=pos-1;i<L->length-1;i++)
        L->items[i]=L->items[i+1];
    L->length--;
}
