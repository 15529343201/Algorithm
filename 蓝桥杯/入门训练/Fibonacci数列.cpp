/*Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。*/
#include<cstdio>
const int mod=10007;
const int MAXN=1000000+10;
int ans[MAXN];
int main()
{
	ans[1]=ans[2]=1;
	int n,i;
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
		ans[i]=(ans[i-1]+ans[i-2])%mod;
	}
	printf("%d\n",ans[n]);
	return 0;
} 
/*以下程序是求输入一个整数n,求出Fibonacci数列的第n项的值*/
#include<stdio.h>
int fib(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
	{
		return fib(n-1)+fib(n-2);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",fib(n));
	return 0;
}
