/*
编写一个程序，要求：从终端输入一组整数(大于10个数),以0作为结束标志
，将这一组整数存放在一个链表中(结束标志0不包括在内),打印出该链表中的
值。然后删除该链表中的第5个元素，打印删除后的结果。最后在内存中释放
掉该链表。
*/
#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType; 

typedef struct node{
	ElemType data;
	struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList(int n){/*创建一个链表，包含n个节点*/
    LinkList p,r,list=NULL;
    ElemType e;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&e);//输入结点的内容
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		p->next=NULL;
		if(!list)
		  list=p;//赋值链表头指针
		else
		  r->next=p;//将结点连入链表 
		r=p;
	}
	return list;
}

//向链表中插入结点
void insertList(LinkList *list,LinkList q,ElemType e){
	LinkList p;
	p=(LinkList)malloc(sizeof(LNode));
	p->data=e;
	if(!*list){
		*list=p;//赋值链表头指针
		p->next=NULL; 
	}else{
		p->next=q->next;
		q->next=p;
	}
} 

//删除链表的某结点
void delLink(LinkList *list,LinkList q){
	LinkList r;
	if(q==*list){//如果删除第一个结点 
		*list=q->next;
		free(q);
	}else{//删除其他结点 
		for(r=*list;r->next!=q;r=r->next);
		if(r->next!=NULL){
			r->next=q->next;
			free(q);
		}
	}
} 

//销毁一个链表 
void destroyLinkList(LinkList *list){
	LinkList p,q;
	p=*list;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	*list=NULL;
}
int main()
{
	int e,i;
	LinkList l,q;
	q=l=CreatLinkList(1);//创建一个链表结点，q和l指向该结点 
	scanf("%d",&e);
	while(e){
		insertList(&l,q,e);
		q=q->next;
		scanf("%d",&e);
	}
	q=l;
	printf("The content of the linklist\n");
	while(q){
		printf("%d ",q->data);
		q=q->next;
	}
	q=l;
	printf("\nDelete the fifth element\n");
	for(i=0;i<4;i++){//将指针q指向链表第5个元素 
		q=q->next;
	}
	delLink(&l,q);
	q=l;
	while(q){
		printf("%d ",q->data);
		q=q->next;
	}
	destroyLinkList(&l);/*释放掉该链表*/ 
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 0
The content of the linklist
1 2 3 4 5 6 7 8 9
Delete the fifth element
1 2 3 4 6 7 8 9
*/
