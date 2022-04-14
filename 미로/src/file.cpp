#include<stdio.h>
#include<stdlib.h>

char R2[50]={}/*읽기변수*/;
int R1/*읽기*/;

int file_read(){
	FILE *fread=fopen("count.txt","r");
	if(fread==NULL){
		FILE*fmake=fopen("count.txt","w");
		fprintf(fmake, "0");
		fclose(fmake);
		R1=0;
	}
	else{
		fgets(R2,50,fread);
		R1=atoi(R2);
	}
	fclose(fread);
	return R1;
}

void file_write(){
	sprintf(R2,"%d",++R1);
	FILE*fmake=fopen("count.txt","w");
	fprintf(fmake, R2);
	fclose(fmake);
}
