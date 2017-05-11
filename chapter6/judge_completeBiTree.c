//6.49 judge whether a bitree is a complete bitree
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct Node {
  BiTree data;
  struct Node *next;
}QNode;

typedef struct {
  QNode *front;
  QNode *rear;
}LinkedQueue;
//链队列的基本操作
// 链队列的初始化,构造一个空队列
Status InitQueue(LinkedQueue *lq){
  lq->front=lq->rear=(QNode *)malloc(sizeof(QNode));
  if(!lq->front) return ERROR;
  lq->front->next=NULL;
  return OK;
}
//队列判空
int IsQueueEmpty(LinkedQueue *lq){
  if(lq->front == lq->rear) return 1;
  else return 0;
}
// 入队:插入元素 e 为队列的新的队尾元素
Status Enqueue(LinkedQueue *lq,BiTree e){
  QNode *p;
  p=(QNode *)malloc(sizeof(QNode));
  if(!p) return ERROR;
  p->data =e; p->next=NULL;
  lq->rear->next=p; // 修改尾指针
  lq->rear=p;
  return OK;
}
// 出队:若队列不空,则删除队列的队头元素,
// 用 e 返回其值,并返回 OK ;否则返回 ERROR
Status Dequeue(LinkedQueue *lq,BiTree *e){
  QNode *p;
  if (lq->front == lq->rear)
    return ERROR; // 空队列的话,则出错
  p = lq->front->next; // 修改头指针
  *e = p->data;
  lq->front->next =p->next;
  if(lq->rear==p)
    lq->rear=lq->front; // 修改尾指针
  free(p);
  return OK;
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

int judge_completeBiTree(BiTree T){
	LinkedQueue Q;
	InitQueue(&Q);
	int flag = 0;
	Enqueue(&Q, T);
	BiTree p;
	while (!IsQueueEmpty(&Q) ) {
		Dequeue(&Q, &p);
		if(!p)
		  flag = 1;
		else if(flag)
		  return 0;
		else {
			printf( "%c\n", p->data );
			Enqueue(&Q, p->lchild);
			Enqueue(&Q, p->rchild);
		}
	}
	return 1;
}

int main( int argc, char **argv ) {
	BiTree T;
	printf( "Create a tree: " );
	CreateBiTree(&T);

	int value = judge_completeBiTree(T);
	printf( "%s\n", (value)?"True":"False" );
	return 0;
}
