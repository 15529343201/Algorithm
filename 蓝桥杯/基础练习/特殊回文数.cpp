/*��������
����123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
��������һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n ��
�����ʽ
��������һ�У�����һ��������n��
�����ʽ
��������С�����˳���������������������ÿ������ռһ�С�
��������
52
�������
899998
989989
998899
���ݹ�ģ��Լ��
����1<=n<=54��*/ 
#include<stdio.h>
int huiwen(int a,int n)
{
	int j=a,s=0,y;
	y=0;
	while(j!=0)//1221
	{
		y=y*10+j%10;
		s=s+j%10;
		j=j/10;
	}
	// y=1 s=1 j=122
	// y=12 s=3 j=12
	// y=122 s=5 j=1
	// y=1221 s=6 j=0
	if(y==a&&s==n)
	  return 1;
	else
	  return 0;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=10000;i<=999999;i++)
	{
		if(huiwen(i,n))
		printf("%d\n",i);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool hw(int a,int n)
{
   int y,j=a,s=0;
   y=0;
   while(j!=0)
   {
      y=y*10+j%10;
      s=s+j%10;
      j=j/10;
   }
   if(y==a&&s==n) 
     return true;
   else 
     return false;
}
int main()
{
   int n,i;
   cin>>n;
   for(i=10000;i<=999999;++i)
   if(hw(i,n)) 
   cout<<i<<endl;
   return 0;
}
