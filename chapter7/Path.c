//7.22
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

//输出有向图
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

int FindPath(AGraph *G, int w, int v){ //找到从第w个顶点到第v个顶点的路径
	static int i = 0;
	static int value = 0;
	if( w == v ){
		value = 1;
		return value;
	}
	else{
		NodeLink *p;
		for( p = G->v[w].first; p ; p = p->next )
		  if(p->vindex != w)
			FindPath(G, p->vindex, v);//递归
	}
	return value;
}

void CreateGraph(AGraph *g,int n,int m);
void ListGraph(AGraph *g) ;
int FindPath(AGraph *G, int w, int v);

int main( int argc, char **argv ) {
	AGraph G;
	int n;
	char c;

	printf( "Input the Number of Vertexs: " );
	scanf("%d",&n);
	while ( (c = getchar()) != '\n' ) { //消除前面的上次输入的空格和换行符
		;
	}

	CreateGraph(&G, n, 1);
	
	printf( "Output The Graph: \n" );
	ListGraph(&G);

	int w, v;
	printf( "Input the vertex:w-->v:" );
	scanf("%d %d", &w, &v);
	int PathValue = FindPath(&G,w, v );
	if(PathValue){
		printf( "Exist Path!\n" );
	}
	else
	  printf( "No Path!\n" );
	return 0;
}
