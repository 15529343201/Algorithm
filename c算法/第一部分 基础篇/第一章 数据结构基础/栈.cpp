//定义一个栈
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;

//创建一个栈
#define STACK_INIT_SIZE 100
initStack(sqStack *s){
	/*内存中开辟一段连续空间作为栈空间，首地址赋值给s->base*/
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	  exit(0);/*空间分配失败*/
	s->top=s->base;/*最开始，栈顶就是栈底*/
	s->stacksize=STACK_INIT_SIZE;/*最大容量为STACK_INIT_SIZE*/ 
} 

//入栈操作
#define STACKINCREMENT 10
Push(sqStack *s,ElemType e){
	if(s->top-s->base>=s->stacksize){
		/*栈满，追加空间*/
		s->base=(ElemType*)realloc(s->base,(s->stacksize
		  +STACKINCREMENT)*sizeof(ElemType));
		if(!s->base)
		  exit(0);
		s->top=s->base+s->stacksize;
		s->stacksize=s->stacksize+STACKINCREMENT;/*设置栈的最大容量*/
	}
	*(s->top)=e;
	s->top++;
} 

//出栈操作
Pop(sqStack *s,ElemType *e){
	if(s->top==s->base)
	  return;
	*e=*--(s->top);
} 

/*栈的其他操作*/
//1.清空一个栈
ClearStack(sqStack *s){
	s->top=s->base;
} 

//2.销毁一个栈
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

//3.计算栈的当前容量
int StackLen(sqStack s){
	return (s.top-s.base);
} 
