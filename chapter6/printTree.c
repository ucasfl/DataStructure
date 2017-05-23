//6.71 按凹表打印树
#include<stdio.h>
#include<stdlib.h>

typedef struct CSNode{
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;


int CreateBiTree(CSTree *T){
  //按先序次序输入二叉树的值，空格字符表示空树
  char ch;
  if ((ch = getchar ()) == ' '||(ch == '\n')){
    *T = NULL;
  }
  else{
    *T = (CSTree) malloc (sizeof(CSNode));
    (*T)->data = ch;
    CreateBiTree(&((*T)->nextsibling));
    CreateBiTree(&((*T)->firstchild));
  }
  return 1;
}//CreateBiTree

void printTree(CSTree T,int i){
	for ( int j = 0; j < i; j++ ) { //print blank first
		printf( "   " );
	}
	printf( "%c\n", T->data ); //print data
	for(CSTree p = T->firstchild; p ; p = p->nextsibling){
		printTree(p, i + 1); //print child
	}
}//printTree 

int CreateBiTree(CSTree *T);
void printTree(CSTree T,int i);

int main( int argc, char **argv ) {
	CSTree T;
	printf( "Create a Tree(Input mode:x xxxxxxxx...): " );
	CreateBiTree(&T);
	printTree(T,0);
	printf( "\n" );
	return 0;
}
