/*问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。
样例输入
5
8 3 6 4 9
样例输出
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
