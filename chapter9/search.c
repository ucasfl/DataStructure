//9.29
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList(int n, LinkList *h); //create the linklist by order
void search(LinkList *h, LinkList *t, int key[], int m);//search every K in key[]
LinkList *output(LinkList *h, LinkList *t, int n);//output value through when search n

int main( int argc, char **argv ) {
	int n, m;
	LNode N;
    LinkList h, t;
	printf( "Input Linklist:\n" );
	scanf("%d", &n);
	h = &N;
	CreateList(n, &h);//create sorted linklist
	t = h;
	printf( "Input search key:\n" );
	scanf("%d", &m);
	int key[m];
	for ( int i = 0; i < m; i++ ) {
		scanf("%d", &key[i]);//input the key you want search
	}
	printf( "Output search results:\n" );//output the reasch results
	search(&h, &t, key, m);
	return 0;
}
//Create the cycle linklist
void CreateList(int n, LinkList *h){
	LinkList p, q;
	p = *h;
	scanf("%d", &(p->data));// create the first one
	int i = 0;
	while ( i++ < n - 1 ) {
		q = (LinkList) malloc (sizeof (LNode) );
		scanf("%d", &(q->data));
		p->next = q;
		p = p->next;
	}
	p->next = *h; //the last record point to the first one
}

void search(LinkList *h, LinkList *t, int key[], int m){
	int i;
	LinkList *p;
	for ( i = 0; i < m; i++ ) {
		p = t;
		t = output(h, p, key[i]);//search every key in key[]
	}
}

LinkList *output(LinkList *h, LinkList *t, int n){
	if(n == (*t)->data){
		printf("%d\n", (*t)->data);
		return t;
	}
	else{
		printf( "%d ", (*t)->data );
		if (n > (*t)->data){  //K > t->key, search from last
			//LinkList p = t; //save the last value of point t
			*t = (*t)->next;
			while((*t)->data < n && (*t) != (*h)){
				printf( "%d ", (*t)->data );
				//p = t;
				*t = (*t)->next;
			}
			printf( "%d\n", (*t)->data );
			return t;
		}
		else {//K < t->key
			//LinkList q = t;
			*t = (*t)->next;
			while(*t != *h){
				printf( "%d ", (*t)->data );
				//q = t;
				*t = (*t)->next;
			}
			if((*h)->data > n){//K < any data in linklist
				printf( "%d\n", (*h)->data );
				*t = *h;
				return t;
			}
			else{
				//t = t->next;
				printf( "%d\t", (*t)->data );
				while(n > (*t)->data){
					printf( "%d ", (*t)->data );
					//q = t;
					*t = (*t)->next;
				}
				printf( "%d\n", (*t)->data );
				return t;
			}
		}
	}
}
