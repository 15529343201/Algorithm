//计算整数的划分
/*
将一个整数n表示成一系列的正整数之和:
n=n1+n2+......nk
被称作正整数n的一个划分。一个正整数n可能存在着不同的划分，
例如正整数6的全部的划分为:
6=6
6=5+1
6=4+2 6=4+1+1
6=3+3 6=3+2+1 6=3+1+1+1
6=2+2+2 6=2+2+1+1 6=2+1+1+1+1
6=1+1+1+1+1+1
*/
/*
(1)P(n,1)=1,n>=1;
(2)P(n,m)=P(n,n),m>=n;
这是因为任何正整数n的划分中，只存在一种划分及n=n，其最大加数
等于n。不存在最大加数大于n的情况，(根据划分的定义,任何加数必须大于1)
(3)P(n,n)=P(n,n-1)+1; 
最大加数不大于n的划分数P(n,n)等于最大加数不大于n-1的划分数
P(n,n-1)与最大加数为n的划分数1之和。
(4)P(n,m)=P(n,m-1)+P(n-m,m),n>m>1;
"正整数n的最大加数不大于m的划分数(n>m>1)"等于"n的最大加数不大于
m-1的划分数P(n,m-1)"与"n的最大加数为m的划分数"之和。 
*/
#include<stdio.h>
int P(int n,int m){
	if(m==1||n==1) return 1;
	if(m>n) return P(n,n);
	if(m==n) return 1+P(n,m-1);
	return P(n,m-1)+P(n-m,m);
} 
int main()
{
	int n,s; 
	printf("Please input a integer for getting the number of division\n");
	scanf("%d",&n);
	s=P(n,n);
	printf("The number of division of %d is %d\n",n,s);
	return 0;
}
/*
Please input a integer for getting the number of division
6
The number of division of 6 is 11
*/
