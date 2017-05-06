/*4.21*/
#include<stdio.h>
#include<stdlib.h>

//宏定义
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的分配增量
typedef char ElemType;

typedef struct Lnode{
	  ElemType data; /* 数据域,保存结点的值 */
	  struct Lnode *next; /* 指针域 */	  
}LinkList,Lnode;/* 结点的类型 */

LinkList *CreateList_L(int n) {
	// // 建立带表头结点的单链表 L
	LinkList *L,*p; int i;
	 // 先建立一个带头结点的空单链表
	L = (LinkList *)malloc(sizeof(Lnode));
	L->next = NULL;
	for (i=n; i>0; --i) {
		p = (LinkList *)malloc(sizeof(Lnode)); // 生成新结点
		p->data = ' ';
		p->next = L->next; L->next = p; // 插入到表头
	}
	return L;
} // CreateList_L

int StrAssign(LinkList *t,char *s){
	while(*s!='\0'&&t->next!=NULL)
	  t->next->data = *s, s++, t = t->next; /*assign*/
	if(*s!='\0'){ /*list length less than string length*/
		Lnode *q=t,*p;
		while(*s!='\0'){
			p = (LinkList *)malloc(sizeof(Lnode)); /*new locate*/
			if(!p)   return ERROR; /*存储分配失败*/
			p->data=*s;
			p->next=NULL;
			q->next=p;
			q=p;
			s++;
		}
		p = (LinkList *)malloc(sizeof(Lnode)); 
		if(!p) return ERROR; /*存储分配失败*/
		p->data='\0';
		p->next=NULL;
		q->next=p;
	}
	else{
		t->next->data='\0';
	}
	return OK;
}

int StrCopy(LinkList *s,LinkList *t){ /*把字符串t复制到字符串s中*/
	while(s->next!=NULL&&t->next->data!='\0'){
		s->next->data=t->next->data;
		s=s->next,t=t->next;
	}
	if(t->next->data!='\0'){
		Lnode *q=s,*p;
		while(t->next->data!='\0'){
			p=(LinkList *)malloc(sizeof(Lnode));
			if(!p) return ERROR;
			p->data=t->next->data;
			p->next=NULL;
			q->next=p;
			q=p;
			t=t->next;
		}
		p=(LinkList *)malloc(sizeof(Lnode));
		if(!p)  return ERROR;
		p->data='\0';
		p->next=NULL;
		q->next=p;
	}
	else
	  s->next->data='\0';
	return OK;
}

int StrCompare(LinkList *s,LinkList *t){ /*比较两字符串s和t的大小,s>t,返回1,否则返回0*/
	while(s->next->data!='\0'&&t->next->data!='\0'&&s->next->data==t->next->data)
	  s=s->next, t=t->next;
	if(s->next->data=='\0'&&t->next->data=='\0')
	  return -1;
	else if(s->next->data!='\0'&&t->next->data=='\0')
	  return 1;
	else if(s->next=='\0'&&t->next!='\0')
	  return 0;
	else{
		if(s->next->data>t->next->data)
		  return 1;
		else
		  return 0;
	}
}

int StrLength(LinkList *s){ /*return the length of the string s*/
	int length=0;
	while(s->next->data!='\0')
	  length++, s = s->next;
	return length;
}

LinkList *Concat(LinkList *s,LinkList *t){ /*返回由s,t拼接的串*/
	int m=StrLength(s),n=StrLength(t);
	LinkList *p=CreateList_L(m+n+1); //多余的一个长度存'\0'
	LinkList *q=p;

	while(s->next->data!='\0'){
		p->next->data=s->next->data;
		p=p->next;
		s=s->next;
	}
	while(t->next->data!='\0'){
		p->next->data=t->next->data;
		p=p->next;
		t=t->next;
	}
	p->next->data='\0';
	return q;
}

LinkList *SubString(LinkList *s,int start,int len){ /*返回从start开始长度为len的子串*/
	int s_len=StrLength(s);
	if ( start<1||start>s_len||len<1||len>s_len-start+1 ) { /*参数不符合条件*/
		return NULL;
	}
	LinkList *p=CreateList_L(len+1);
	LinkList *q=p;
	for ( int i = 0; i < start; i++ ) {
		s=s->next;
	}
	for ( int j = 0; j < len; j++ ) {
		p->next->data=s->data;
		p=p->next;
		s=s->next;
	}
	p->next->data='\0';
	return q;
}

void PrintS(LinkList *s){ /*打印串*/
	while ( s->next->data!='\0' ) {
		printf("%c",s->next->data);
		s = s->next;
	}
	printf( "\n" );
}
/*函数声明*/
LinkList *CreateList_L(int n);
int StrAssign(LinkList *t,char *s);
int StrCompare(LinkList *s,LinkList *t);
int StrCopy(LinkList *s,LinkList *t);
int StrLength(LinkList *s);
LinkList *Concat(LinkList *s,LinkList *t);
LinkList *SubString(LinkList *s,int start,int len);
void PrintS(LinkList *s);
//main 函数
int main( int argc, char **argv ) {
	ElemType s1[30],s2[40];
	printf( "Please enter s1:\n" );
	scanf("%s",s1);
	printf( "Please enter s2:\n" );
	scanf("%s",s2);
	printf( "\n" );
	
	LinkList *s=CreateList_L(LIST_INIT_SIZE);
	LinkList *t=CreateList_L(LIST_INIT_SIZE);
	StrAssign(t,s2);
	StrAssign(s,s1);
	printf( "After assign s=s1, s:\n" );
	PrintS(s);
	printf( "\n" );
	printf( "After assign t=s2, t:\n" );
	PrintS(t);
	printf( "\n" );

	int len_s=StrLength(s),len_t=StrLength(t);
	printf( "length of s = %d, length of t = %d\n\n",len_s,len_t );

	int judge=StrCompare(s,t);
	printf( "s %c t\n\n",(judge==1)?'>':(judge==-1)?'=':'<' );

	LinkList *cat = Concat(s,t);
	printf( "cat = s+t:\n" );
	PrintS(cat);
	printf( "\n" );
	
	LinkList *substr = SubString(s,3,6);
	printf( "substr(s,3,6):\n" );
	PrintS(substr);
	printf( "\n" );

	StrCopy(s,t);
	printf( "After copy t to s, s:\n" );
	PrintS(s);

	return 0;
}
