#include<stdio.h>
#include<stdlib.h>
//��̬�ض���һ��˳���ķ����붨��һ������ķ������ơ�
//������������:
#define MaxSize 100
ElemType Sqlist[MaxSize];
int len; 
//��̬������һ��˳���ķ�������������:
#define MaxSize 100
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
//��ʼ��һ��˳���
void initSqlist(Sqlist *L){
	L->elem=(int *)malloc(MaxSize*sizeof(ElemType));
	if(!L->elem)
	  exit(0);
	L->length=0;
	L->listsize=MaxSize;
} 
//��̬����һ��˳���ɷ�Ϊ����������
/*
(1)����һ������Sqlist,����һ���ṹ�壬���Ա������ָ��˳���
���׵�ַ��˳����б�ĳ���(����Ԫ�ظ���),˳���Ĵ洢�ռ�����
(ռ���ڴ��С����sizeof(ElemType)Ϊ��λ����MaxSize�涨)
(2)ͨ������һ������initSqlistʵ�ֶ�̬����һ��˳�������
initSqlist�Ĳ�����һ��Sqlist���͵�ָ���������˿����ں���
initSqlist��ֱ�Ӷ�˳�����в�����
*/
//��̬˳����в���Ԫ��
void InserElem(ElemType Sqlist[],int &n,int i,ElemType item){
	/*��˳���Sqlist�е�i��λ�ò���Ԫ��item����˳���ԭ����Ϊn*/
	int t;
	if(n==MaxSize||i<1||i>n+1)
	  exit(0);//�Ƿ�����
	for(t=n-1;t>=i-1;t--)
	  Sqlist[t+1]=Sqlist[t];/*��i-1�Ժ��Ԫ��˳�����һ��Ԫ�ص�λ��*/
	Sqlist[i-1]=item;/*�ڵ�i��λ���ϲ���Ԫ��item*/
	n=n+1;  
} 
//��̬˳����в���Ԫ��
void InsertElem(Sqlist *L,int i,ElemType item){
	ElemType *base,*insertPtr,*p;
	if(i<1||i>L->length+1)
	  exit(0);
	if(L->length>=L->listsize){
		base=(ElemType*)realloc(L->elem,(L->listsize+10)*sizeof(ElemType));
		/*����׷�ӿռ�*/
		L->elem=base;//�����ڴ����ַ
		L->listsize=L->listsize+100;/*�洢�ռ�������100��Ԫ*/ 
	}
	insertPtr=&(L->elem[i-1]);/*insertPtrΪ����λ��*/
	for(p=&(L->elem[L->length-1]);p>=insertPtr;p--)
	  *(p+1)=*p;/*��i-1�Ժ��Ԫ��˳�����һ��Ԫ�ص�λ��*/
	*insertPtr=item;/*�ڵ�i��λ���ϲ���Ԫ��item*/
	L->length++;/*����1*/ 
}
//ɾ����̬˳����Ԫ��
void DelElem(ElemType Sqlist[],int &n,int i){
	int j;
	if(i<1||i>n)
	  exit(0);
	for(j=i;j<n;j++)
	  Sqlist[j-1]=Sqlist[j];
	n--;
} 
//ɾ����̬˳����Ԫ��
void DelElem(Sqlist *L,int i){
	ElemType *delItem,*q;
	if(i<1||i>L->len)
	  exit(0);
	delItem=&(L->elem[i-1]);
	q=L->elem+L->length-1;/*qָ���β*/
	for(++delItem;delItem<=q;++delItem){
		*(delItem-1)=*delItem;/*����iλ���Ժ��Ԫ������ǰ��*/ 
	} 
	L->length--;/*����1*/ 
} 
