/*
int CaptureNWSquares[12] = {2,3,6,7,10,11,14,15,18,19,23,2};
int CaptureNESquares[12] = {0,1,4,5,8,9,12,13,16,17,20,21};
int CaptureSWSquares[12] ={10,11,14,15,18,19,22,23,26,27,30,31};
int CaptureSESquares[12] = {8,9,12,13,16,17,20,21,24,25,28,29};

int GenCaptures()
{
int sq;
captures = 0;

if(side==0)
{
for(int x=0;x<12;x++)
{
	sq = CaptureNWSquares[x];
if(board[sq] > 0 && board[sq+3] < 0 && board[sq+7] == 0) 
{  
  AddCapture(sq,sq+6);
} 
sq = CaptureNESquares[x];
if(board[sq] > 0 && board[sq+4] < 0 && board[sq+9] == 0) 
{  
  AddCapture(sq,sq+6);
}
sq = CaptureSWSquares[x];
if(board[sq] == 2 && board[sq-3] < 0 && board[sq-7] == 0) 
{  
  AddCapture(sq,sq-6);
} 
sq = CaptureSESquares[x];
if(board[sq] == 2 && board[sq-4] < 0 && board[sq-9] == 0) 
{  
  AddCapture(sq,sq-8);
} 
}
}
if(side == 1)
{
for(int x=0;x<12;x++)
{
	sq = CaptureSWSquares[x];
if(board[sq] < 0 && board[sq-3] > 0 && board[sq-7] == 0) 
{  
  AddCapture(sq,sq-6);
} 
sq = CaptureSESquares[x];
if(board[sq] < 0 && board[sq-4] > 0 && board[sq-9] == 0) 
{  
  AddCapture(sq,sq-6);
}
sq = CaptureNWSquares[x];
if(board[sq] == -2 && board[sq+3] > 0 && board[sq+7] == 0) 
{  
  AddCapture(sq,sq+6);
} 
sq = CaptureNESquares[x];
if(board[sq] == -2 && board[sq+4] > 0 && board[sq+9] == 0) 
{  
  AddCapture(sq,sq+8);
} 
}
}
return captures;
}
*/