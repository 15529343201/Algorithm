/********************************************************************* 
File Name:               5-1最小公倍数  
Author:                          date: 
Description:          问题描述 
                        　　编写一函数lcm，求两个正整数的最小公倍数。 
                        样例输入 
                        一个满足题目要求的输入范例。 
                        例： 
                        3 5 
                        样例输出 
                        与上面的样例输入对应的输出。 
                        例： 
                        3 5 
                        15 
                        数据规模和约定 
                        　　输入数据中每一个数的范围。 
                        　　例：两个数都小于65536。 
Fuction List:            
********************************************************************/ 
#include<iostream>
using namespace std;
int main()
{
	int n;
	int m;
	int i;
	int temp;
	cin>>n>>m;
	for(i=1;;i++)
	{
		if(i%n==0&&i%m==0)
		{
			break;
		}
	}
	cout<<i<<endl;
	return 0;
}
