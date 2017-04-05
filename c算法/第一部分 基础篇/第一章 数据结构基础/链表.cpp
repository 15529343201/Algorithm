/*
��дһ������Ҫ�󣺴��ն�����һ������(����10����),��0��Ϊ������־
������һ�����������һ��������(������־0����������),��ӡ���������е�
ֵ��Ȼ��ɾ���������еĵ�5��Ԫ�أ���ӡɾ����Ľ����������ڴ����ͷ�
��������
*/
#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType; 

typedef struct node{
	ElemType data;
	struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList(int n){/*����һ����������n���ڵ�*/
    LinkList p,r,list=NULL;
    ElemType e;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&e);//�����������
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		p->next=NULL;
		if(!list)
		  list=p;//��ֵ����ͷָ��
		else
		  r->next=p;//������������� 
		r=p;
	}
	return list;
}

//�������в�����
void insertList(LinkList *list,LinkList q,ElemType e){
	LinkList p;
	p=(LinkList)malloc(sizeof(LNode));
	p->data=e;
	if(!*list){
		*list=p;//��ֵ����ͷָ��
		p->next=NULL; 
	}else{
		p->next=q->next;
		q->next=p;
	}
} 

//ɾ�������ĳ���
void delLink(LinkList *list,LinkList q){
	LinkList r;
	if(q==*list){//���ɾ����һ����� 
		*list=q->next;
		free(q);
	}else{//ɾ��������� 
		for(r=*list;r->next!=q;r=r->next);
		if(r->next!=NULL){
			r->next=q->next;
			free(q);
		}
	}
} 

//����һ������ 
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
	q=l=CreatLinkList(1);//����һ�������㣬q��lָ��ý�� 
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
	for(i=0;i<4;i++){//��ָ��qָ�������5��Ԫ�� 
		q=q->next;
	}
	delLink(&l,q);
	q=l;
	while(q){
		printf("%d ",q->data);
		q=q->next;
	}
	destroyLinkList(&l);/*�ͷŵ�������*/ 
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 0
The content of the linklist
1 2 3 4 5 6 7 8 9
Delete the fifth element
1 2 3 4 6 7 8 9
*/
