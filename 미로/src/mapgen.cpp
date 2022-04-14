#include<windows.h>
#define MAP 15

const int DIR[4][2] = {{0,-2},{0,2},{-2,0},{2,0}};

typedef enum Direction{
   LEFT,UP,RIGHT,DOWN
} Direction;
typedef enum MapFlag{
   WALL,EMPTY,VISITED
} MapFlag;

COORD getRandomStartingPoint(){
int x=1+rand()%(MAP-1);
	int y=1+rand()%(MAP-1);
	if (x%2==0) x--;
	if (y%2==0) y--;
	return(COORD){x,y};
}

int inRange(int y,int x){
	return(y<MAP-1&&y>0)&&(x<MAP-1&&x>0);
}
void shuffleArray(int array[],int size){
	int i,r,temp;
	for (i=0;i<(size-1);++i){
      r=i+(rand()%(size-i));
      temp=array[i];
      array[i]=array[r];
      array[r]=temp;
   }
}
void generateMap(int y,int x,int map[MAP][MAP]){
   int i,nx,ny;
   int directions[4]={
      UP,RIGHT,DOWN,LEFT
   };
   map[y][x]=VISITED;
   shuffleArray(directions, 4);
   for(i=0;i<4;i++){
      nx=x+DIR[directions[i]][0];
      ny=y+DIR[directions[i]][1];
      if(inRange(ny,nx)&&map[ny][nx]==WALL){
         generateMap(ny,nx,map);
         if(ny!=y) map[(ny+y)/2][x]=EMPTY;
         else map[y][(x+nx)/2]=EMPTY;
         map[ny][nx]=EMPTY;
      }
   }
}	

