/*
���ڽӱ�洢����ʽ����һ������ͼ����Ӧ��������������ķ�������
��ͼ�е�ÿ���ڵ㣬��ӡ��ÿ�������а���������
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{
	int data;
	ArcNode *firstarc;
}VNode;

VNode G[MAX_VERTEX_NUM];
int visited[5]={0,0,0,0,0};

CreatGraph(int n,VNode G[]){
	int i,e;
	ArcNode *p,*q;
	printf("Input the information of the vertex\n");
	for(i=0;i<n;i++){
		scanf("%d",&G[i]);
		G[i].firstarc=NULL; 
	}
	for(i=0;i<n;i++){
		printf("Create the edges for the %dth vertex\n",i);
		scanf("%d",&e);
		while(e!=-1){
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->next=NULL;
			p->adjvex=e;
			if(G[i].firstarc==NULL)
			  G[i].firstarc=p;
			else
			  q->next=p;
			q=p;
			scanf("%d",&e);
		}
	}
}

int FirstAdj(VNode G[],int v){
	if(G[v].firstarc!=NULL) 
	  return (G[v].firstarc)->adjvex;
	return -1;
}

int NextAdj(VNode G[],int v){
	ArcNode *p;
	p=G[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex])
		  p=p->next;
		else
		  return p->adjvex;
	}
	return -1;
}

//void DFS(VNode G[],int v){
//	int w;
//	printf("%d ",G[v]);/*���ʵ�ǰ���㣬��ӡ���ö����е�������Ϣ*/
//	visited[v]=1;
//	w=FirstAdj(G,v);
//	while(w!=-1){
//		if(visited[w]==0)
//		  DFS(G,w);
//		w=NextAdj(G,v);
//	} 
//}

void DFS(VNode G[],int v){
	int w;
	printf("%d",G[v]);/*���ʵ�ǰ����*/
	visited[v]=1;/*������v��Ӧ�ķ��ʱ����1*/
	w=FirstAdj(G,v);/*�ҵ�����v�ĵ�һ���ڽӵ㣬��������㣬����-1*/
	while(w!=-1){
		if(visited[w]==0)/*�ö���δ������*/
		DFS(G,w);/*�ݹ�Ľ��������������*/
		w=NextAdj(G,v);/*�ҵ�����v����һ���ڽӵ㣬������ڽӵ㣬����-1*/
	}
} 
/*��ͼG=(V,E)����������ȱ������������㷨*/
void Travel_DFS(VNode G[],int visited[],int n){
	int i;
	for(i=0;i<n;i++)
	  visited[i]=0;/*����������ʼ��Ϊ0*/
	for(i=0;i<n;i++)
	  if(visited[i]==0)/*���ж���δ�����ʣ��Ӹö��㿪ʼ���������������*/
	    DFS(G,i); 
} 

int main()
{
	VNode G[5];
	CreatGraph(5,G);
	Travel_DFS(G,visited,5);
	return 0;
}
