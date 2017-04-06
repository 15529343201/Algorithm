//邻接表的定义
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define VertexType int
typedef struct ArcNode{
	/*单链表中的结点的类型*/
	int adjvex;/*该边指向的顶点在顺序表中的位置*/
	struct ArcNode *next;/*下一条边*/
	//infoType *weight;/*边上的权重*/ 
}ArcNode;

typedef struct VNode{
	/*顶点类型*/
	VertexType data;/*顶点中的数据信息*/
	ArcNode *firstarc;/*指向单链表，即指向第一条边*/ 
}VNode;

VNode G[MAX_VERTEX_NUM];/*VNode类型的数组G，它是图的存储容器*/
  
//图的创建
CreatGraph(int n,VNode G[]){
	int i,e;
	ArcNode *p,*q;
	printf("Input the information of the vertex\n");
	for(i=0;i<n;i++){
		//Getdata(G[i]);/*得到每个顶点中的数据*/
		scanf("%d",&G[i].data);
		G[i].firstarc=NULL;/*初始化第一条边为空*/ 
	}
	for(i=0;i<n;i++){
		printf("Creat the edges for the %dth vertex\n",i);
		scanf("%d",&e);
		while(e!=-1){
			p=(ArcNode*)malloc(sizeof(ArcNode));/*创建一条边*/
			p->next=NULL;
			p->adjvex=e;
			if(G[i].firstarc==NULL)
			  G[i].firstarc=p;/*i结点的第一条边*/
			else
			  q->next=p;/*下一条边*/
			q=p;
			scanf("%d",&e); 
		}
	}
} 

/*深度优先搜索一个连通图*/
void DFS(VNode G[],int v){
	int w;
	visit(v);/*访问当前顶点*/
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

/*广度优先遍历*/
void BFS(VNode G[],int v){
	int w;
	visit(v);/*访问顶点*/
	visited[v]=1;/*将顶点v对应的访问标记置1*/
	EnQueue(q,v);/*顶点v入队列*/
	while(!emptyQ(q)){
		DeQueue(&q,&v);/*出队列，元素由v返回*/
		w=FirstAdj(G,v);/*找到顶点v的第一个邻接点，如果无邻接点，返回-1*/
		while(w!=-1){
			if(visited[w]==0){
				visit(w);
				EnQueue(q,w);/*顶点w入队列*/
				visited[w]=1; 
			}
			w=NextAdj(G,v);/*找到顶点v的下一个邻接点，如果无邻接点，返回-1*/ 
		}
	} 
} 
/*对图G=(V,E)进行广度优先搜索的主算法*/
void Travel_BFS(VNode G[],int visited[],int n){
	int i;
	for(i=0;i<n;i++)
	  visited[i]=0;/*将标记数组初始化为0*/
	for(i=0;i<n;i++)
	  if(visited[i]==0)/*若有顶点未被访问，从该顶点开始继续广度优先搜索*/
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
