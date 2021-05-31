#include "globals.h"

int Eval();
int CountMoves(const int s,const int sq);

int mc[2];

int king[32]=
{
0,0,0,0,
2,6,6,0,
0,8,8,2,
2,8,8,0,
0,8,8,2,
2,8,8,0,
0,6,6,2,
0,0,0,0
};

int red_piece[32]=
{
0,0,0,0,
4,4,4,4,
3,3,3,3,
2,2,2,2,
1,1,1,1,
0,0,0,0,
0,0,0,0,
0,0,0,0
};

int black_piece[32]=
{
0,0,0,0,
0,0,0,0,
0,0,0,0,
1,1,1,1,
2,2,2,2,
3,3,3,3,
4,4,4,4,
0,0,0,0
};

int Eval()
{
int score[2] = {0,0};
mc[0]=0;mc[1]=0;
for(int x=0;x<32;x++)
{
switch(board[x])
{
case RED_MAN: score[LIGHT] += 20 + CountMoves(LIGHT,x) + red_piece[x];break;
case RED_KING: score[LIGHT] += 30 + CountMoves(LIGHT,x) + king[x];break;
case BLACK_MAN: score[DARK] += 20 + CountMoves(DARK,x) + black_piece[x];break;
case BLACK_KING: score[DARK] += 30 + CountMoves(DARK,x) + king[x];break;
default: break;
}
}
if(score[xside]==0)
{
	return 1000 - ply;
}
if(score[side]==0)
{
	return -1000 + ply;
}

return score[side] - score[xside];
}

int CountMoves(const int s,const int sq)
{
	int c=0;
if(s==DARK || board[sq]==RED_KING)
{
if(board[squares[sq].nw] == 0)
  c++;
if(board[squares[sq].ne] == 0)
  c++;
}
if(s==LIGHT || board[sq]==BLACK_KING)
{
if(board[squares[sq].sw] == 0)
  c++;
if(board[squares[sq].se] == 0)
  c++;
}
return c;
}

