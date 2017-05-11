//6.43交换二叉树的左右子树
#include<stdio.h>
#include<stdlib.h>

#define Ok 1
#define ERROR 0

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;

int CreateBiTree(BiTree *T){
  //按先序次序输入二叉树的值，空格字符表示空树
  char ch;
  if ((ch = getchar ()) == ' '||(ch == '\n')){
    *T = NULL;
  }
  else{
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
  }
  return 1;
}//CreateBiTree

void PrintTree(BiTree T){
	if(T){
		printf( "%c\t",T->data );
		PrintTree( T->lchild );
		PrintTree( T->rchild );
	}
}

void changeL_R(BiTree *T){
	if(*T){
		BiTree p;
		p = (*T)->rchild;
		(*T)->rchild = (*T)->lchild;
		(*T)->lchild = p;
		changeL_R(&((*T)->rchild));
		changeL_R(&((*T)->lchild));
	}
}

int main( int argc, char **argv ) {
	BiTree T;
	printf( "Create a Tree: " );
	CreateBiTree(&T);

	printf( "Before exchange lchild and rchild:\n" );
	PrintTree(T);
	printf( "\n" );
	
	printf( "After exchange lchild and rchild:\n"); 
	changeL_R(&T);
	PrintTree(T);
	printf( "\n" );
	return 0;
}
