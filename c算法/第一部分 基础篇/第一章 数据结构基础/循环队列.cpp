//1.����һ��ѭ������
#define MAXQSIZE 100  
typedef struct{
	ElemType *base;//ѭ�����е��ڴ�������ַ
	int front;//��ͷ
	int rear;//��β 
}cycleQueue;

//2.��ʼ��һ��ѭ������
initiQueue(cycleQueue *q){
	q->base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
	if(!q->base)
	  exit(0);
	q->front=q->rear=0;/*�ն��У�front��rear��ָ��0�ŵ�Ԫ*/ 
}

//3.����в���
EnQueue(cycleQueue *q,ElemType e){
	if((q->rear+1)%MAXQSIZE==q->front)/*ѭ����������*/ 
	  return;
	q->base[q->rear]=e;/*��Ԫ��e����У�q->baseΪ˳�����׵�ַ*/
	q->rear=(q->rear+1)%MAXQSIZE;/*��βָ���1*/ 
} 

//4.�����в���
DeQueue(cycleQueue *q,ElemType *e){
	if(q->front==q->rear)
	  return;
	*e=q->base[q->front];/*ȡ����ͷԪ��*/
	q->front=(q->front+1)%MAXQSIZE;/*��ͷָ���1*/ 
} 
