/*���ʵ���������������㡣������������ �� �������ǵ����㹫ʽΪ��

����Ҫ�󣺣�1������һ���ṹ������������������
������2������֮��ļӷ����������˷��ͳ����ֱ��ò��õĺ�����ʵ�֡�
������3������ʹ�ýṹ��ָ��ķ����Ѻ����ļ��������ء�
����˵�����û����룺�������(+,-,*,/) a b c d.
���������a+bi�����ʱ����a,b��С��0�����0�����ø�ʽ��������ʱa,b��������λ��

���룺
����- 2.5 3.6 1.5 4.9
�����
����1.00+-1.30i*/
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
