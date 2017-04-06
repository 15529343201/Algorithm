typedef struct QNode{
	QelemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//��ʼ������
initQueue(LinkQueue *q){
	/*��ʼ��һ���ն���*/
	q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
	/*����һ��ͷ��㣬��ͷ��βָ��ָ��ý��*/
	if(!q->front)
	  exit(0);
	q->front->next=NULL; 
}

//��Ӳ���
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

//�����в���
DeQueue(LinkQueue *q,ElemType *e){
	/*�������q��Ϊ�գ�ɾ��q�Ķ�ͷԪ�أ���e������ֵ*/
	if(q->front==q->rear)
	  return;
	p=q->front->next;
	*e=p->data;
	q->front->next=p->next;
	if(q->rear==p)/*�����ͷ���Ƕ�β�����޸Ķ�βָ��*/ 
	  q->rear=q->front;
	free(p);
} 

//����һ������
DestroyQueue(LinkQueue *q){
	while(q->front){
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
} 
