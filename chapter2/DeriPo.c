//2.41
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0

typedef int Status;
//结点的类型定义
typedef struct node{
	int c; // 多项式,系数
	int e; // 多项式,指数
	struct node *next;

}Polynomial;

// 输入 m 项的系数和指数,建立表示一元多项式的有序链表P
Polynomial *Create(int m){
	Polynomial *head,*p,*q; 
	int i;
  // 生成头结点;
    p=head=(Polynomial*) malloc(sizeof(Polynomial));
	if(!p)
	  return ERROR;//存储分配失败
	for(i=1;i<=m;i++){ // 依次输入 m 个非零项
		q=(Polynomial *)malloc(sizeof(Polynomial));
		if(!q)
		  return ERROR;//存储分配失败
		printf("Please enter two number refer to coefficient and exponential respectively:");
		scanf("%d %d",&q->c,&q->e);
		p->next = q;
		p=q;
	}
	p->next=NULL;
	return head;
} //Create

//求导
Status DeriPo(Polynomial *head){
	Polynomial *p,*q,*r;
	q=head;
	p=head->next;
	while(p){
		if(p->e!=0){//指数不为0
			p->c*=p->e, --p->e;//系数乘于指数，然后指数减１
			q=p,p=p->next;
		}
		else{//指数为0
			r=p,p=p->next;
			free(r);//释放节点
		}
	}
	return OK;
}

//输出多项式
Status OutputPoly(Polynomial *head){
	Polynomial *p;
	p=head;
	printf("F(x)=");
	while(p->next){
		if(p->next->c!=0&&p->next->e!=0)//系数和指数均不为0
		  printf(" %dx^%d %c",p->next->c,p->next->e,(p->next->next)?'+':' ');
		else if(p->next->c!=0&&p->next->e==0)//系数不为0,指数为0
		  printf(" %d %c",p->next->c,(p->next->next)?'+':' ');
		else  //指数和系数均为0
		  ;
		p=p->next;
	}
	printf("\n");
	return OK;
}
//函数声明
Polynomial *Create(int m);
Status DeriPo(Polynomial *head);
Status OutputPoly(Polynomial *head);

//main函数测试
int main(){
	int m;
	Polynomial *head;
	printf("Please enter the degree of polynomial:");
	scanf("%d",&m);
	printf("\n");
	head = Create(m);
	//求导前
	printf("\nBefore Deri:\n");
	OutputPoly(head);
   //求导
	DeriPo(head);
	//求导后
	printf("\nAfter Deri:\n");
	OutputPoly(head);
	return 0;
}
