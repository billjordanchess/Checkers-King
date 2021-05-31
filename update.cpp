#include "globals.h"

void z();

void MakeMove(const int from,const int to)
{
gamelist[ply].from = from;
gamelist[ply].to = to;
gamelist[ply].jumps = 0;
gamelist[ply].last = board[from];
gamelist[ply].fifty++;

board[to] = board[from];
board[from] = EMPTY;
if(board[to]==RED_MAN && rank[to]==0)
{
	board[to] = RED_KING;
}
else if(board[to] == BLACK_MAN && rank[to]==7)
{
	board[to] = BLACK_KING;
}
side ^= 1;
xside ^= 1;
ply++;
hply++;
}

void UnMakeMove()
{
ply--;
hply--;
board[gamelist[ply].from] = gamelist[ply].last;
board[gamelist[ply].to] = EMPTY;
side ^= 1;
xside ^= 1;
}

void MakeCaptures(const int from, const int to,const int jumps,const int last)
{
gamelist[ply].from = from;
gamelist[ply].to = to;
gamelist[ply].last = board[from];
gamelist[ply].jumps = jumps;
gamelist[ply].fifty = 0;

for(int x=0;x<jumps;x++)
{
//gamelist[ply].between[x] = movelist[x].between[y];
gamelist[ply].captured[x] = board[gamelist[ply].between[x]];
board[gamelist[ply].between[x]] = EMPTY;
}

board[to] = board[from];
if(board[to]==RED_MAN && rank[to]==0)
{
	board[to] = RED_KING;
}
else if(board[to] == BLACK_MAN && rank[to]==7)
{
	board[to] = BLACK_KING;
}
board[from] = EMPTY;
ply++;
hply++;
side ^= 1;
xside ^= 1;
}

void UnMakeCaptures()
{
side ^= 1;
xside ^= 1;
ply--;
hply--;
board[gamelist[ply].from] = gamelist[ply].last;
board[gamelist[ply].to] = EMPTY;

for(int x=0;x<gamelist[ply].jumps;x++)
{
board[gamelist[ply].between[x]] = gamelist[ply].captured[x];
}
}

void MakeCapture(const int from,const int between,const int to)
{
gamelist[ply].from = from;
gamelist[ply].to = to;
gamelist[ply].jumps = 0;
gamelist[ply].last = board[from];
gamelist[ply].fifty = 0;

board[to] = board[from];
board[from] = EMPTY;
board[between] = EMPTY;

if(board[to]==RED_MAN && rank[to]==0)
{
	board[to] = RED_KING;
}
else if(board[to] == BLACK_MAN && rank[to]==7)
{
	board[to] = BLACK_KING;
}
}