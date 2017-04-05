/*
创建一个静态的顺序表存放整数，大小为10，完成以下操作.
(1)输入6个整数，打印出顺序表中的内容，并显示表中剩余的空间个数
(2)在顺序表中的第3个位置插入元素0，打印出顺序表中的内容，并显示表中剩余的空间个数
(3)在试图插入表中的11个位置整数0，程序提示超出范围。
(4)删除表中第6个元素，打印出顺序表中的内容，并显示表中剩余的空间个数
*/
#include<stdio.h>
#define MaxSize 10

/*静态顺序表的各种操作*/

/** 向顺序表中插入元素 */
/** 参数Sqlist:表首地址 */
/** 参数*len:表的长度 */
/** 参数i:插入元素的位置 */
/** 参数x:待插入的元素值 */ 
void insertElem(int Sqlist[],int *len,int i,int x){
	int t;
	if(*len==MaxSize || i<1 || i>*len+1){
		printf("This insert is illegal\n");
		return;
	}
	for(t=*len-1;t>=i-1;t--)
	  Sqlist[t+1]=Sqlist[t];
	Sqlist[i-1]=x;
	*len=*len+1;
}

/** 向顺序表中删除元素 */
/** 参数Sqlist:表首地址 */
/** 参数*len:表的长度 */
/** 参数i:插入元素的位置 */
void DelElem(int Sqlist[],int *len,int i){
	int j;
	if(i<1 || i>*len){
		printf("This insert is illegal");
		return;
	}
	for(j=i;j<=*len-1;j++)
	  Sqlist[j-1]=Sqlist[j];
	*len=*len-1;
} 

int main()
{
	int Sqlist[MaxSize];
	int len;
	int i;
	for(i=0;i<6;i++)
	  scanf("%d",&Sqlist[i]);
	len=6;
	for(i=0;i<6;i++)
	  printf("%d ",Sqlist[i]);
	printf("\nThe spare length is %d\n",MaxSize-len);
	
	insertElem(Sqlist,&len,3,0);
	for(i=0;i<len;i++){
		printf("%d ",Sqlist[i]);
	}
	printf("\nThe spare length is %d\n",MaxSize-len);
	
	insertElem(Sqlist,&len,11,0);
	
	DelElem(Sqlist,&len,6); 
	for(i=0;i<len;i++)
	  printf("%d ",Sqlist[i]);
	printf("\nThe spare length is %d\n",MaxSize-len);
	return 0;
}
/*
1 2 3 4 5 6
1 2 3 4 5 6
The spare length is 4
1 2 0 3 4 5 6
The spare length is 3
This insert is illegal
1 2 0 3 4 6
The spare length is 4
*/
