//5.27
#include<stdio.h>
#include<stdlib.h>

typedef int Status;
typedef int ElemType;

#define OK 1
#define OVERFLOW 0

typedef struct OLNode{
	int i, j; //该非零元的行和列下标
	ElemType e;
	struct OLNode *down, *right;
} OLNode, *OLink;

typedef struct{
	OLink *rhead, *chead;//行和列链表头指针向量
	int mu, nu, tu;
}CrossList;

Status CreateSMatrix_OL(CrossList *M){
	//if(M)
	//  free(M);
	int m, n, t;
	int i, j, e;
	printf( "Please Enter row , column and tatal:" );
	scanf("%d%d%d",&m, &n, &t);
	M->mu = m;
	M->nu = n;
	M->tu = t;
	M->rhead = (OLink * ) malloc ((m + 1) * sizeof(OLink));
	M->chead = (OLink * ) malloc ((n + 1) * sizeof(OLink));
	if(!M->rhead || !M->chead)
	  exit(OVERFLOW);//存储分配失败
	for(i = 0; i <= m; i++)
	  M->rhead[i] = NULL;
	for(i = 0; i <= n; i++)
	  M->chead[i] = NULL;//初始化行列表头指针向量
	printf( "Please enter data:\n" );
	for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e)){
		if( i < 0 || j < 0 || i > M->mu || j > M->nu ){
			printf( "Error data input!\n" );
			exit(0);
		}
		OLNode *p, *q;
		p = (OLNode *) malloc (sizeof(OLNode));
		if(!p)
		  exit(OVERFLOW);
		p->i = i;
		p->j = j;
		p->e = e;//生成节点
		if(M->rhead[i] == NULL || M->rhead[i]->j > j){//寻找在行表中的插入位置
			p->right = M->rhead[i];
			M->rhead[i] = p;
		}
		else{
			for(q = M->rhead[i]; q->right && q->right->j < j; q = q->right) ;
			p->right = q->right ;
			q->right = p;
		}//完成行插入
		if(M->chead[j] == NULL || M->chead[j]->i > i){
			p->down = M->chead[j];
			M->chead[j] = p;
		}//寻找在列表中的插入位置
		else{
			for(q = M->chead[j]; q->down && q->down->i < i; q = q->down);
			p->down = q->down;
			q->down = p;
		}//完成列插入
	}//for
	return OK;
}//CreateSMatrix_OL

//两个矩阵相加，将M加到N上，因此要求M,N的行列数相等
void AddMatrix(CrossList *M, CrossList *N){
	if(M->mu != N->mu || M->nu != N->nu){
		printf( "Error Matrix Add!\n" );
		exit(0);
	}
	int n;
	int state;
	OLNode  *p,*q, *r, *s, *a, *b;
	for(n = 1; n <= M->mu; n++){//将M的每一行加到N上
		state = 0;
		r = M->rhead[n];
		s = N->rhead[n];
		p = NULL;
		q = NULL;
			while(r){
				while ( s ) {
					if(s->j == r->j){//纵坐标相同
						s->e += r->e;//直接相加
						state = 1;
						if(s->e)//和不为0,退出内层循环
						  break;
						else{//和为0,删除节点
							N->tu--;
							if(q == NULL)
								N->rhead[r->i] = s->right;
							  else
								q->right = s->right;
							  for( a = N->chead[s->j], b = NULL; a->down && a->i < r->i; ){
								  b = a;
								  a = a->down;
							  }
							  if(b == NULL){
								  N->chead[r->j] = a->down;
								  free(a);
							  }
							  else{
								  b->down = a->down;
								  free(a);
							  }
							  break;
						}
					}
					q = s;
					s = s->right;
				}
				if( state == 0 ){ //纵坐标不同，需要重新插入节点
					a = (OLNode *) malloc (sizeof(OLNode));
					if(!a)
					  exit(OVERFLOW);
					a->i = r->i;
					a->j = r->j;
					a->e = r->e;//生成节点
					if(N->rhead[r->i] == NULL || N->rhead[r->i]->j > r->j){//寻找在行表中的插入位置
						a->right = N->rhead[r->i];
						N->rhead[r->i] = a;
					}
					else{
						for(b = N->rhead[r->i]; b->right && b->right->j < r->j; b = b->right) ;
						a->right = b->right ;
						b->right = a;
					}//完成行插入
					if(N->chead[r->j] == NULL || N->chead[r->j]->i > r->i){
						a->down = N->chead[r->j];
						N->chead[r->j] = a;
					}//寻找在列表中的插入位置
					else{
						for(b = N->chead[r->j]; b->down && b->down->i < r->i; b = b->down);
						a->down = b->down;
						b->down = a;
					}
					N->tu++;
				}
					r = r->right ;
			}
	}
}
//按行打印
void PrintMatrix(CrossList *A){
	int i;
	OLink p;
	for ( i = 1; i <= A->mu; i++ ){
		p = A->rhead[i];
		while ( p ) {
			printf( "[%d, %d] %d\t", p->i, p->j, p->e );
			p = p->right;
		}
		printf( "\n" );
	}
}
//按列打印
//void PrintMatrix1(CrossList *A){
//    int i;
//    OLink p;
//    for(i = 1; i <= A->nu; i++){
//        p = A->chead[i];
//        while ( p ) {
//            printf( "[%d, %d] %d\t", p->i, p->j, p->e );
//            p = p->down;
//        }
//        printf( "\n" );
//    }
//}

void AddMatrix(CrossList *M, CrossList *N);
void PrintMatrix(CrossList *A);
Status CreateSMatrix_OL(CrossList *M);
//void PrintMatrix1(CrossList *A);

int main( int argc, char **argv ) {
	CrossList M, N;
	CrossList *p, *q;
	p = &M, q= &N;
	
	printf("Initial B:\n");
	CreateSMatrix_OL(p);
	
	printf( "Initial A:\n" );
	CreateSMatrix_OL(q);
	
	printf( "B:\n" );
	PrintMatrix(p);
	//printf( "B:\n" );
	//PrintMatrix1(p);

	printf( "A:\n" );
	PrintMatrix(q);
	//printf( "A:\n" );
	//PrintMatrix1(q);

	AddMatrix(p, q);
	printf( "A + B:\n" );
	PrintMatrix(q);
	//printf( "A + B:\n" );
	//PrintMatrix1(q);
	return 0;
}
