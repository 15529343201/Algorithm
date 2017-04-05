/*
����һ����̬��˳�������������СΪ10��������²���.
(1)����6����������ӡ��˳����е����ݣ�����ʾ����ʣ��Ŀռ����
(2)��˳����еĵ�3��λ�ò���Ԫ��0����ӡ��˳����е����ݣ�����ʾ����ʣ��Ŀռ����
(3)����ͼ������е�11��λ������0��������ʾ������Χ��
(4)ɾ�����е�6��Ԫ�أ���ӡ��˳����е����ݣ�����ʾ����ʣ��Ŀռ����
*/
#include<stdio.h>
#define MaxSize 10

/*��̬˳���ĸ��ֲ���*/

/** ��˳����в���Ԫ�� */
/** ����Sqlist:���׵�ַ */
/** ����*len:��ĳ��� */
/** ����i:����Ԫ�ص�λ�� */
/** ����x:�������Ԫ��ֵ */ 
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

/** ��˳�����ɾ��Ԫ�� */
/** ����Sqlist:���׵�ַ */
/** ����*len:��ĳ��� */
/** ����i:����Ԫ�ص�λ�� */
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
