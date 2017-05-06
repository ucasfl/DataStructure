//4_29
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
		q->next = p;
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
			p = p->succ,q = q->succ,p->next = q;
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
/*4.29*/
LinkNode *StrIndex(LinkNode *S,LinkNode *L){ /*字符串匹配，Ｓ为母串，Ｌ为模式串*/
	LinkNode *p = S->succ,*q = L->succ;
	while ( p&&q ) {
		if(q == L||q->chdata == p->chdata){
			p = p->succ;
			q = q->succ;
		}
		else {
			q = q->next;
		}
	}
	if ( !q ) {
		while(L->succ){
			p = p->next;
			L = L->succ;
		}
		return p;
	}
	return NULL;
}
LinkNode *StrIndex(LinkNode *S,LinkNode *L);
LinkNode *Crea_List();
void count_next(LinkNode *L);
void PrintS(LinkNode *L);
void PrintNextChar(LinkNode *L);
/*main 函数*/
int main( int argc, char **argv ) {
	printf( "enter S:" );
	LinkNode *S = Crea_List();
	printf( "\n" );

	printf( "enter L:" );
	LinkNode *L = Crea_List();
	printf( "\n" );
	count_next(L);

	LinkNode *post = StrIndex(S,L);
	if ( !post ) {
		printf( "No such subtring\n" );
	}
	while(post&&L->succ){
		printf( "%c",post->chdata );
		L = L->succ;
		post = post->succ;
	}
	printf( "\n" );
	return 0;
}
