//3.21
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COLUMN 10

int Pic[ROW][COLUMN]={
	0,1,2,6,7,9,1,5,6,8,
	2,4,7,8,9,0,1,2,3,5,
	4,5,7,7,9,0,1,2,4,6,
	7,6,7,8,9,0,1,2,5,2,
	4,7,7,5,1,0,4,5,6,1,
	4,5,7,7,7,4,1,6,3,7,
	1,4,4,6,7,8,1,6,5,3,
	1,2,4,7,7,7,8,1,2,3,
	1,4,5,6,7,8,9,0,1,4,
	4,5,6,8,9,1,4,6,8,1,
};
//打印图片,未置换的地方直接打印数字，置换的地方打印&
void PrintPic(int n[][COLUMN]){
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COLUMN;j++){
			if(n[i][j]>=0&&n[i][j]<10)
			  printf("%d ",n[i][j]);
			else
			  printf("%c ",'&');
		}
		printf("\n");
	}
}

//递归置换颜色
int ChangeColor(int n[][COLUMN],int x,int y,int cl){
	if(n[x][y]!=cl)
	  return 1;
	else{
		n[x][y]=10;//颜色相同则换成10,然后在不超边界的情况下递归往四个方向搜索
		if(x+1<ROW)
		  ChangeColor(n,x+1,y,cl);
		if(x-1>-1)
		  ChangeColor(n,x-1,y,cl);
		if(y+1<COLUMN)
		  ChangeColor(n,x,y+1,cl);
		if(y-1>-1)
		  ChangeColor(n,x,y-1,cl);
		return 1;

	}
}

void PrintPic(int n[][COLUMN]);
int ChangeColor(int n[][COLUMN],int x,int y,int cl);
//main函数
int main(){
	int x,y;

	printf("Before change color:\n");
	PrintPic(Pic);
	
	printf("Enter the coordnate:\n");
	scanf("%d%d",&x,&y);
	
	int color=Pic[x][y];
	ChangeColor(Pic,x,y,color);
	
	printf("After Change color:\n");
	PrintPic(Pic);
	return 0;
}
