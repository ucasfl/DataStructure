//2.19
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
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
} // CreateList_L

Status DeleSq(LinkList *L,ElemType mink,ElemType maxk){
	LinkList *p,*q,*s;
	p=L->next;
	q=L;

	if(p->data>=maxk)  //链表中的最小值大于等于maxk,无需删除，直接退出
	  return OK;
	while(p&&p->data<=mink)   //跨过前面的小于mink的部分
	  q=p,p=p->next;
	if(p==NULL)   //链表中的最大值小于等于mink,无需删除
	  return OK;
	while(p&&p->data<maxk){
		s=p->next;
		free(p);
		p=s;
	}//删除并释放结点
	q->next=p;
}
//最好情况下，算法复杂度为O(1),最坏情况下，算法复杂度为O(n)

LinkList *CreateList_L(int n);
Status DeleSq(LinkList *L,ElemType mink,ElemType maxk);

//主函数测试
int main(){
	LinkList *p,*q,*r,*s;
	LinkList *p1,*q1,*r1,*s1;
	//对链表初始化并赋值
	p=CreateList_L(20);
	q=CreateList_L(30);
	r=CreateList_L(15);
	s=CreateList_L(10);
	p1=p,q1=q,r1=r,s1=s;

	printf("Before Dete,La:\n");    //删除中间部分
	for(;p->next;)
	  printf("%d\t",p->next->data),p=p->next;
	printf("\n");
	DeleSq(p1,6,12);
	printf("After delete data between 6-12,La:\n");
	for(;p1->next;)
	  printf("%d\t",p1->next->data),p1=p1->next;
	printf("\n\n");

	printf("Before Dele,Lb:\n");//删除起始部分
	for(;q->next;)
	  printf("%d\t",q->next->data),q=q->next;
	printf("\n");
	DeleSq(q1,-5,10);
	printf("After delete data between -5 - 10,Lb:\n");
	for(;q1->next;)
	  printf("%d\t",q1->next->data),q1=q1->next;
	printf("\n\n");

	printf("Before Dele,Lc:\n");//删除结尾部分
	for(;r->next;)
	  printf("%d\t",r->next->data),r=r->next;
	printf("\n");
	DeleSq(r1,10,20);
	printf("After delete data between 10-20,Lc:\n");
	for(;r1->next;)
	  printf("%d\t",r1->next->data),r1=r1->next;
	printf("\n\n");

	printf("Before Dele,Ld:\n");//不删除
	for(;s->next;)
	  printf("%d\t",s->next->data),s=s->next;
	printf("\n");
	DeleSq(s1,10,20);
	printf("After delete data between 10-20,Ld:\n");
	for(;s1->next;)
	  printf("%d\t",s1->next->data),s1=s1->next;

	printf("\n\n");
	return 0;
}

