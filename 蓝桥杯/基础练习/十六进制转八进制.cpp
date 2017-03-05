/*问题描述
　　给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
　　输出n行，每行为输入对应的八进制正整数。

　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。

样例输入
　　2
　　39
　　123ABC

样例输出
　　71
　　4435274

　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。*/
#include<iostream>
#include<string>
using namespace std;

int main(int argc,char **argv)
{
	char a[]="0123456789ABCDEF";
	int n,i,j,k,len,m;
	char b[410003];
	char c[110003];
	char d;
	int f[4];
	string s;
	cin>>n;
	
	for(;n>0;n--)
	{
		k=0;
		cin>>s;
		len=s.length();
		
		//16进制转换成2进制
		for(i=0;i<len;i++)
		{
			d=s[i];
			
			if(d>='0'&&d<='9')
			  m=(int)(d-'0');
			else
			  m=(int)(d-'A'+10);
			
			for(j=3;j>=0;j--)
			{
				f[j]=m%2;
				m=m/2;
			}
			for(j=0;j<4;k++,j++)
			{
				b[k]='0'+f[j];
			}
		}
		
		//转换成3的倍数
		if(len*4%3==1)
		{
			for(i=(len*4)+1;i>=2;i--)
			{
				b[i]=b[i-2];
			}
			b[1]=b[0]='0';
			len=len*4+2; 
		}
		else if(len*4%3==2)
		{
			for(i=len*4;i>=1;i--)
			{
				b[i]=b[i-1];
			}
			b[0]='0';
			len=len*4+1;
		}
		else
		{
			len=len*4;
		}
		
		//将二进制转换成八进制
		int flag=0;
		for(i=0;i<len;i+=3)
		{
			k=0;
			for(j=0;j<3;j++)
			{
				k*=2;
				k+=(int)(b[i+j]-'0');
			}
			if(k!=0) flag=1;
			
			if(flag||k)
			  cout<<k;
		}
		cout<<endl; 
	}
}

