/*样例输入
一个满足题目要求的输入范例。
3 10
样例输出
与上面的样例输入对应的输出。
120
数据规模和约定
　　输入数据中每一个数的范围。
　　例：结果在int表示时不会溢出。
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
