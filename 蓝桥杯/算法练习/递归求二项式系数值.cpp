/*��������
һ��������ĿҪ������뷶����
3 10
�������
����������������Ӧ�������
120
���ݹ�ģ��Լ��
��������������ÿһ�����ķ�Χ��
�������������int��ʾʱ���������
*/
#include<stdio.h>
int pailie(int a,int b)
{
	if(a==0||a==b)
	{
		return 1;
	}
	else
	{
		return pailie(a,b-1)+pailie(a-1,b-1);
	}
}
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	printf("%d",pailie(k,n));
	return 0;
}
