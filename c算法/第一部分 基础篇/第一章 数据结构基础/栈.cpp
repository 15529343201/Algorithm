//����һ��ջ
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;

//����һ��ջ
#define STACK_INIT_SIZE 100
initStack(sqStack *s){
	/*�ڴ��п���һ�������ռ���Ϊջ�ռ䣬�׵�ַ��ֵ��s->base*/
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	  exit(0);/*�ռ����ʧ��*/
	s->top=s->base;/*�ʼ��ջ������ջ��*/
	s->stacksize=STACK_INIT_SIZE;/*�������ΪSTACK_INIT_SIZE*/ 
} 

//��ջ����
#define STACKINCREMENT 10
Push(sqStack *s,ElemType e){
	if(s->top-s->base>=s->stacksize){
		/*ջ����׷�ӿռ�*/
		s->base=(ElemType*)realloc(s->base,(s->stacksize
		  +STACKINCREMENT)*sizeof(ElemType));
		if(!s->base)
		  exit(0);
		s->top=s->base+s->stacksize;
		s->stacksize=s->stacksize+STACKINCREMENT;/*����ջ���������*/
	}
	*(s->top)=e;
	s->top++;
} 

//��ջ����
Pop(sqStack *s,ElemType *e){
	if(s->top==s->base)
	  return;
	*e=*--(s->top);
} 

/*ջ����������*/
//1.���һ��ջ
ClearStack(sqStack *s){
	s->top=s->base;
} 

//2.����һ��ջ
DestroyStack(sqStack *s){
	int i,ken;
	len=s->stacksize;
	for(i=0;i<len;i++){
		free(s->base);
		s->base++;
	}
	s->base=s->top=NULL;
	s->stacksize=0;
} 

//3.����ջ�ĵ�ǰ����
int StackLen(sqStack s){
	return (s.top-s.base);
} 
