//6.37
#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 100 // 栈空间初始分配量
#define INCREMENTSIZE 10 // 栈空间分配增量
#define OK 1
#define ERROR 0
typedef char ElemType ;
typedef int Status;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;
typedef struct {
	int top;// 栈顶指针
    BiTree base; // 栈不存在时值为 NULL
	int stacksize ;  //当前已分配空间

}SqStack ;

Status InitStack(SqStack *s){// 构造一个空栈 s
	s->base=(BiTree)malloc(INITSIZE * sizeof(BiTNode));
	if (!s) return ERROR;
	s->top=0;
	s->stacksize=INITSIZE;
	return OK;
}
//push 元素进栈
Status Push(SqStack *s,BiTNode e){
	if(s->top >= s->stacksize) {//若栈已满,则增加INCREMENTSIZE 个存储单元
		s->base=(BiTree)realloc(s->base,(s->stacksize + INCREMENTSIZE)*sizeof(BiTNode));
		if(!s->base) return ERROR;  //存储分配失败
		s->stacksize+=INCREMENTSIZE;
	}
	s->base[s->top++]=e; //e成为新的栈顶元素,栈顶指针加1
	return OK;
}
//pop 元素出栈
Status Pop(SqStack *s,BiTree e){
	if(s->top==0) return ERROR; // 栈空,返回出错标志
	*e=s->base[--s->top]; // 等于s->top--; *e=s->base[s->top];
	return OK;
}
int IsStackEmpty(SqStack *s){
  if(s->top == 0) return 1;
  else return 0;
}

Status CreateBiTree(BiTree *T){
  //按先序次序输入二叉树的值，空格字符表示空树
  char ch;
  if ((ch = getchar ()) == ' '||(ch == '\n')){
    *T = NULL;
  }
  else{
    *T = (BiTree) malloc (sizeof(BiTNode));
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
  }
  return 1;
}//CreateBiTree

void PreOrder_iter(BiTree T){
	SqStack S;
	BiTNode p;
	InitStack(&S);
	if(T)
	  Push(&S,*T);
	while(!IsStackEmpty(&S)){
		Pop(&S, &p);
		printf( "%c\t", p.data );
		if(p.rchild)
		  Push(&S,*(p.rchild));
		if(p.lchild)
		  Push(&S,*(p.lchild));
	}
}

int main( int argc, char **argv ) {
	BiTree T;
	printf("Creat a Tree: ");
	CreateBiTree(&T);
	printf( "PreOderTraverse_iter:\n" );
	PreOrder_iter(T);
	printf( "\n" );
	return 0;
}
