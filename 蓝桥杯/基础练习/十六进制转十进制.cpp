/*问题描述
　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
FFFF
样例输出
65535*/
#include<stdio.h>
int main()
{
	int a;
	scanf("%x",&a);
	printf("%u",a);
	return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	long long sum=0;
	string a;
	cin>>a;//FFFF
	int b;
	b=a.length();
	
	for(int i=0;i<b;i++)
	{
		if(a[i]>='A'&&a[i]<='F')
		{
			sum=sum*16+a[i]-'A'+10;
			//sum=F
			//sum=F*16+15
			//sum=(F*16+15)*16+15
			//sum=.......
		}
		else
		{
			sum=sum*16+a[i]-'0';
		}
	}
	cout<<sum<<endl;
	return 0;
 } 

