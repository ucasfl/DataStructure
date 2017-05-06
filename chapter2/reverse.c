//2.22
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的分配增量
typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType *elem;    //存储空间基址
	int length;        //当前长度
	int listsize;      //当前分配的存储容量

}SqList;

Status InitList_Sq(SqList *L){
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);    //存储分配失败
	L->length=0;                    //空表长度为0
	L->listsize=LIST_INIT_SIZE;     //初始存储容量
	return OK;

}//InitList_Sq

Status Insert_Sq(SqList *L,ElemType e,int i){
	if(L->length >=L->listsize){ //当前存储空间已满，增加分配
		ElemType *newbase;
		newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);     //存储分配失败
		L->elem=newbase;                 //新基址
		L->listsize+=LISTINCREMENT;       //增加存储容量
	}
	L->elem[i]=e;
	++L->length;
	return OK;
}

//结点的类型定义
typedef struct Lnode{
	ElemType data; /* 数据域,保存结点的值 */
    struct Lnode *next; /* 指针域 */
}Lnode, LinkList;/* 结点的类型 */
//创建单链表
LinkList *CreateList_L(int n) {
	LinkList *L,*p; int i;
	L = (LinkList *)malloc(sizeof(Lnode));
	if(!L) return ERROR;//存储分配失败
	  L->next = NULL;
	for (i=n; i>0; --i) {
		p = (LinkList *)malloc(sizeof(Lnode)); // 生成新结点
			if(!p)  return ERROR;
		p->data =i;
		p->next = L->next; 
		L->next = p; // 插入到表头
	}
	return L;
}//createList_L

//原地倒转链表
Status ReverseList(LinkList *L){
	SqList Sq,*p;
	p=&Sq;
	InitList_Sq(p);
	LinkList *q;
	q=L->next;
	int i=0;
	while(q){//先将数据存到顺序线性表中
		Insert_Sq(p,q->data,i);
		q=q->next;
		i++;
	}
	//反存
	i--,q=L->next;
	while(q)
	  q->data=p->elem[i--],q=q->next;
	return OK;
}//Reverse_LinkList

//函数声明
Status InitList_Sq(SqList *L);
Status Insert_Sq(SqList *L,ElemType e,int i);
LinkList *CreateList_L(int n) ;
Status ReverseList(LinkList *L);

//main函数测试
int main(){
	LinkList *p,*q;
	p=CreateList_L(30);
	q=p;
	printf("Before reverse,List:\n");//倒置前
	for(;p->next;)
	  printf("%d\t",p->next->data),p=p->next;
	printf("\n\n");

	ReverseList(q);
	printf("After reverse,List:\n");//倒置后
	for(;q->next;)
	  printf("%d\t",q->next->data),q=q->next;
	printf("\n\n");
	
	return 0;
}
