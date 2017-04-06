//���������Ļ���
/*
��һ������n��ʾ��һϵ�е�������֮��:
n=n1+n2+......nk
������������n��һ�����֡�һ��������n���ܴ����Ų�ͬ�Ļ��֣�
����������6��ȫ���Ļ���Ϊ:
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
������Ϊ�κ�������n�Ļ����У�ֻ����һ�ֻ��ּ�n=n����������
����n������������������n�������(���ݻ��ֵĶ���,�κμ����������1)
(3)P(n,n)=P(n,n-1)+1; 
������������n�Ļ�����P(n,n)����������������n-1�Ļ�����
P(n,n-1)��������Ϊn�Ļ�����1֮�͡�
(4)P(n,m)=P(n,m-1)+P(n-m,m),n>m>1;
"������n��������������m�Ļ�����(n>m>1)"����"n��������������
m-1�Ļ�����P(n,m-1)"��"n��������Ϊm�Ļ�����"֮�͡� 
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
