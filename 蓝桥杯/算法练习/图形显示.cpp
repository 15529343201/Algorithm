/*
问题描述
　　编写一个程序，首先输入一个整数，例如5，然后在屏幕上显示如下的图形（5表示行数）：
　　* * * * *
　　* * * *
　　* * *
　　* *
　　*
*/ 
#include<stdio.h>
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	for(i=0;i<n;i++)
	{
		for(j=n-i;j>0;j--)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
