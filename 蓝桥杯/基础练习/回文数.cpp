/*��������
����1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
�����ʽ
��������С�����˳�����������������λʮ��������*/
#include<iostream>
using namespace std;
bool huiwen(int a)
{
	int y=0,j;
	j=a;
	while(j!=0)//1221
	{
		y=y*10+j%10;
		j/=10; 
	}
	//y=1 j=122
	//y=12 j=12
	//y=122 j=1
	//y=1221 j=0
	if(y==a)
	  return true;
	else
	  return false;
}
int main()
{
	int i;
	for(i=1000;i<=9999;i++)
	{
		if(huiwen(i))
		  cout<<i<<endl;
	}
	return 0;
}
