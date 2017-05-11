//6.72
#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;
#define MAX_TREE_SIZE 100

typedef struct CTNode{
  int child;
  struct CTNode *next;
}*ChildPtr;
typedef struct{
  TElemType data;
  ChildPtr firstchild; //孩子链表头指针
}CTBox;
typedef struct{
  CTBox nodes[MAX_TREE_SIZE];
  int n, r;
}CTree;

CTree T;

void Print_CTree(int e, int i){
	int j;
	for ( j = 1; j < i; j++ ) {
		printf( " " );
	}
	printf( "%c\n", T.nodes[e].data );
	ChildPtr p;
	for( p = T.nodes[e].firstchild; p; p = p->next )
	  Print_CTree(p->child,i+1);
}

int main( int argc, char **argv ) {
	CreatCSTree(&T);
	Print_CTree(T.r, 0);
	return 0;
}
