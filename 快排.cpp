#include<stdio.h>
int Partition(int a[],int left,int right){
	int i=left,j=right+1;
	do{
		do{
			i++;
		}while(a[i]<a[left]);
		do{
			j--;
		}while(a[j]>a[left]);
		if(i<j){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}while(i<j);
	int t=a[left];
	a[left]=a[j];
	a[j]=t;
	return j;
}
void QuickSort(int a[],int x,int y){
    if(x<y){
        int m=Partition(a,x,y);
        QuickSort(a,x,m-1);
        QuickSort(a,m+1,y);
    }
}
int main(){
	int n,i;
	int a[100];
	printf("输入数组的长度：\n");
	scanf("%d",&n);
	printf("输入待排元素：\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n排序前的元素：\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	QuickSort(a,0,n-1);
	printf("\n排序后的元素顺序：\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	return 0;
}
