#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
void cursoroff(){
   CONSOLE_CURSOR_INFO cursorInfo={0,};
   cursorInfo.dwSize=1;
   cursorInfo.bVisible=FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursorInfo);
}

void color(int n){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}

void gotoxy(int x,int y){
   COORD pos;
   pos.X=x;
   pos.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

void winset(int x){
	char command[256]={'\0',};
	int lines=x+3;
	int cols=2*x;
	sprintf(command,"mode con: lines=%d cols=%d | title 미로찾기",lines,cols);
	system(command);
}
