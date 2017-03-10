/*编程实现两个复数的运算。设有两个复数 和 ，则他们的运算公式为：

　　要求：（1）定义一个结构体类型来描述复数。
　　（2）复数之间的加法、减法、乘法和除法分别用不用的函数来实现。
　　（3）必须使用结构体指针的方法把函数的计算结果返回。
　　说明：用户输入：运算符号(+,-,*,/) a b c d.
　　输出：a+bi，输出时不管a,b是小于0或等于0都按该格式输出，输出时a,b都保留两位。

输入：
　　- 2.5 3.6 1.5 4.9
输出：
　　1.00+-1.30i*/
#include<stdio.h>
#include<stdlib.h>

struct  complix
{
	double a,b;
};

complix* add(complix a,complix b)
{
	complix *p=(complix*)malloc(sizeof(complix));
	p->a=a.a+b.a;
	p->b=a.b+b.b;
	return p;
}

complix* sub(complix a,complix b)
{
	complix* p=(complix*)malloc(sizeof(complix));
	p->a=a.a-b.a;
	p->b=a.b-b.b;
	return p;
}

complix* mul(complix a,complix b)
{
	complix* p=(complix*)malloc(sizeof(complix));
	p->a=a.a*b.a-a.b*b.b;
	p->b=a.a*b.b+a.b*b.a;
	return p;
}

complix* div(complix a,complix b)  
{  
    complix* p=(complix*)malloc(sizeof(complix));  
    double x=b.a*b.a+b.b*b.b;  
    p->a=(a.a*b.a+a.b*b.b)/x;  
    p->b=(a.b*b.a-a.a*b.b)/x;  
    return p;  
}  

int main()
{
	complix a,b;
	char ch;
	scanf("%c%lf%lf%lf%lf",&ch,&a.a,&a.b,&b.a,&b.b);
	complix *ans;
	switch(ch)
	{
		case '+':ans=add(a,b);break;
		case '-':ans=sub(a,b);break;
		case '*':ans=mul(a,b);break;
		case '/':ans=div(a,b);break;
	}
	printf("%.2f+%.2fi\n",ans->a,ans->b);
	return 0;
}
