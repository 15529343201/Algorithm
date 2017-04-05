//利用栈的数据结构，将二进制数转换为十进制数
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;

initStack(sqStack *s){
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	  exit(0);
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE; 
}

Push(sqStack *s,ElemType e){
	if(s->top-s->base>=s->stacksize){
		s->base=(ElemType*)realloc(s->base,(s->stacksize
		  +STACKINCREMENT)*sizeof(ElemType));
		if(!s->base)
		  exit(0);
		s->top=s->base+s->stacksize;
		s->stacksize=s->stacksize+STACKINCREMENT;
	}
	*(s->top)=e;
	s->top++;
}

Pop(sqStack *s,ElemType *e){
	if(s->top==s->base)
	  exit(0);
	*e=*--(s->top);
}

int StackLen(sqStack s){
	return (s.top-s.base);
}

int main()
{
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	printf("Please input a Binary digit\n");
	initStack(&s);/*创建一个栈，用来存放二进制字符串*/
	/*输入0/1字符表示的二进制数，以#结束*/
	scanf("%c",&c);
	while(c!='#'){
		Push(&s,c);
		scanf("%c",&c);
	} 
	getchar();
	len=StackLen(s);
	
	for(i=0;i<len;i++){
		Pop(&s,&c);
		sum=sum+(c-48)*pow(2,i);
	}
	printf("Decimal is %d\n",sum);
	return 0; 
}
/*
Please input a Binary digit
10010101#
Decimal is 149
*/
