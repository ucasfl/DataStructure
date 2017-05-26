//7.42 用临接表存储实现 Dijkstra 算法
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTEX_NUM 20

typedef char ElemType;

typedef struct NodeLink {
	int vindex; // 邻接点在头结点数组中的位置 ( 下标 )
	struct NodeLink *next; // 指向下一个表结点
	int info;    //权值
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
	int info;
	g->vexnum = n;
	g->kind = m;
	for(i=0;i<n;i++) {// 初始化邻接表
		g->v[i].vertex = i + 'A';
		g->v[i].first=NULL;
	}
	printf("Input edges x-->y and info:"); 
	scanf("%c%c%d",&x,&y, &info);
	while(x!='X' && y!='X'){ //生成节点并插入临接表
		e++;
		s=(NodeLink *)malloc(sizeof(NodeLink));
		s->vindex= y-'A';
		s->info = info;
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
		scanf(" %c%c%d",&x,&y,&info);
	}
	g->edgenum =e;
}
//输出有向图
void ListGraph(AGraph *g) {
	int i;
	NodeLink *p;
	for(i=0;i<g->vexnum;i++){
		printf("%d:%c--->",i,g->v[i].vertex);
		p=g->v[i].first;
		while(p) {
			printf("%3d(%d)",p->vindex, p->info );
			p=p->next;
		}
		printf("\n");
	}
}

int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int D[MAX_VERTEX_NUM];

void AGraph_DIJ(AGraph *G, int v0, int p[][MAX_VERTEX_NUM]){
	int i, j;
	for ( i = 0; i < G->vexnum; i++ ) {
		D[i] = INT_MAX;
	}
	NodeLink *q;
	for( q = G->v[v0].first; q; q = q->next )
	  D[q->vindex] = q->info;//D赋初始值
	int final[G->vexnum];
	for( i = 0; i < G->vexnum; i++ ){
		final[i] = 0;
		for( j = 0; j < G->vexnum; j++ ){
			p[i][j] = 0; //设空路径
		}
		if( D[i] < INT_MAX  ){
			p[i][v0] = 1;
			p[i][i] = 1;
		}
		D[v0] = 0;
		final[v0] = 1; //初始化
	}
	int min, vex;
	for ( i = 0; i <G->vexnum; i++ ){
		min = INT_MAX;
		for ( j = 0; j <G->vexnum; j++ ){
			if ( !final[j] )
			  if ( D[j] < min ){
				  vex = j;
				  min = D[j];
			  }
		}
		final[vex] = 1;
		for( q = G->v[vex].first; q; q = q->next ){
			int value = q->vindex;
			if ( !final[value] && ( min + q->info  ) < D[value]){
				D[value] = min + q->info;
				for( int k = 0; k < G->vexnum; k++ )
				  p[value][k] = p[vex][k];
				p[value][value] = 1;
			}//if
		}//for
	}//for
}
void CreateGraph(AGraph *g,int n,int m);
void ListGraph(AGraph *g);
void AGraph_DIJ(AGraph *G, int v0, int p[][MAX_VERTEX_NUM]);

int main( int argc, char **argv ) {
	AGraph G;
	int n, m;
	printf( "Input the number of vertex and edge:" );
	scanf("%d%d",&n, &m);
	CreateGraph(&G, n, m);

	AGraph_DIJ(&G, 2, p);
	ListGraph(&G);
	for (int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			printf( "%4d", p[i][j] );
	  }
		printf( "Lenth = %d\n", D[i] );
	}
	return 0;
}
