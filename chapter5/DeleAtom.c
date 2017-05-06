//5.37
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int AtomType;

typedef enum{ATOM,LIST}ElemTag;

typedef struct GLNode {
	ElemTag tag;// = ATOM or = LIST
	union {// 原子结点和表结点的联合部分
		AtomType atom;
		struct {struct GLNode *hp, *tp;} ptr;//ptr.hp,ptr.tp分别指向表头和表尾
	};
}GLNode, *GList;

int DeleX(GList *L, AtomType x){
	if(!*L)
	  return 1;//空表直接返回
	else if((*L)->tag == ATOM){
		if((*L)->atom != x)
		  return 1;//原子值不等于x
		else{    //删除值等于x的原子项
			free(*L);
			*L = NULL;
			return 1;
		}
	}
	else{
		DeleX(&((*L)->ptr.hp), x);
		DeleX(&((*L)->ptr.tp), x);
		return 1;
	}
}
//创建一个广义表节点
void CreatGList(GList L){
	int i;
	GList p = L;
	p->tag = LIST;
	p->ptr.hp = (GList) malloc (sizeof (GLNode));
	if(!p->ptr.hp){
		printf( "Error!" );
		exit(0);
	}
	p->ptr.hp->tag = ATOM;
	p->ptr.hp->atom = rand()%10;
}
//打印广义表，递归
int PrintGList(GList L){
	if(!L)
	  return 1 ;
	else if(L->tag == ATOM){
		printf( "%d\t", L->atom );
		return 1;
	}
	else{
		PrintGList(L->ptr.hp);
		PrintGList(L->ptr.tp);
		return 1;
	}
}
void CreatGList(GList L);
int PrintGList(GList L);
int DeleX(GList *L, AtomType x);

int main( int argc, char **argv ) {
	GLNode L;
	GList p = &L, q;
	CreatGList(p);
	p->ptr.tp = (GList)malloc(sizeof(GLNode));
	q = p->ptr.tp;
	for( int i = 0; i < 40 ; i ++ ){
		CreatGList(q);

		q->ptr.tp = (GList) malloc (sizeof(GLNode));
		q = q->ptr.tp;
	}
	q->tag = ATOM;
	q->atom = rand()%10;

	printf( "Before Dele, L:\n" );
	PrintGList(p);
	printf( "\n" );

	printf( "Please enter 'x': " );
	int x;
	scanf("%d",&x);

	DeleX(&p, x);
	printf( "After delete %d, L:\n", x );
	PrintGList(p);
	printf( "\n" );
	return 0;
}
