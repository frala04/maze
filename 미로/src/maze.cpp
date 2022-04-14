#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"winset.h"
#include"file.h"
#define U 72
#define L 75
#define R 77
#define D 80
#define enter 13
int print(int (*x)[15]){
	system("cls");
	printf("          미로찾기\n       방향키로 이동\n"); 
	for(int a=0;a<15;puts(""),a++)
		for(int b=0;b<15;b++)
		{
	    	if(x[a][b]==0) printf("  ");
	    	else if(x[a][b]==4) printf("●");
	    	else if(x[a][b]==2) printf("○");
	    	else if(x[a][b]==1) {color(34);printf("  ");color(15);}
	        else printf("%d ",x[a][b]);
		}
}
int updownselect(int x,int y,int a,int b){/*시작x,y,a~b범위*/ 
	int o;
	while(1){
		gotoxy(y,x);
		o=getch();
		printf(" ");
		if(o==U&&x>a) x--;
		else if(o==D&&x<b) x++;
		else if(o==enter) break;
		gotoxy(y,x);
		printf(">");
	}
	return x;
}
void start_ment(){
	printf("\n           미로찾기\n\n\n\n\n\n\n");
	printf("           > 시작");
	printf("\n             종료");
	printf("\n             정보");
}
int start_select(){
	int z=9, i=0;
	z=updownselect(8,11,8,10);
	if(z==8) return 0;
	else if(z==9) return 1;
	else if(z==10) return 2;
}
int end_ment(int c,int m,int n){
   	gotoxy(n,m);
   	printf("●");
   	system("cls");
    printf("\n\n\n\n\n\n\n             ㅊㅊ\n        소요 ");
	printf("시간 : %d초\n           다시하실?",c); 
	printf("\n\n             > O"); 
	printf("\n               X");
  	gotoxy(11,11);
}
int end_select(){
	int z=11;
	z=updownselect(11,13,11,12);
	if(z==11) return 0;
	else if(z==12) return 1;
}
int pause_ment(){
	int O=0;
	system("cls");
	printf("\n\n           일시정지");
	printf("\n\n\n\n\n\n\n\n         > 계속하기");
	printf("\n           게임종료");
	return updownselect(10,9,10,11);
}
void info_ment(){
	int o;
	system("cls");
	printf("\n\n        made by ㄱㅅㅁ\n\n");
	printf("\n          게임 방법");
	printf("\n\n    방향키로 이동 및 선택.\n\n\n\n");
	printf("\n         > 돌아가기");
	while(1){
		o=getch();
		if(o==enter) break;
	}
}
