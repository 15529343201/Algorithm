//�ڽӱ�Ķ���
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define VertexType int
typedef struct ArcNode{
	/*�������еĽ�������*/
	int adjvex;/*�ñ�ָ��Ķ�����˳����е�λ��*/
	struct ArcNode *next;/*��һ����*/
	//infoType *weight;/*���ϵ�Ȩ��*/ 
}ArcNode;

typedef struct VNode{
	/*��������*/
	VertexType data;/*�����е�������Ϣ*/
	ArcNode *firstarc;/*ָ��������ָ���һ����*/ 
}VNode;

VNode G[MAX_VERTEX_NUM];/*VNode���͵�����G������ͼ�Ĵ洢����*/
  
//ͼ�Ĵ���
CreatGraph(int n,VNode G[]){
	int i,e;
	ArcNode *p,*q;
	printf("Input the information of the vertex\n");
	for(i=0;i<n;i++){
		//Getdata(G[i]);/*�õ�ÿ�������е�����*/
		scanf("%d",&G[i].data);
		G[i].firstarc=NULL;/*��ʼ����һ����Ϊ��*/ 
	}
	for(i=0;i<n;i++){
		printf("Creat the edges for the %dth vertex\n",i);
		scanf("%d",&e);
		while(e!=-1){
			p=(ArcNode*)malloc(sizeof(ArcNode));/*����һ����*/
			p->next=NULL;
			p->adjvex=e;
			if(G[i].firstarc==NULL)
			  G[i].firstarc=p;/*i���ĵ�һ����*/
			else
			  q->next=p;/*��һ����*/
			q=p;
			scanf("%d",&e); 
		}
	}
} 

/*�����������һ����ͨͼ*/
void DFS(VNode G[],int v){
	int w;
	visit(v);/*���ʵ�ǰ����*/
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

/*������ȱ���*/
void BFS(VNode G[],int v){
	int w;
	visit(v);/*���ʶ���*/
	visited[v]=1;/*������v��Ӧ�ķ��ʱ����1*/
	EnQueue(q,v);/*����v�����*/
	while(!emptyQ(q)){
		DeQueue(&q,&v);/*�����У�Ԫ����v����*/
		w=FirstAdj(G,v);/*�ҵ�����v�ĵ�һ���ڽӵ㣬������ڽӵ㣬����-1*/
		while(w!=-1){
			if(visited[w]==0){
				visit(w);
				EnQueue(q,w);/*����w�����*/
				visited[w]=1; 
			}
			w=NextAdj(G,v);/*�ҵ�����v����һ���ڽӵ㣬������ڽӵ㣬����-1*/ 
		}
	} 
} 
/*��ͼG=(V,E)���й���������������㷨*/
void Travel_BFS(VNode G[],int visited[],int n){
	int i;
	for(i=0;i<n;i++)
	  visited[i]=0;/*����������ʼ��Ϊ0*/
	for(i=0;i<n;i++)
	  if(visited[i]==0)/*���ж���δ�����ʣ��Ӹö��㿪ʼ���������������*/
	    BFS(G,i); 
} 
int main()
{
	VNode G[3];
	CreatGraph(3,G);
}
/*
Input the information of the vertex
0 1 2
Creat the edges for the 0th vertex
2 -1
Creat the edges for the 1th vertex
0 2 -1
Creat the edges for the 2th vertex
-1
*/
