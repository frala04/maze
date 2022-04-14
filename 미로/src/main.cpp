#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include"winset.h"
#include"file.h"
#include"maze.h"
#include"mapgen.h"

#define U 72
#define L 75
#define R 77
#define D 80
#define enter 13
#define esc 27
#define MAP 15

time_t t1; 
int d,o,O/*입력*/,p=0/*도착확인*/,q/*랜덤*/,r/*리플*/;
int m=1,n=1,/*이동*/i=0/*선택*/,c=0,t2=t1/*시간*/,z/*커서이동*/;
int t[MAP][MAP]/*좌표*/;

typedef enum MapFlag{
   WALL,EMPTY,VISITED
} MapFlag;

void random(){
	int j=0;
	int map[MAP][MAP];
	COORD startPoint=getRandomStartingPoint();
	srand((unsigned int)time(NULL));
	memset(map,WALL,sizeof(map));
	generateMap(startPoint.Y,startPoint.X, map);
	for (int i=0;i<MAP;++i)
		for (int j=0;j<MAP;++j)
			t[i][j]=map[i][j]==WALL;
	t[1][1]=4;
	t[MAP-2][MAP-2]=2;
}
void print(){
	int a=0,b=0;
	system("cls");
	printf("           미로찾기\n  클리어 횟수 : %d  시간\n",file_read()); 
	for(a=0;a<MAP;puts(""),a++)
		for(b=0;b<MAP;b++){
	    	if(t[a][b]==0) printf("  ");
	    	else if(t[a][b]==4) printf("●");
	    	else if(t[a][b]==2) printf("○");
	    	else if(t[a][b]==1) {color(34);printf("  ");color(15);}
	        else printf("%d ",t
			[a][b]);
		}
}
void in_game_move(){
	if(kbhit()){ 
		o=getch();
   		gotoxy(n*2,m+2);
   		t[m][n]=0;
    	printf("  ");
			switch(o){
			case U:
				if(t[m-1][n]!=1) m--;
       	  			break;
    		case L:
       	 		if(t[m][n-1]!=1) n--;
       	 	 		break;
			case R:
       		 	if(t[m][n+1]!=1) n++;
       		  		break;
      		case D:
       	 	 	if(t[m+1][n]!=1) m++;
      				break;
      		case esc:
      			d=pause_ment();
      		default:
    	   	  	break;
		}
		gotoxy(n*2,m+2);
  		printf("●");
  		if(t[m][n]!=2) t[m][n]=4;
		if(t[m][n]==2) i=1;
		if(d==11) i=2;
		if(d==10){
			system("cls");
			print();
			d=0;
		}
	}
}
void time_count(){
	t2=t1;
	t1=time(NULL);
	if(t1>t2){
		gotoxy(26,1);
		printf("%d",c);
		c++;
	}	
}

int main()
{
	winset(MAP);
	cursoroff();
	while(1){
    	while(1){
    		system("cls");
    		start_ment();
    		i=start_select();
    		if(i==0) break;
    		else if(i==1) exit(0);
    		else if(i==2) info_ment();
		}
    	while(1){
			random();
    	    print();
			c=0;m=1;n=1;
    	    while(1){
    	    	time_count();
    	        in_game_move();
    	        if(i==1) break;
				if(i==2) break;
       		}
        	if(i==2) break;
       		end_ment(c,m,n);
			file_write();
        	i=end_select();
        	if(i==1) break;
    	}
	}
}
