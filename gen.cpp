#include "globals.h"

extern int moves,captures;
extern char algebraic[32][3];
extern int history[32][32];

int jumps;
int start;
int capturing_piece;
int xply;
int first_cap[40];

void Makecapture(const int from,const int to);
void UnMakecapture(const int from,const int to);

int RMCapture(const int sq);
int RKCapture(const int sq);
int BMCapture(const int sq);
int BKCapture(const int sq);

void GenMoveRM(const int s,const int sq);
void GenMoveRK(const int s,const int sq);
void GenMoveBM(const int s,const int sq);
void GenMoveBK(const int s,const int sq);

int GenCaptures(const int s)
{
	int sq;
	int jumps = 0;
captures = 0;
firstmove[ply+1] = firstmove[ply];//
if(s==LIGHT_PLAYER)
{
for(int x = 0;x<32;x++)
if(board[x]<0)
{
	sq = x;
	start = sq;
	capturing_piece = board[sq];
	jumps = 0;
	xply = 0;
	first_cap[0] = 0;
	first_cap[1] = 0;
	GenCapture(s,sq);
	board[sq] = capturing_piece;
}
}
else
{
for(int x = 0;x<32;x++)
if(board[x]>0)
{
	sq = x;
	start = sq;
	capturing_piece = board[sq];
	jumps = 0;
	xply = 0;
	first_cap[0] = 0;
	first_cap[1] = 0;
	GenCapture(s,sq);
	board[sq] = capturing_piece;
}
}
firstmove[ply+1] = firstmove[ply] + captures;
return captures;
}

int GenCapture(const int s,const int sq)
{
if(s==DARK)
{
if(edge[squares[sq].nw]==0 && (board[squares[sq].nw]==RM || board[squares[sq].nw]==RK) && board[squares[sq].nw2] == 0)
  AddCapture(squares[sq].nw,squares[sq].nw2);
if(edge[squares[sq].ne]==0 && (board[squares[sq].ne]==RM || board[squares[sq].ne]==RK) && board[squares[sq].ne2] == 0)
  AddCapture(squares[sq].ne,squares[sq].ne2);
if(capturing_piece==BLACK_KING)
{
if(edge[squares[sq].sw]==0 && (board[squares[sq].sw]==RM || board[squares[sq].sw]==RK) && board[squares[sq].sw2] == 0)
  AddCapture(squares[sq].sw,squares[sq].sw2);
if(edge[squares[sq].se]==0 && (board[squares[sq].se]==RM || board[squares[sq].se]==RK) && board[squares[sq].se2] == 0)
  AddCapture(squares[sq].se,squares[sq].se2);
}
}
else
{
if(edge[squares[sq].sw]==0 && (board[squares[sq].sw]==BM || board[squares[sq].sw]==BK) && board[squares[sq].sw2] == 0)
  AddCapture(squares[sq].sw,squares[sq].sw2);
if(edge[squares[sq].se]==0 && (board[squares[sq].se]==BM || board[squares[sq].se]==BK) && board[squares[sq].se2] == 0)
  AddCapture(squares[sq].se,squares[sq].se2);
if(capturing_piece==RED_KING)
{
if(edge[squares[sq].nw]==0 && (board[squares[sq].nw]==BM || board[squares[sq].nw]==BK) && board[squares[sq].nw2] == 0)
  AddCapture(squares[sq].nw,squares[sq].nw2);
if(edge[squares[sq].ne]==0 && (board[squares[sq].ne]==BM || board[squares[sq].ne]==BK) && board[squares[sq].ne2] == 0)
  AddCapture(squares[sq].ne,squares[sq].ne2);  
}
}
//
if(first_cap[xply]==first_cap[xply+1])//no captures
{
if(xply>0)
{
//	if(capturelist[first_cap[xply-1]].to != sq)
//		z();
movelist[firstmove[ply] + captures].from = start;
movelist[firstmove[ply] + captures].to = sq;//capturelist[first_cap[xply-1]].to;
movelist[firstmove[ply] + captures].jumps = xply;
for(int y=0;y<xply;y++)
{
	movelist[firstmove[ply] + captures].between[y] = capturelist[y].between;
	movelist[firstmove[ply] + captures].captured[y] = capturelist[y].captured;
}
captures++;
}
return 0;
}
int from,to,bet;
int startmove = first_cap[xply];
int endmove = first_cap[xply+1];

for(int x = startmove;x < endmove; x++)
{
	to = capturelist[x].to;
	bet = capturelist[x].between;
	xply++;
	first_cap[xply+1] = first_cap[xply];
	GenCapture(s,to);
	xply--;
	board[bet] = capturelist[x].captured;
}

return 0;
}

int AddCapture(const int between,const int to)
{
capturelist[first_cap[xply+1]].to = to;
capturelist[first_cap[xply+1]].between = between;
capturelist[first_cap[xply+1]].captured = board[between];
board[between] = 0;
first_cap[xply+1]++;
return 0;
}

int GenMoves(const int s)
{
moves = 0;
firstmove[ply+1] = firstmove[ply];
if(s==LIGHT_PLAYER)
{
for(int x= 0;x<32;x++)
{
  if(board[x]==RM)
    GenMoveRM(s,x);
  else if(board[x]==RK)
	GenMoveRK(s,x);
}
}
else
{
for(int x= 0;x<32;x++)
{
  if(board[x]==BM)
    GenMoveBM(s,x);
  else if(board[x]==BK)
	GenMoveBK(s,x);
}
}
firstmove[ply + 1] = firstmove[ply] + moves;
return moves;
}

void GenMoveRM(const int s,const int sq)
{
if(board[squares[sq].sw] == 0)
  AddMove(sq,squares[sq].sw);
if(board[squares[sq].se] == 0)
  AddMove(sq,squares[sq].se);
}

void GenMoveRK(const int s,const int sq)
{
if(board[squares[sq].sw] == 0)
  AddMove(sq,squares[sq].sw);
if(board[squares[sq].se] == 0)
  AddMove(sq,squares[sq].se);
if(board[squares[sq].nw] == 0)
  AddMove(sq,squares[sq].nw);
if(board[squares[sq].ne] == 0)
  AddMove(sq,squares[sq].ne);
}

void GenMoveBM(const int s,const int sq)
{
if(board[squares[sq].nw] == 0)
  AddMove(sq,squares[sq].nw);
if(board[squares[sq].ne] == 0)
  AddMove(sq,squares[sq].ne);
}

void GenMoveBK(const int s,const int sq)
{
if(board[squares[sq].nw] == 0)
  AddMove(sq,squares[sq].nw);
if(board[squares[sq].ne] == 0)
  AddMove(sq,squares[sq].ne);
if(board[squares[sq].sw] == 0)
  AddMove(sq,squares[sq].sw);
if(board[squares[sq].se] == 0)
  AddMove(sq,squares[sq].se);
}

void AddMove(const int from, const int to)
{
movelist[firstmove[ply] + moves].from = from;
movelist[firstmove[ply] + moves].to = to;
movelist[firstmove[ply] + moves].jumps = 0;
movelist[firstmove[ply] + moves].score = history[from][to];
moves++;
}

int AnyCaptures(const int s)
{
if(s==LIGHT_PLAYER)
{
for(int sq = 0;sq<32;sq++)
{
if(board[sq]==RM)
{
	if(RMCapture(sq))
		return 1;
}
if(board[sq]==RK)
{
	if(RKCapture(sq))
		return 1;
}
}
}
else
{
for(int sq = 0;sq<32;sq++)
{
if(board[sq]==BM)
{
	if(BMCapture(sq))
		return 1;
}
if(board[sq]==BK)
{
	if(BKCapture(sq))
		return 1;
}
}
}
return 0;
}

int RMCapture(const int sq)
{
if(edge[squares[sq].sw]==0 && (board[squares[sq].sw]==BM || board[squares[sq].sw]==BK) && board[squares[sq].sw2] == 0)
  return 1;
if(edge[squares[sq].se]==0 && (board[squares[sq].se]==BM || board[squares[sq].se]==BK) && board[squares[sq].se2] == 0)
  return 1;
return 0;
}

int RKCapture(const int sq)
{
if(edge[squares[sq].sw]==0 && (board[squares[sq].sw]==BM || board[squares[sq].sw]==BK) && board[squares[sq].sw2] == 0)
  return 1;
if(edge[squares[sq].se]==0 && (board[squares[sq].se]==BM || board[squares[sq].se]==BK) && board[squares[sq].se2] == 0)
  return 1;
if(edge[squares[sq].nw]==0 && (board[squares[sq].nw]==BM || board[squares[sq].nw]==BK) && board[squares[sq].nw2] == 0)
  return 1;
if(edge[squares[sq].ne]==0 && (board[squares[sq].ne]==BM || board[squares[sq].ne]==BK) && board[squares[sq].ne2] == 0)
  return 1; 
return 0;
}

int BMCapture(const int sq)
{
if(edge[squares[sq].nw]==0 && (board[squares[sq].nw]==RM || board[squares[sq].nw]==RK) && board[squares[sq].nw2] == 0)
  return 1;
if(edge[squares[sq].ne]==0 && (board[squares[sq].ne]==RM || board[squares[sq].ne]==RK) && board[squares[sq].ne2] == 0)
  return 1;
return 0;
}

int BKCapture(const int sq)
{
if(edge[squares[sq].nw]==0 && (board[squares[sq].nw]==RM || board[squares[sq].nw]==RK) && board[squares[sq].nw2] == 0)
  return 1;
if(edge[squares[sq].ne]==0 && (board[squares[sq].ne]==RM || board[squares[sq].ne]==RK) && board[squares[sq].ne2] == 0)
  return 1;
if(edge[squares[sq].sw]==0 && (board[squares[sq].sw]==RM || board[squares[sq].sw]==RK) && board[squares[sq].sw2] == 0)
  return 1;
if(edge[squares[sq].se]==0 && (board[squares[sq].se]==RM || board[squares[sq].se]==RK) && board[squares[sq].se2] == 0)
  return 1;
return 0;
}

