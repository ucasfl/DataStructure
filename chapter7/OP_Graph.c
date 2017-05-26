//7.15 用临接矩阵实现图的基本操作
#include<stdio.h>
#include<stdlib.h>

// 图的种类: UDG 无向图, DG 有向图, UDN 无向网, DN 有向网
typedef enum {UDG, DG, UDN, DN} GraphKind;
#define Max 30

typedef struct{
	int vexnum,arcnum; // 顶点数,边数,
	GraphKind kind; // 图的种类
	char vexs[Max]; // 存放顶点信息
	int A[Max][Max];// 存放边的信息
}MGraph;

void CreateGraph(MGraph *g) {
	int i,j,k;
	printf("Input: Vex Num & Arc Num & Arc Kind\n");
	scanf("%d %d %d",&g->vexnum,&g->arcnum,&k);
	switch (k) {
		case 0: g->kind=UDG;break;
		case 1: g->kind=DG;break;
	}
	for(k=0;k<g->vexnum;k++)
	  g->vexs[k]='A'+k;
	for(i=0;i<g->vexnum;i++)
	  for(j=0;j<g->vexnum;j++)
		g->A[i][j] = 0; // 初始化邻接矩阵
	printf("Input: %d edges: \n",g->arcnum);
	for(k=0;k<g->arcnum;k++){
		scanf("%d %d",&i,&j);
		g->A[i][j]=1;
		if(g->kind==UDG) 
		  g->A[j][i]=1; // 无向图时,邻接矩阵是对称的
	}
}

void ListGraph(MGraph *g){
	int i,j;
	for(i=0;i<g->vexnum;i++) {
		printf("%6c---",g->vexs[i]);
		for(j=0;j<g->vexnum;j++)
		  printf("%4d",g->A[i][j]);
		printf("\n");
	}
}
//无向图插入节点
void InsertVex(MGraph *g, char c){
	g->vexs[g->vexnum] = c;
	g->vexnum ++;
	for ( int i = 0; i < g->vexnum; i++ ) {
		g->A[g->vexnum - 1][i] = g->A[i][g->vexnum - 1] = 0;
	}
}

void DeleteVex(MGraph *g, char c){
	int i, j, k;
	for ( i = 0; i < g->vexnum && g->vexs[i] != c; i++ )
	  ;
	for( j = i; j < g->vexnum ; j ++ ){
		g->vexs[j] = g->vexs[j + 1];
	}
	for(j = 0; j < g->vexnum; j++){//更新边数
		if(g->A[i][j])
		  g->arcnum--;
	}
	for(j = 0; j < g->vexnum; j++){
		g->A[i][j] = g->A[j][i] =0;
	}
	for(j = i; j < g->vexnum; j++)//更新临接矩阵
	  for(k = 0; k < g->vexnum; k++ ){
		  g->A[j][k] = g->A[j+1][k];
		  g->A[k][j] = g->A[k][j+1];
	  }
	g->vexnum --;
}

void InsertEdge(MGraph *g, char w, char v){
	int i, j ;
	for( i = 0; i < g->vexnum && g->vexs[i] != w; i++ )
	  ;
	for( j = 0; j < g->vexnum && g->vexs[j] != v; j++ )
	  ;
	g->A[i][j] = g->A[j][i] = 1;
	g->arcnum++;
}

void deleteEdge(MGraph *g, char w, char v){
	int i, j ;
	for( i = 0; i < g->vexnum && g->vexs[i] != w; i++ )
	  ;
	for( j = 0; j < g->vexnum && g->vexs[j] != v; j++ )
	  ;
	g->A[i][j] = g->A[j][i] = 0;
	g->arcnum--;
}

void clear(){
	while(getchar() != '\n')
	  ;
}

void CreateGraph(MGraph *g);
void ListGraph(MGraph *g);
void DeleteVex(MGraph *g, char c);
void InsertVex(MGraph *g, char c);
void InsertEdge(MGraph *g, char w, char v);
void deleteEdge(MGraph *g, char w, char v);
void clear();

int main( int argc, char **argv ) {
	MGraph G;
	CreateGraph(&G);
	printf( "The Graph G:\n" );
	ListGraph(&G);
	clear();

	char x, y;
	printf( "Input the Insert Vex:" );
	scanf("%c", &x);
	InsertVex(&G, x);
	printf( "After Insert, G:\n" );
	ListGraph(&G);
	clear();

	printf( "Input the Delete Vex:" );
	scanf("%c", &x);
	DeleteVex(&G, x);
	printf( "After Delete: G:\n" );
	ListGraph(&G);
	clear();

	printf( "Input the Insert Edge, x--y:" );
	scanf("%c %c", &x,&y);
	InsertEdge(&G, x, y);
	printf( "After Insert Edge, G:\n" );
	ListGraph(&G);
	clear();

	printf( "Input the Delete Edge, x--y:" );
	scanf("%c %c", &x, &y);
	deleteEdge(&G, x, y);
	printf( "After Delete Edge, G:\n" );
	ListGraph(&G);
	return 0;
}
