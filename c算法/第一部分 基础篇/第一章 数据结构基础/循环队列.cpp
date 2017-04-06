//1.定义一个循环队列
#define MAXQSIZE 100  
typedef struct{
	ElemType *base;//循环队列的内存分配基地址
	int front;//队头
	int rear;//队尾 
}cycleQueue;

//2.初始化一个循环队列
initiQueue(cycleQueue *q){
	q->base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
	if(!q->base)
	  exit(0);
	q->front=q->rear=0;/*空队列，front和rear都指向0号单元*/ 
}

//3.入队列操作
EnQueue(cycleQueue *q,ElemType e){
	if((q->rear+1)%MAXQSIZE==q->front)/*循环队列已满*/ 
	  return;
	q->base[q->rear]=e;/*将元素e入队列，q->base为顺序表的首地址*/
	q->rear=(q->rear+1)%MAXQSIZE;/*队尾指针加1*/ 
} 

//4.出队列操作
DeQueue(cycleQueue *q,ElemType *e){
	if(q->front==q->rear)
	  return;
	*e=q->base[q->front];/*取出队头元素*/
	q->front=(q->front+1)%MAXQSIZE;/*队头指针加1*/ 
} 
