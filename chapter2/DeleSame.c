//2.29
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define FIND 1
#define NONE 0

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

//元素插入
Status Insert_Sq(SqList *L,ElemType e){
	if(L->length >=L->listsize){ //当前存储空间已满，增加分配
		ElemType *newbase;
		newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);     //存储分配失败
		L->elem=newbase;                 //新基址
		L->listsize+=LISTINCREMENT;       //增加存储容量
	}	
	L->elem[L->length]=e;
	L->length++;
	return OK;
}
//寻找相同元素
Status Find_Sq(SqList *L,ElemType e){
	if(e<L->elem[0]||e>L->elem[L->length-1])
	  return NONE;
	int i=0;
	while(i<L->length&&e!=L->elem[i])
	  i++;
	if(i==L->length)
	  return NONE;
	return FIND;
}

//删除单个元素
Status DeleElem(SqList *L,ElemType e){
	if(e<L->elem[0]||e>L->elem[L->length-1])
	  return OK;
	ElemType *p,*q;
	int i=0;
	while(i<L->length&&e!=L->elem[i])
	  i++;
	if(i==L->length)
	  return OK;
	p=&L->elem[i];
	for(q=&L->elem[L->length-1];p<q;p++)
	  *p=*(p+1);
	--L->length;
	return OK;
}
//删除A中含有的B和C中相同的元素
Status DeleSame_Sq(SqList *A,SqList *B,SqList *C){
	SqList *p,*q,L;
	p=&L;
	InitList_Sq(p);
	int i,find;
	for(i=0;i<B->length;i++){    //寻找相同元素
		find=Find_Sq(C,B->elem[i]);
		if(find==1)
		  Insert_Sq(p,B->elem[i]);
	}

	printf("The Same elements are:\n");
	for(int i=0;i<p->length;i++)
	  printf("%d\t",p->elem[i]);
	printf("\n\n");

	for(i=0;i<p->length;i++){  //将相同元素从A中删除
		DeleElem(A,p->elem[i]);
	}
	return OK;
}

//函数声明
Status InitList_Sq(SqList *L);
Status Insert_Sq(SqList *L,ElemType e);
Status Find_Sq(SqList *L,ElemType e);
Status DeleElem(SqList *L,ElemType e);
Status DeleSame_Sq(SqList *A,SqList *B,SqList *C);

//main函数测试
int main(){
	//初始化
	SqList A,B,C;
	SqList *p,*q,*r;
	p=&A,q=&B,r=&C;
	InitList_Sq(p), InitList_Sq(q), InitList_Sq(r);
	int i;
	//赋值
	for(i=0;i<60;i++)
	  p->elem[i]=i+1,p->length++;
	for(i=0;i<30;i++)
	  q->elem[i]=2*(i+1),q->length++;
	for(i=0;i<20;i++)
	  r->elem[i]=3*(i+1),r->length++;
	
	printf("Before DeleSame:\n");
	
	printf("A:\n");
	for(i=0;i<p->length;i++)
	  printf("%d\t",p->elem[i]);
	printf("\n\n");

	printf("B:\n");
	for(i=0;i<q->length;i++)
	  printf("%d\t",q->elem[i]);
	printf("\n\n");

	printf("C:\n");
	for(i=0;i<r->length;i++)
	  printf("%d\t",r->elem[i]);
	printf("\n\n");
	
	//删除元素
	DeleSame_Sq(p,q,r);
	printf("After Dele,A:\n");
	for(i=0;i<p->length;i++)
	  printf("%d\t",p->elem[i]);
	printf("\n\n");

	return 0;
}
//算法的时间复杂度为O(n^2)
