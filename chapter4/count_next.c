//4.28
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0

typedef struct LinkNode{
	char chdata;
	struct LinkNode *succ;
	struct LinkNode *next;
}LinkNode;

LinkNode *Crea_List(){ /*assign a string to a linklist*/
	char c;
	LinkNode *p,*q,*r;
	p = (LinkNode *)malloc(sizeof(LinkNode));
	if(!p)
	  exit(ERROR);
	p->succ = NULL;
	p->next = NULL;
	r = p;
	while((c=getchar())!='\n'&&c!=EOF){
		q = (LinkNode *)malloc(sizeof(LinkNode));
		if(!q)
		  exit(ERROR);
		q->chdata = c;
		q->next = NULL;
		q->succ = NULL;
		p->succ = q;
		p = q;
	}
	return r;
}

void count_next(LinkNode *L){ /*count next pointer*/
	LinkNode *p,*q;
	p = L->succ, p->next = L, q = L;
	while ( p->succ ) {
		if ( q == L||p->chdata==q->chdata ) {
			p = p->succ;
			q = q->succ;
			p->next = q;
		}
		else {
			q = q->next;
		}
	}
}

void PrintS(LinkNode *L){ /*print linkString*/
	while(L->succ){
		printf( "%c",L->succ->chdata );
		L = L->succ;
	}
	printf( "\n" );
}
void PrintNextChar(LinkNode *L){
	while(L->succ){
		printf( "%c",L->succ->next->chdata );
		L = L->succ;
	}
	printf( "\n");
}
