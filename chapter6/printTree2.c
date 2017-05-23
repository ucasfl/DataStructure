//6.72
#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;
#define MAX_TREE_SIZE 100

typedef struct CTNode{
  int child;
  struct CTNode *next;
}*ChildPtr,CTNode;
typedef struct{
  TElemType data;
  ChildPtr firstchild; //孩子链表头指针
}CTBox;
typedef struct{
  CTBox nodes[MAX_TREE_SIZE];
  int n, r;
}CTree;

CTree T;

void CreatCSTree(CTree *T){ //构造一棵如课本6.14(a)所示的孩子链表存储的树
	int i;
	for ( i = 0; i < 4; i++ ) {//初始化
		T->nodes[i].data = 'A' + i;
		T->nodes[i].firstchild = NULL;
	}
	for(i = 5; i < 10; i++){
		T->nodes[i].data = 'E' + i-5;
		T->nodes[i].firstchild = NULL;
	}
	T->nodes[9].data = 'K';
	T->nodes[4].data = 'R';
	T->nodes[4].firstchild = NULL;

	T->nodes[0].firstchild = (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[0].firstchild->child = 3;
	T->nodes[0].firstchild->next = (ChildPtr) malloc(sizeof(CTNode));
	T->nodes[0].firstchild->next->child = 5;
	T->nodes[0].firstchild->next->next= NULL;

	T->nodes[2].firstchild = (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[2].firstchild->child = 6;
	T->nodes[2].firstchild->next = NULL;

	T->nodes[4].firstchild = (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[4].firstchild->child = 0;
	T->nodes[4].firstchild->next = (ChildPtr) malloc(sizeof(CTNode));
	T->nodes[4].firstchild->next->child = 1;
	T->nodes[4].firstchild->next->next= (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[4].firstchild->next->next->child = 2;
	T->nodes[4].firstchild->next->next->next = NULL;

	T->nodes[6].firstchild = (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[6].firstchild->child = 7;
	T->nodes[6].firstchild->next = (ChildPtr) malloc(sizeof(CTNode));
	T->nodes[6].firstchild->next->child = 8;
	T->nodes[6].firstchild->next->next= (ChildPtr) malloc (sizeof(CTNode));
	T->nodes[6].firstchild->next->next->child = 9;
	T->nodes[6].firstchild->next->next->next = NULL;

	T->n = 10;
	T->r = 4;
}

void Print_CTree(int e, int i){
	int j;
	for ( j = 0; j < i; j++ ) {
		printf( "   " );
	}
	printf( "%c\n", T.nodes[e].data );
	ChildPtr p;
	for( p = T.nodes[e].firstchild; p; p = p->next )
	  Print_CTree(p->child,i+1);
}

void CreatCSTree(CTree *T);
void Print_CTree(int e, int i);

int main( int argc, char **argv ) {
	CreatCSTree(&T);
	Print_CTree(T.r, 0);
	return 0;
}
