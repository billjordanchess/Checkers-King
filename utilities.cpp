#include "globals.h"

int LoadDiagram(char* file);
void CloseDiagram();
void SaveDiagram(char* file);

FILE *diagram_file;
char fen_name[256];

int LoadDiagram(char* file)
{
int x,n=0;
char ts[200];

diagram_file = fopen(file, "r");
if (!diagram_file)
{
	printf("Diagram missing.\n");
	return -1;
}

strcpy_s(fen_name,file);

fgets(ts, 256, diagram_file);

//[FEN "B:W18,24,27,28,K10,K15:B12,16,20,K22,K25,K29"]

for(x=0;x<121;x++)
{
	board[x]= ts[x] - 48;
}
if(ts[121]=='1')
	side = 1;
else
	side = 2;

CloseDiagram();
DisplayBoard(0,0);
return 0;
}

void CloseDiagram()
{
if (diagram_file)
    fclose(diagram_file);
diagram_file = NULL;
}

void SaveDiagram(char* file)
{
	printf("save");
	diagram_file = fopen(file, "w");
if (!diagram_file)
{
  printf("Diagram missing.\n");
  return;
}

char a[3];
char b[128] = "[FEN \"";
if(side==1)
  strcat(b,"W:W");
else
  strcat(b,"B:W");

int wc=0,bc=0;

for(int x=0;x<32;x++)
{
	if(board[x]==RM)
	{
		if(wc>0)
			strcat(b,",");
		strcat(b,itoa(x,a,10));
		wc++;
	}
	if(board[x]==RK)
	{
		if(wc>0)
			strcat(b,",");
		strcat(b,"K");
		strcat(b,itoa(x,a,10));
		wc++;
	}	
}
strcat(b,":B");
for(int x=0;x<32;x++)
{
	if(board[x]==BM)
	{
		if(bc>0)
			strcat(b,",");
		strcat(b,itoa(x,a,10));
		bc++;
	}
	if(board[x]==BK) 
	{
		if(bc>0)
			strcat(b,",");
		strcat(b,"K");
		strcat(b,itoa(x,a,10));
		bc++;
	}		
}

strcat(b,"\"]");
//[FEN "B:W18,24,27,28,K10,K15:B12,16,20,K22,K25,K29"]

fwrite(b,sizeof(char), sizeof(b),diagram_file);

if (diagram_file)
    fclose(diagram_file);
diagram_file = NULL;

}