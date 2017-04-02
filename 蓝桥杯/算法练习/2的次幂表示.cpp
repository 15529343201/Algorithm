#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

void put(int num,int n){//num为当前数，n为几次方
    if(num==0)
      return;//结束条件，分解结束 
    int r=num%2;//最后一位取出来
    num=num>>1;//右移一位
	put(num,n+1);//下一位次方+1
	if(num&&r)
	  printf("+");//前面和当前位非0的时候输出'+'号 
	if(r){//当前最后一位 非0 那么输出对应的表示
	  if(n==1)
	    printf("2");
	  else{
	  	printf("2(");
	  	if(n==0)
	  	  printf("0");
	  	else
	  	  put(n,0);//次方大于等于2 时，继续分解 
	  	printf(")");
	  }
		
	}
	
}
int main()
{
	int num;
	scanf("%d",&num);
	put(num,0);//刚开始 最后一位 是0次方 
	return 0;
 } 
