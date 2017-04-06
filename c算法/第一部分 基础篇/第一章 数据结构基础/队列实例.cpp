/*
实现一个链队列，任意输入一串字符，以@为结束标志，然后将队列中
的元素逐一取出，打印在屏幕上。
*/
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化一个队列
initQueue(LinkQueue *q){
	q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!q->front)
	  exit(0);
	q->front->next=NULL;
} 

EnQueue(LinkQueue *q,ElemType e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!q->front)
      exit(0);
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

DeQueue(LinkQueue *q,ElemType *e){
	QueuePtr p;
	if(q->front==q->rear)
	  exit(0);
	p=q->front->next;
	*e=p->data;
	q->front->next=p->next;
	if(q->rear==p)
	  q->rear=q->front;/*如果队头就是队尾，则修改队尾指针*/
	free(p); 
}

int main()
{
	ElemType e;
	LinkQueue q;
	initQueue(&q);
	printf("Please input a string into a queue\n");
	scanf("%c",&e);
	while(e!='@'){
		EnQueue(&q,e);
		scanf("%c",&e);
	}
	printf("The string into the queue is\n");
	while(q.front!=q.rear){
		DeQueue(&q,&e);
		printf("%c",e);
	}
	printf("\n");
	return 0;
}
/*
Please input a string into a queue
This is a test: Hello world!@
The string into the queue is
This is a test: Hello world!
*/
