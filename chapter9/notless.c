//9.33 output all the key value which not less than given value x
#include<stdio.h>
#include<stdlib.h>

typedef struct BiTreeNode{
	int data;
	struct BiTreeNode *lchild, *rchild;
}BiTreeNode, *BiTree;

int Search(BiTree T, int k, BiTree f, BiTree *p); //search if k in T
int InsertBiTree(BiTree *T, int k ); //create a BiTree
void output(BiTree T, int x); //output the all key value which not less than x

int main( int argc, char **argv ) {
	int n, x, k;
	printf( "Input the record number: " );
	scanf("%d", &n);
	
	BiTree T = NULL;
	printf( "Input records: " );
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &k);
		InsertBiTree(&T, k);
	}
	printf( "Input the search key: " );
	scanf("%d", &x);
	printf( "Output all the record which not less key:\n" );
	output(T, x);
	printf( "\n" );
	return 0;
}

int Search(BiTree T, int k, BiTree f, BiTree *p){
	if( !T ){
		*p =f;
		return 0; //k is not in T
	}
	else if ( k == T->data ){
		*p = T;
		return 1; // k in T
	}
	else if( k > T->data ) //search in right child
	  return Search( T->rchild, k, T, p );
	else //search in left child
	  return Search( T->lchild, k, T, p );
	return 1;
}

int InsertBiTree(BiTree *T, int k){
	BiTree p, s;
	if (!Search(*T, k, NULL, &p)){
		s = (BiTree) malloc (sizeof(BiTreeNode));
		s->data = k;
		s->lchild = s->rchild = NULL;
		if(!*T)
		  *T = s;//insert s as the root node
		else if(p->data < s->data)
		  p->rchild = s;// insert s as the right child of p;
		else //insert s as the left child of p
		  p->lchild = s;
		return 1;
	}
	else
	  return 0;
}

void output(BiTree T, int x){ //recusive output all the key value not less than x
	if (!T)
	  return;
	else if( T->data < x )
	  output( T->rchild, x );
	else if (T->data == x){
		printf( "%d ", T->data );
		output( T->rchild, x );
	}
	else{
		printf( "%d ", T->data );
		output(T->lchild, x);
		output(T->rchild, x);
	}
}

