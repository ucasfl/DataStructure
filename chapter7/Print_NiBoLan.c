//7.38
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 30
typedef char ElemType;

typedef struct NodeLink {
	int vindex; // 邻接点在头结点数组中的位置 ( 下标 )
	struct NodeLink *next; // 指向下一个表结点
}NodeLink; // 表结点类型定义

typedef struct {
	// 图的顶点数、边数、种类标志
	int vexnum,edgenum,kind;
	struct {
		ElemType vertex;
		NodeLink *first;// 指向第一个表结点
	}v[MAX_VERTEX_NUM];
}AGraph;
//创建一个正邻接表存储的有向图
void CreateGraph(AGraph *g,int n,int m){
	int i, e = 0;
	NodeLink *p, *q, *s;
	char x, y;
	g->vexnum = n;
	g->kind = m;
	for(i=0;i<n;i++) {// 初始化邻接表
		g->v[i].vertex = i + 'A';
		g->v[i].first=NULL;
	}
	printf("Input edges x-->y:"); 
	scanf("%c%c",&x,&y);
	while(x!='X' && y!='X'){ //生成节点并插入临接表
		e++;
		s=(NodeLink *)malloc(sizeof(NodeLink));
		s->vindex= y-'A';
		if(g->v[x-'A'].first == NULL) {
			g->v[x-'A'].first =s;
			s->next = NULL;
		}
		else{
			p=g->v[x-'A'].first;
			q=p->next;
			while (q!=NULL){
				p=q;q=q->next;
			}
			p->next=s;s->next=q;
		}
		scanf(" %c%c",&x,&y);
	}
	g->edgenum =e;
}

//输出图
void ListGraph(AGraph *g) {
	int i;
	NodeLink *p;
	for(i=0;i<g->vexnum;i++){
		printf("%d:%c--->",i,g->v[i].vertex);
		p=g->v[i].first;
		while(p) {
			printf("%3d",p->vindex );
			p=p->next;
		}
		printf("\n");
	}
}

int Find_Root(AGraph *G){//找到根，即入度为0
	 int degree[G->vexnum];
	for ( int i = 0; i < G->vexnum; i++ ) {
		degree[i] = 1;
	}
	NodeLink *p;
	for ( int i = 0; i < G->vexnum; i++ ){
		for ( p = G->v[i].first; p; p = p->next ){
			degree[p->vindex] = 0;
		}
	}
	for ( int i = 0; i < G->vexnum; i++ )
	  if ( degree[i] )
		return i;
}

void Out_Put(AGraph *G, int i){
	char c = G->v[i].vertex;
	if ( !G->v[i].first )
	  printf( "%c ", c );
	else{
		NodeLink *p;
		p = G->v[i].first;
		Out_Put(G, p->vindex);
		Out_Put(G, p->next->vindex);
		printf( "%c ",c );
	}
}

void Print_NiBoLan(AGraph *G){
	int value = Find_Root(G);
	Out_Put( G, value );
}

void CreateGraph(AGraph *g,int n,int m);
void ListGraph(AGraph *g) ;
void Out_Put(AGraph *G, int i);
void Print_NiBoLan(AGraph *G);
int Find_Root(AGraph *G);

int main( int argc, char **argv ) {
	AGraph G;
	int m, n;
	printf( "Input the number of vertex and Graph Kind:" );
	scanf("%d%d", &n, &m);
	while( (getchar()) != '\n' )
	  ;

	CreateGraph( &G, n, m );
	ListGraph(&G);

	Print_NiBoLan(&G);
	printf( "\n" );

	return 0;
}
