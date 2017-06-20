#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MMAX 200

typedef struct BiTreeNode{
	int number;
	int data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode, *BiTree;

void join(BiTree *T, int key[], int first, int last); //use a sorted array key[] to create a balanced tree
void split(BiTree T, BiTree *T1, BiTree *T2, int x); //split a balanced tree into two balanced tree
int inorder(BiTree T, int key[], int *last, int restore); //inorder traverse a balanced tree to get the record list
int preorder(BiTree T); //preorder traverse a tree
int get_index_x(int key[], int last, int x, int *index_x); //get the index of x in array key
void merge_array(int key[], int key1[], int key2[], int len1, int len2, int *last); //merge two sorted array into one sorted array
void merge_tree(BiTree *T, BiTree T1, BiTree T2);  //merge two balanced tree into one balanced tree

void merge_tree(BiTree *T, BiTree T1, BiTree T2){ 
	int key[MMAX], key1[MAX], key2[MAX];
	int len1, len2, last;
    //get lists
	inorder(T1, key1, &len1, 0);
	inorder(T2, key2, &len2, 0);
   //merge lists
	merge_array(key, key1, key2, len1, len2, &last);
	join(T, key, 0, last); //create tree
}//merge_tree

void merge_array(int key[], int key1[], int key2[], int len1, int len2, int *last){
	int i, j, k ;
	key[0] = (key1[0] < key2[0])?key1[0]:key2[0];//get the first value 
	
	for(i = 0, j = 0, k = 1; i <= len1 && j <= len2; ){ //merge lists
		if (key1[i] < key2[j] ){
			if (key1[i] != key[k-1])
			  key[k++] = key1[i++];
			else
			  i ++;
		}
		else {
			if (key2[j] != key[k-1])
			  key[k++] = key2[j++];
			else
			  j ++;
		}
	}

	if (i <= len1){  //merge remain record of key1[]
		while ( i <= len1 ) {
			key[k++] = key1[i++];
		}
	}
	else if(j <= len2 ){ //merge remain record of key2[]
		while ( j <= len2 ) {
			key[k++] = key2[j++];
		}
	}
	else ;
	*last = k - 1; //get lenth-1
}//merge_array

void join(BiTree *T, int key[], int first, int last){ //create balanced tree using sorted array
	if(first == last){//left one record
		*T = (BiTree) malloc (sizeof(BiTreeNode));
		(*T)->data = key[first];
		(*T)->lchild = (*T)->rchild = NULL;
	}
	else if(first == last - 1){//left two record
		*T = (BiTree) malloc (sizeof(BiTreeNode));
		(*T)->data = key[first];
		(*T)->rchild = (BiTree) malloc (sizeof(BiTreeNode));
		(*T)->rchild->data = key[last];
		(*T)->lchild = (*T)->rchild->lchild = (*T)->rchild->rchild = NULL;
	}
	else{ //insert middle record
		int middle = (first + last) / 2;
		*T = (BiTree) malloc (sizeof(BiTreeNode));
		(*T)->data = key[middle];
		//recursive call the join function
		join(&((*T)->lchild), key, first, middle - 1);
		join(&((*T)->rchild), key, middle + 1, last);
	}
} //join

void split(BiTree T, BiTree *T1, BiTree *T2, int x){ //split one balanced tree T into two balanced tree T1 and T2
	int key[MAX];
	int last, index_x;
	inorder(T, key, &last, 0);//get sorted list array
	int get_x = get_index_x(key, last, x, &index_x);//get the index of x in array key
	if (get_x){
		//call join funcion to create balanced tree
		join(T1, key, 0, index_x);
		join(T2, key, index_x + 1, last);
	}
} //split

int get_index_x(int key[], int last, int x, int *index_x){
	int i, j;
	for ( i = 0; i <= last; i++ ) {
		j = i + 1;
		if((key[i] <= x && key[j] > x && j <= last ) || key[i] <= x && i == last){
			*index_x = i;
			return 1;
		}
	}
	return 0;
}//get_index

int inorder(BiTree T, int key[], int *last, int restore){
	static int i = 0;
	if (!restore)
	  i = 0;//when everytime call the function in main function, restore i to zero
	if(!T)
	  return 1;
	else{
		if (inorder(T->lchild, key, last, ++ restore)){
			key[i++] = T->data;//get array list
			if (inorder(T->rchild, key, last, ++ restore)){
				*last = i - 1;// get the length-1 of list
				return 1;
			}
		}
		return 0;
	}
}//inorder

int preorder(BiTree T){
	if(!T){
		return 1;
	}
	else{
		printf( "%d  ", T->data );
		if(preorder(T->lchild))
		  if(preorder(T->rchild))
			return 1;
		return 0;
	}
	return 0;
}//preorder

int main( int argc, char **argv ) {
	int key[16];
	for ( int i = 1; i <= 16; i++ ) {
		key[i-1] = 4*i - 3;
	}
	BiTree T;
	join(&T, key, 0, 15);
	preorder(T);
	printf( "\n\n" );

	int num[40];
	for ( int i = 0; i < 40; i++ ) {
		num[i] = 2*i + 1;
	}
	
	BiTree T0, T1, T2;
	
	join(&T0, num, 0, 39);
	preorder(T0);
	printf( "\n\n" );
	
	int x;
	printf( "Input x: " );
	scanf("%d", &x);
	split(T0, &T1, &T2, x);
	preorder(T1);
	printf( "\n" );
	preorder(T2);
	printf( "\n\n" );

	int key1[10], key2[20];
	for(int i = 0; i < 10; i ++)
	  key1[i] = 3*i;
	for ( int i = 0; i < 20; i++ ) {
		key2[i] = 2*i;
	}
	BiTree t, t1, t2;
	join(&t1, key1, 0, 9);
	preorder(t1);
	printf( "\n" );
	join(&t2, key2, 0, 19);
	preorder(t2);
	printf( "\n\n" );
	merge_tree(&t, t1, t2);
	preorder(t);
	printf( "\n" );
	return 0;
}
