/*
用邻接表存储的形式创建一棵无向图，并应用深度优先搜索的方法遍历
该图中的每个节点，打印出每个顶点中包含的数据
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
//	printf("%d ",G[v]);/*访问当前顶点，打印出该顶点中的数据信息*/
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
	printf("%d",G[v]);/*访问当前顶点*/
	visited[v]=1;/*将顶点v对应的访问标记置1*/
	w=FirstAdj(G,v);/*找到顶点v的第一个邻接点，如果无领结点，返回-1*/
	while(w!=-1){
		if(visited[w]==0)/*该顶点未被访问*/
		DFS(G,w);/*递归的进行深度优先搜索*/
		w=NextAdj(G,v);/*找到顶点v的下一个邻接点，如果无邻接点，返回-1*/
	}
} 
/*对图G=(V,E)进行深度优先遍历搜索的主算法*/
void Travel_DFS(VNode G[],int visited[],int n){
	int i;
	for(i=0;i<n;i++)
	  visited[i]=0;/*将标记数组初始化为0*/
	for(i=0;i<n;i++)
	  if(visited[i]==0)/*若有顶点未被访问，从该顶点开始继续深度优先搜索*/
	    DFS(G,i); 
} 

int main()
{
	VNode G[5];
	CreatGraph(5,G);
	Travel_DFS(G,visited,5);
	return 0;
}
