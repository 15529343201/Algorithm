/*
��дһ�����򣬶�̬�Ĵ���һ��˳���Ҫ��˳���ĳ�ʼ����Ϊ10
����˳���������15����������ӡ��������ɾ��˳����еĵ�5��Ԫ�أ�
��ӡ��ɾ����Ľ����
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct{
	int *elem;
	int length;
	int listsize;
}Sqlist;

/** ��ʼ��һ��˳��� */
/** ����L:Sqlist���͵�ָ�� */
void initSqlist(Sqlist *L){
	L->elem=(int *)malloc(MaxSize*sizeof(ElemType));
	if(!L->elem)
	  exit(0);
	L->length=0;
	L->listsize=MaxSize;
} 

/** ��˳����в���Ԫ�� */
/** ����L:Sqlist���͵�ָ�� */
/** ����i:����Ԫ�ص�λ�� */
/** ����item:�����Ԫ�� */
void InsertElem(Sqlist *L,int i,ElemType item){
	/*��˳���L�е�i��λ���ϲ���Ԫ��item*/
	ElemType *base,*insertPtr,*p;
	if(i<1||i>L->length+1)
	  exit(0);
	if(L->length>=L->listsize){
		base=(ElemType*)realloc(L->elem,(L->listsize+10)*sizeof(ElemType));
		L->elem=base;
		L->listsize=L->listsize+100;
	}
	insertPtr=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=insertPtr;p--)
	  *(p+1)=*p;
	*insertPtr=item;
	L->length++;
}

/** ��˳�����ɾ��Ԫ�� */
/** ����L:Sqlist���͵�ָ�� */
/** ����i:ɾ��Ԫ�ص�λ�� */
void DelElem(Sqlist *L,int i){
	ElemType *delItem,*q;
	if(i<1||i>L->length)
	  exit(0);
	delItem=&(L->elem[i-1]);
	q=L->elem+L->length-1;
	for(++delItem;delItem<=q;++delItem)
	  *(delItem-1)=*delItem;
	L->length--;
} 

int main()
{
	Sqlist l;
	int i;
	initSqlist(&l);/*��ʼ��һ��˳���*/
	
	for(i=0;i<15;i++)
	  InsertElem(&l,i+1,i+1);
	printf("\nThe content of the list is\n");
	for(i=0;i<l.length;i++)
	  printf("%d ",l.elem[i]);
	  
	DelElem(&l,5);
	printf("\nDelete the fifth element\n");
	for(i=0;i<l.length;i++)
	  printf("%d ",l.elem[i]);
	return 0;
} 
/*

The content of the list is
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Delete the fifth element
1 2 3 4 6 7 8 9 10 11 12 13 14 15
*/
