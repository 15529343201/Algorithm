#include<stdio.h>
#include<stdlib.h>
//静态地定义一张顺序表的方法与定义一个数组的方法类似。
//可以描述如下:
#define MaxSize 100
ElemType Sqlist[MaxSize];
int len; 
//动态地生成一张顺序表的方法可描述如下:
#define MaxSize 100
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
//初始化一个顺序表
void initSqlist(Sqlist *L){
	L->elem=(int *)malloc(MaxSize*sizeof(ElemType));
	if(!L->elem)
	  exit(0);
	L->length=0;
	L->listsize=MaxSize;
} 
//动态生成一张顺序表可分为以下两步。
/*
(1)定义一个类型Sqlist,它是一个结构体，其成员包括：指向顺序表
的首地址，顺序表中表的长度(表中元素个数),顺序表的存储空间容量
(占据内存大小，以sizeof(ElemType)为单位，由MaxSize规定)
(2)通过调用一个函数initSqlist实现动态生成一张顺序表。函数
initSqlist的参数是一个Sqlist类型的指针变量，因此可以在函数
initSqlist中直接对顺序表进行操作。
*/
//向静态顺序表中插入元素
void InserElem(ElemType Sqlist[],int &n,int i,ElemType item){
	/*向顺序表Sqlist中第i个位置插入元素item，该顺序表原长度为n*/
	int t;
	if(n==MaxSize||i<1||i>n+1)
	  exit(0);//非法插入
	for(t=n-1;t>=i-1;t--)
	  Sqlist[t+1]=Sqlist[t];/*将i-1以后的元素顺序后移一个元素的位置*/
	Sqlist[i-1]=item;/*在第i个位置上插入元素item*/
	n=n+1;  
} 
//向动态顺序表中插入元素
void InsertElem(Sqlist *L,int i,ElemType item){
	ElemType *base,*insertPtr,*p;
	if(i<1||i>L->length+1)
	  exit(0);
	if(L->length>=L->listsize){
		base=(ElemType*)realloc(L->elem,(L->listsize+10)*sizeof(ElemType));
		/*重新追加空间*/
		L->elem=base;//更新内存基地址
		L->listsize=L->listsize+100;/*存储空间增大是100单元*/ 
	}
	insertPtr=&(L->elem[i-1]);/*insertPtr为插入位置*/
	for(p=&(L->elem[L->length-1]);p>=insertPtr;p--)
	  *(p+1)=*p;/*将i-1以后的元素顺序后移一个元素的位置*/
	*insertPtr=item;/*在第i个位置上插入元素item*/
	L->length++;/*表长加1*/ 
}
//删除静态顺序表的元素
void DelElem(ElemType Sqlist[],int &n,int i){
	int j;
	if(i<1||i>n)
	  exit(0);
	for(j=i;j<n;j++)
	  Sqlist[j-1]=Sqlist[j];
	n--;
} 
//删除动态顺序表的元素
void DelElem(Sqlist *L,int i){
	ElemType *delItem,*q;
	if(i<1||i>L->len)
	  exit(0);
	delItem=&(L->elem[i-1]);
	q=L->elem+L->length-1;/*q指向表尾*/
	for(++delItem;delItem<=q;++delItem){
		*(delItem-1)=*delItem;/*将第i位置以后的元素依次前移*/ 
	} 
	L->length--;/*表长减1*/ 
} 
