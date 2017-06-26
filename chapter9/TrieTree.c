//9.42 9.43 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INSERT 1
#define DELETE 2
#define TRAVERSE 3
#define BRANCH 0
#define LEAF -1

typedef struct KeyType {
	char ch[11];
	struct KeyType *next;
}KeyType;

typedef struct TrieNode {
	char  kind;
	union {
		struct {
			KeyType  *k;
			int num;											
		}lf;		
		struct {
			struct TrieNode *ptr[27];
			int num;
		}bh;
	};
}TrieNode, *Tree;

//Tree search(Tree T, char k[], int h);// search whethere k is in T or not
void insert(Tree *T, char key[], int h);// insert k into T
void delete(Tree *T, char key[], int h);//delete k from T if it exsits
int traverse(Tree T);//traverse the tree T
int order(char c);
void init(Tree *T);

int main( int argc, char **argv ) {
	int h, n;//h refers to the largest layer number, n refers to the number of operations
	int op; //op refers to the operation type
	char record[11]; //the record you want insert or delete
	printf( "Input the largest layer number and operations' number: " );
	scanf("%d%d", &h, &n);
	Tree T;
	init(&T);
	
	for ( int i = 0; i < n; i++ ) {
		printf( "Input operation(INSERT == 1, DELETE == 2, TRAVERSE == 3): " );
		scanf("%d", &op);
		if(op == INSERT){
			printf( "Input string wanted insert:\n " );
			scanf("%s", record);
			//call insert function
			insert(&T, record, h);
		}
		else if(op == DELETE){
			printf( "Input string wanted delete:\n " );
			scanf("%s", record);
			//call delete function
			delete(&T, record, h);
		}
		else if(op == TRAVERSE){
			printf( "Traverse the Tree:\n" );
			//call traverse function
			traverse(T);
		}
		else{//input error
			printf("Undefined operation!\n");
			return 0;
		}
	}
	return 0;
}

int order(char c){
	return c - '@';//return the charactors rank in charactors menu
}

void init(Tree *T){
	*T = (Tree) malloc (sizeof(TrieNode));
	(*T)->kind = BRANCH;
	for ( int i = 0; i < 27; i++ ) {
		(*T)->bh.ptr[i] = NULL;
	}
} //init

void insert(Tree *T, char key[], int h){
	Tree q = (TrieNode *) malloc (sizeof(TrieNode)); //buile a new leaf
	q->kind = LEAF;
	KeyType *ktemp = (KeyType *) malloc (sizeof(KeyType));
	int len = strlen(key);
	for(int i = 0; i < len; i++)
	  ktemp->ch[i] = key[i];
	ktemp->next = NULL;
	q->lf.k = ktemp;
	q->lf.num ++;

	Tree *p = &(*T)->bh.ptr[order(key[0])], *last, temp;
	last = T;
	int i = 0;
	int j = 1;
	while (  i < len && j < h ) { //search for the key in the Tree
		i ++;
		j ++;
		if(!*p){
			temp = (TrieNode *) malloc (sizeof(TrieNode));//if NULL, add BRANCH
			temp->kind = BRANCH;
			for ( int i = 0; i < 27; i++ ) { //initial the new branch
				temp->bh.ptr[i] = NULL;
			}
			(*last)->bh.num++;//the branch's number of last brach plus one
			*p = temp;
		}
		last = p;
		if ( i < len )
		  p = &((*p)->bh.ptr[order(key[i])]);
		else
		  break;
	}
	if (i == len){ //arrive in a BRANCH, just link the leaf to the BRANCH
		(*p)->bh.ptr[0] = q;
		(*p)->bh.num ++;
	}
	else{ //the layer has full
		if(!(*last)->bh.ptr[order(key[i-1])]){//there no leaf, just need link it
			(*last)->bh.ptr[order(key[i-1])] = q;
			(*last)->bh.num ++;
		}
		else{//there has another leaf, replace the old leaf with new leaf, and add the old leaf's record to the new leaf
			q->lf.k->next = (*last)->bh.ptr[order(key[i-1])]->lf.k;
			q->lf.num += (*last)->bh.ptr[order(key[i-1])]->lf.num;
			(*last)->bh.ptr[order(key[i-1])] = q;
			//free (p);
		}
	}
}//insert

void delete(Tree *T, char key[], int h){ //make sure the key[] exists in T 
	Tree p;
	//Tree last;
	p = (*T)->bh.ptr[order(key[0])];
	int len = strlen(key);
	int i = 1, j = 1;
	while( i < len && j < h - 1 ){ //search for the key
		//last = p;
		p = p->bh.ptr[order(key[i])];
		i ++;
		j ++;
	}
	if ( i == len  ){//the key in a leaf and its lenth <= h
		p->bh.num --;
		free(p->bh.ptr[0]);
		p->bh.ptr[0] = NULL;
	}
	else{ //the key's length > h
		if ( p->bh.ptr[order(key[i-1])]->lf.num == 1){ //just one value in the leaf
			free( p->bh.ptr[order(key[i-1])] );
			p->bh.ptr[order(key[i-1])] = NULL;
		}
		else{ //one more value in the leaf
			KeyType *s = p->bh.ptr[order(key[i-1])]->lf.k, *last_key = s;
			while( s && !strcmp(s->ch, key)){
				last_key = s;
				s = s->next;
			}
			if( s == last_key ){ //the first value
				p->lf.k = s->next;
				p->bh.ptr[order(key[i-1])]->lf.num --;
				free(s);
			}
			else{ //not the first value
			last_key->next = s->next;
			p->lf.num --;
			free(s);
			}
		}
	}
} //delete

int traverse(Tree T){ //traverse the whole TrieTree
	if (!T)
	  return 1; //the Tree is empty
	else if(T->kind == LEAF){//T is a leaf
		printf( "leaf %d ", T->lf.num );
		KeyType *s = T->lf.k;
		for ( int i = 0; i < T->lf.num; i++ ) {
			printf("%s ", s->ch);
			s = s->next;
		}
		printf("\n");
	}
	else{
		printf( "BRANCH %d\n", T->bh.num );
		for(int i = 0; i < 27; i ++){//recursive recall the traverse function
			traverse(T->bh.ptr[i]);
		}
	}
	return 1;
}//traverse
