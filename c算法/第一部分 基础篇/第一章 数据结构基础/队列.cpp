typedef struct QNode{
	QelemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列
initQueue(LinkQueue *q){
	/*初始化一个空队列*/
	q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
	/*创建一个头结点，队头队尾指针指向该结点*/
	if(!q->front)
	  exit(0);
	q->front->next=NULL; 
}

//入队操作
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

//出队列操作
DeQueue(LinkQueue *q,ElemType *e){
	/*如果队列q不为空，删除q的队头元素，用e返回其值*/
	if(q->front==q->rear)
	  return;
	p=q->front->next;
	*e=p->data;
	q->front->next=p->next;
	if(q->rear==p)/*如果队头就是队尾，则修改队尾指针*/ 
	  q->rear=q->front;
	free(p);
} 

//销毁一个队列
DestroyQueue(LinkQueue *q){
	while(q->front){
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
} 
