//����װ������
/*
��һ����װ��Ҫװ��һ��������ΪC�Ļ����У�ÿ����װ����������û��Լ�
����ָ�����ڻ�����װ��������޵�ǰ���£����װ�ؼ�װ����ܾ�����
��ؽ���װ��װ�������
*/
/*
������㷨ʱ������һ������w[]���ÿ����װ�������������w[2]=5,
�ͱ�ʾ��2����װ�������Ϊ5��������һ����������x[]��ż�װ���ȡ��
״̬�����У�x[i]=1��ʾ����i����װ����봬�У�x[i]=0��ʾ��i����װ��
��װ���������������Ľ��Ӧ������������x[]���±ꡣ
    Ӧ��̰���㷨��⣬ÿ�ζ�Ҫѡ������w[]�е�ǰ���������(w[i]ֵ��С��)
��װ�䣬����x[i]��1��ͬʱc=c-w[i],������c�д�Ż�����ʣ����������
c�����ֵΪ��������C.ѭ��ִ�����ϲ�����ֱ��w[i]<=c,���������Ѵﵽ�����
���������߼�װ��ȫ��װ��Ϊֹ��
*/
#include<stdio.h>
#include<stdlib.h>
void sort(int w[],int t[],int n){
	int i,j,tmp;
	int *w_tmp=(int*)malloc(sizeof(int)*n);
	/*��̬����һ����ʱ���飬���w[]�е����ݣ���������*/
	for(i=0;i<n;i++)
	  t[i]=i;/*��ʼ������*/
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
	/*��̬����һ����ʱ���飬���w[]���±꣬���t[i],t[j],i<j,��w[i]<=w[j]*/
	sort(w,t,n); //����������t[]���w[]���±�
	for(i=0;i<n;i++)
	  x[i]=0;
	for(i=0;i<n&&w[t[i]]<=c;i++){
		x[t[i]]=1;//����t[i]����װ��װ�봬��
		c=c-w[t[i]];//����c�д�Ż�����ʣ�������� 
	} 
}
int main()
{
	int x[5],w[5],c,i;
	printf("Please input the maximum loading of the sheeep\n");
	scanf("%d",&c);/*������������������*/
	printf("Please input the weight of FIVE box\n");
	for(i=0;i<5;i++)//����ÿ����װ�������
	  scanf("%d",&w[i]);
	Loading(x,w,c,5);//��������װ��
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
