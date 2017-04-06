//最优装船问题
/*
有一批集装箱要装入一个载质量为C的货船中，每个集装箱的质量由用户自己
输入指定，在货船的装载体积不限的前提下，如何装载集装箱才能尽可能
多地将集装箱装入货船中
*/
/*
在设计算法时，可用一个数组w[]存放每个集装箱的质量，例如w[2]=5,
就表示第2个集装箱的质量为5。在设置一个向量数组x[]存放集装箱的取舍
状态。其中，x[i]=1表示将第i个集装箱放入船中，x[i]=0表示第i个集装箱
不装入货船。最终输出的结果应当是向量数组x[]的下标。
    应用贪心算法求解，每次都要选出数组w[]中当前质量最轻的(w[i]值最小的)
集装箱，并将x[i]置1，同时c=c-w[i],及变量c中存放货船的剩余载质量，
c的最初值为货船质量C.循环执行以上操作，直到w[i]<=c,表明货船已达到最大载
质量，或者集装箱全部装完为止。
*/
#include<stdio.h>
#include<stdlib.h>
void sort(int w[],int t[],int n){
	int i,j,tmp;
	int *w_tmp=(int*)malloc(sizeof(int)*n);
	/*动态开辟一个临时数组，存放w[]中的内容，用于排序*/
	for(i=0;i<n;i++)
	  t[i]=i;/*初始化数组*/
	for(i=0;i<n;i++)
	  w_tmp[i]=w[i];
	for(i=0;i<n-1;i++)
	  for(j=0;j<n-i-1;j++)
	    if(w_tmp[j]>w_tmp[j+1]){
	    	tmp=w_tmp[j];
	    	w_tmp[j]=w_tmp[j+1];
	    	w_tmp[j+1]=tmp;
	    	tmp=t[j];
	    	t[j]=t[j+1];
	    	t[j+1]=tmp;
		} 
}
void Loading(int x[],int w[],int c,int n){
	int i,s=0;
	int *t=(int*)malloc(sizeof(int)*n);
	/*动态开辟一个临时数组，存放w[]的下标，如果t[i],t[j],i<j,则w[i]<=w[j]*/
	sort(w,t,n); //排序，用数组t[]存放w[]的下标
	for(i=0;i<n;i++)
	  x[i]=0;
	for(i=0;i<n&&w[t[i]]<=c;i++){
		x[t[i]]=1;//将第t[i]个集装箱装入船中
		c=c-w[t[i]];//变量c中存放货船的剩余载质量 
	} 
}
int main()
{
	int x[5],w[5],c,i;
	printf("Please input the maximum loading of the sheeep\n");
	scanf("%d",&c);/*输入货船的最大载质量*/
	printf("Please input the weight of FIVE box\n");
	for(i=0;i<5;i++)//输入每个集装箱的质量
	  scanf("%d",&w[i]);
	Loading(x,w,c,5);//进行最优装载
	printf("The following boxes will be loaded\n");
	for(i=0;i<5;i++)
	  if(x[i]==1)
	    printf("BOX:%d ",i);
	return 0; 
}	 
/*
Please input the maximum loading of the sheeep
13
Please input the weight of FIVE box
5 7 6 3 2
The following boxes will be loaded
BOX:0 BOX:3 BOX:4
*/ 
