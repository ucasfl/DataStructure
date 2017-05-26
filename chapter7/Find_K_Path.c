//7.27 判断临接表存储的无向图任意两个顶点之间是否存在长度为k的路径

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
//创建一个临接表存储的无向图
void CreateGraph(AGraph *g,int n,int m){
	int i, e = 0;
	NodeLink *p, *q, *s;
	char x, y;
	g->vexnum = n;
	g->kind = m;
	for(i=0;i<n;i++) {// 初始化邻接表
		g->v[i].vertex = 'A'+i;
		g->v[i].first=NULL;
	}
	printf("Input edges x-->y:"); scanf("%c%c",&x,&y);
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
		if(!g->kind){ // 无向图
			s=(NodeLink *)malloc(sizeof(NodeLink));
			s->vindex = x-'A';
			if(g->v[y-'A'].first == NULL) {
				g->v[y-'A'].first =s;
					s->next = NULL;
			}
			else{
				p=g->v[y-'A'].first; q=p->next;
				while(q!=NULL) {
					p=q;q=q->next;
				}
				p->next =s;s->next=q;
			}
		}
		scanf(" %c%c",&x,&y);
	}
	g->edgenum =e;
}

//输出无向图
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

int Visited[MAX_VERTEX_NUM];

int Find_Path(AGraph *G, int i, int j, int k){
	if( i == j && k == 0 )
	  return 1;
	else if( k > 0 ){
		NodeLink *p;
		int n;
		Visited[i] = 1;
		for( p = G->v[i].first ; p ; p = p->next ){
			n = p->vindex;
			if( !Visited[n] )
			  if( Find_Path(G, n, j, k - 1) )//路径长度减1
				return 1;
		}//for
		Visited[n] = 0;
	}
	return 0;
}

void CreateGraph(AGraph *g,int n,int m);
void ListGraph(AGraph *g) ;
int Find_Path(AGraph *G, int i, int j, int k);

int main( int argc, char **argv ) {
	AGraph G;
	int n,m;

	printf( "Create A Graph G:\n" );
	printf( "Input the number of vertexs and Graph Kind:" );
	scanf("%d%d", &n, &m);
	while ( (getchar()) != '\n') {
		;
	}

	CreateGraph(&G, n, m);

	ListGraph(&G);

	int i, j, k;
	printf( "Input i, j, k, the length of the path i-->j == k\n" );
	scanf("%d%d%d", &i, &j, &k);

	int value = Find_Path(&G, i, j, k);
	printf( "%s\n", (value)?"Exist Path!":"No Path!" );
	return 0;
}
