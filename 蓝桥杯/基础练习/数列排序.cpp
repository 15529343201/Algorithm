/*��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ
������һ��Ϊһ������n��
�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ
�������һ�У�����С�����˳��������������С�
��������
5
8 3 6 4 9
�������
3 4 6 8 9*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200+10;
int a[MAXN];
int main()
{
	int n; 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int j=0;j<n;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
	return 0;
} 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc,char *argv[])
{
	int n,val;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		v.push_back(val);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
