/*��������
�����Ӽ�������һ��������8λ������ʮ���������ַ���������ת��Ϊ����ʮ�������������
����ע��ʮ���������е�10~15�ֱ��ô�д��Ӣ����ĸA��B��C��D��E��F��ʾ��
��������
FFFF
�������
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

