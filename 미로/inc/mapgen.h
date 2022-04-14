#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#define U 72
#define L 75
#define R 77
#define D 80
#define enter 13
#define MAP 15
#define esc 27
COORD getRandomStartingPoint();
int inRange(int y,int x);
void shuffleArray(int array[],int size);
void generateMap(int y,int x,int map[MAP][MAP]);
