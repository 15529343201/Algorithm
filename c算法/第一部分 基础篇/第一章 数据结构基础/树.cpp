/*
用先序序列创建一棵二叉树，并输出字符D位于二叉树的层数
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*创建一棵二叉树*/
CreatBiTree(BiTree *T){
	char c;
	scanf("%c",&c);
	if(c==' ')
	  *T=NULL;
	else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data=c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
} 

//先序遍历
PreOrderTraverse(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
} 

//中序遍历
InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历
PosOrderTraverse(BiTree T){
	if(T){
		PosOrderTraverse(T->lchild);
		PosOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
} 

visit(char c,int level){
	if(c=='D')
	  printf("%c is at %d lever of BiTree\n",c,level);
}

PreOrderTraverse1(BiTree T,int level){
	if(T){
		visit(T->data,level);
		PreOrderTraverse1(T->lchild,level+1);
		PreOrderTraverse1(T->rchild,level+1);
	}
}

int main()
{
	int level=1;
	BiTree T=NULL;
	CreatBiTree(&T);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PosOrderTraverse(T);
	printf("\n");
	PreOrderTraverse1(T,level);
	return 0;
}
/*
ABC  D  E F
ABCDEF
CBDAEF
CDBFEA
D is at 3 lever of BiTree
*/
