#include "globals.h"

void SetSquares()
{
for(int x=0;x<32;x++)
{
	squares[x].nw = squares[x].nw2 = x;
	squares[x].ne = squares[x].ne2 = x;
	squares[x].sw = squares[x].sw2 = x;
	squares[x].se = squares[x].se2 = x;
}
squares[0].nw2 = 9; squares[9].se2 = 0;
squares[1].nw2 = 10; squares[10].se2 = 1;
squares[2].nw2 = 11; squares[11].se2 = 2;
squares[1].ne2 = 8; squares[8].sw2 = 1;
squares[2].ne2 = 9; squares[9].sw2 = 2;
squares[3].ne2 = 10; squares[10].sw2 = 3;

//4
squares[4].nw2 = 13; squares[13].se2 = 4;
squares[5].nw2 = 14; squares[14].se2 = 5;
squares[6].nw2 = 15; squares[15].se2 = 6;
squares[5].ne2 = 12; squares[12].sw2 = 5;
squares[6].ne2 = 13; squares[13].sw2 = 6;
squares[7].ne2 = 14; squares[14].sw2 = 7;

//8
squares[8].nw2 = 17; squares[17].se2 = 8;
squares[9].nw2 = 18; squares[18].se2 = 9;
squares[10].nw2 = 19; squares[19].se2 = 10;
squares[9].ne2 = 16; squares[16].sw2 = 9;
squares[10].ne2 = 17; squares[17].sw2 = 10;
squares[11].ne2 = 18; squares[18].sw2 = 11;

//12
squares[12].nw2 = 21; squares[21].se2 = 12;
squares[13].nw2 = 22; squares[22].se2 = 13;
squares[14].nw2 = 23; squares[23].se2 = 14;
squares[13].ne2 = 20; squares[20].sw2 = 13;
squares[14].ne2 = 21; squares[21].sw2 = 14;
squares[15].ne2 = 22; squares[22].sw2 = 15;

//16
squares[16].nw2 = 25; squares[25].se2 = 16;
squares[17].nw2 = 26; squares[26].se2 = 17;
squares[18].nw2 = 27; squares[27].se2 = 18;
squares[17].ne2 = 24; squares[24].sw2 = 17;
squares[18].ne2 = 25; squares[25].sw2 = 18;
squares[19].ne2 = 26; squares[26].sw2 = 19;

//20
squares[20].nw2 = 29; squares[29].se2 = 20;
squares[21].nw2 = 30; squares[30].se2 = 21;
squares[22].nw2 = 31; squares[31].se2 = 22;
squares[21].ne2 = 28; squares[28].sw2 = 21;
squares[22].ne2 = 29; squares[29].sw2 = 22;
squares[23].ne2 = 30; squares[30].sw2 = 23;

squares[0].nw = 4; squares[4].se = 0;
squares[1].nw = 5; squares[5].se = 1;
squares[2].nw = 6; squares[6].se = 2;
squares[3].nw = 7; squares[7].se = 3;
squares[1].ne = 4; squares[4].sw = 1;
squares[2].ne = 5; squares[5].sw = 2; 
squares[3].ne = 6; squares[6].sw = 3; 

squares[4].nw = 9; squares[9].se = 4;
squares[5].nw = 10; squares[10].se = 5;
squares[6].nw = 11; squares[11].se = 6;
squares[4].ne = 8; squares[8].sw = 4;
squares[5].ne = 9; squares[9].sw = 5;
squares[6].ne = 10; squares[10].sw = 6;
squares[7].ne = 11; squares[11].sw = 7;

squares[8].nw = 12; squares[12].se = 8; 
squares[9].nw = 13; squares[13].se = 9;
squares[10].nw = 14; squares[14].se = 10;
squares[11].nw = 15; squares[15].se = 11;
squares[9].ne = 12; squares[12].sw = 9;
squares[10].ne = 13; squares[13].sw = 10;
squares[11].ne = 14; squares[14].sw = 11;

squares[12].nw = 17; squares[17].se = 12;
squares[13].nw = 18; squares[18].se = 13;
squares[14].nw = 19; squares[19].se = 14;
squares[12].ne = 16; squares[16].sw = 12;
squares[13].ne = 17; squares[17].sw = 13;
squares[14].ne = 18; squares[18].sw = 14;
squares[15].ne = 19; squares[19].sw = 15;

squares[16].nw = 20; squares[20].se = 16;
squares[17].nw = 21; squares[21].se = 17;
squares[18].nw = 22; squares[22].se = 18;
squares[19].nw = 23; squares[23].se = 19;
squares[17].ne = 20; squares[20].sw = 17;
squares[18].ne = 21; squares[21].sw = 18;
squares[19].ne = 22; squares[22].sw = 19;

squares[20].nw = 25; squares[25].se = 20;
squares[21].nw = 26; squares[26].se = 21;
squares[22].nw = 27; squares[27].se = 22;
squares[20].ne = 24; squares[24].sw = 20;
squares[21].ne = 25; squares[25].sw = 21;
squares[22].ne = 26; squares[26].sw = 22;
squares[23].ne = 27; squares[27].sw = 23;

squares[24].nw = 28; squares[28].se = 24;
squares[25].nw = 29; squares[29].se = 25;
squares[26].nw = 30; squares[30].se = 26;
squares[27].nw = 31; squares[31].se = 27;
squares[25].ne = 28; squares[28].sw = 25;
squares[26].ne = 29; squares[29].sw = 26;
squares[27].ne = 30; squares[30].sw = 27;

return;
/*

for(int x=0;x<32;x++)
{
	if(rank[x]==0 || rank[2]==0 || rank[4]==0 || rank[6]==0)
	{
		squares[x].nw = x+4; squares[x].nw2 = x+9;
		squares[x].ne = x+3; squares[x].ne2 = x+7;
		squares[x].se = x-4; squares[x].se2 = x-9;
		squares[x].sw = x-3; squares[x].sw2 = x-7;
	}
	else
	{
		squares[x].nw = x+5; squares[x].nw2 = x+9;
		squares[x].ne = x+4; squares[x].ne2 = x+7;
		squares[x].se = x-5; squares[x].se2 = x-9;
		squares[x].sw = x-4; squares[x].sw2 = x-7;
	}
}
for(int x=0;x<32;x++)
{
	if(rank[x]==0)
	{
		squares[x].sw = x;
		squares[x].se = x;
	}
	if(rank[x]==7)
	{
		squares[x].nw = x;
		squares[x].ne = x;
	}
	if(file[x]==0)
	{
		squares[x].ne = x;
		squares[x].se = x;
	}
	if(file[x]==5)
	{
		squares[x].nw = x;
		squares[x].sw = x;
	}
	if(rank[x]<2)
	{
		squares[x].sw2 = x;
		squares[x].se2 = x;
	}
	if(rank[x]>5)
	{
		squares[x].nw2 = x;
		squares[x].ne2 = x;
	}
	if(file[x]==1)
	{
		squares[x].nw2 = x;
		squares[x].sw2 = x;
	}
	if(file[x]==6)
	{
		squares[x].ne2 = x;
		squares[x].se2 = x;
	}
}
*/
}

void SetBoard()
{
for(int x= 0;x<12;x++)
  board[x] = BM;
for(int x= 12;x<20;x++)
  board[x] = 0;
for(int x= 20;x<32;x++)
  board[x] = RM;
}

void SetSquares2()
{
for(int x=0;x<32;x++)
{
	squares[x].nw = squares[x].nw2 = x;
	squares[x].ne = squares[x].ne2 = x;
	squares[x].sw = squares[x].sw2 = x;
	squares[x].se = squares[x].se2 = x;
}
squares[0].nw2 = 9; squares[9].se2 = 0;
squares[1].nw2 = 10; squares[10].se2 = 1;
squares[2].nw2 = 11; squares[11].se2 = 2;
squares[1].ne2 = 8; squares[8].sw2 = 1;
squares[2].ne2 = 9; squares[9].sw2 = 2;
squares[3].ne2 = 10; squares[10].sw2 = 3;

//4
squares[4].nw2 = 13; squares[13].se2 = 4;
squares[5].nw2 = 14; squares[14].se2 = 5;
squares[6].nw2 = 15; squares[15].se2 = 6;
squares[5].ne2 = 12; squares[12].sw2 = 5;
squares[6].ne2 = 13; squares[13].sw2 = 6;
squares[7].ne2 = 14; squares[14].sw2 = 7;

//8
squares[8].nw2 = 17; squares[17].se2 = 8;
squares[9].nw2 = 18; squares[18].se2 = 9;
squares[10].nw2 = 19; squares[19].se2 = 10;
squares[9].ne2 = 16; squares[16].sw2 = 9;
squares[10].ne2 = 17; squares[17].sw2 = 10;
squares[11].ne2 = 18; squares[18].sw2 = 11;

//12
squares[12].nw2 = 21; squares[21].se2 = 12;
squares[13].nw2 = 22; squares[22].se2 = 13;
squares[14].nw2 = 23; squares[23].se2 = 14;
squares[13].ne2 = 20; squares[20].sw2 = 13;
squares[14].ne2 = 21; squares[21].sw2 = 14;
squares[15].ne2 = 22; squares[22].sw2 = 15;

//16
squares[16].nw2 = 25; squares[25].se2 = 16;
squares[17].nw2 = 26; squares[26].se2 = 17;
squares[18].nw2 = 27; squares[27].se2 = 18;
squares[17].ne2 = 24; squares[24].sw2 = 17;
squares[18].ne2 = 25; squares[25].sw2 = 18;
squares[19].ne2 = 26; squares[26].sw2 = 19;

//20
squares[20].nw2 = 29; squares[29].se2 = 20;
squares[21].nw2 = 30; squares[30].se2 = 21;
squares[22].nw2 = 31; squares[31].se2 = 22;
squares[21].ne2 = 28; squares[28].sw2 = 21;
squares[22].ne2 = 29; squares[29].sw2 = 22;
squares[23].ne2 = 30; squares[30].sw2 = 23;
//all same up to here

squares[0].nw = 5; squares[5].se = 0;
squares[1].nw = 6; squares[6].se = 1;
squares[2].nw = 7; squares[7].se = 2;
squares[0].ne = 4; squares[4].sw = 0;
squares[1].ne = 5; squares[5].sw = 1;
squares[2].ne = 6; squares[6].sw = 2; 
squares[3].ne = 7; squares[7].sw = 3; 
//ok

squares[4].nw = 8; squares[8].se = 4;
squares[5].nw = 9; squares[9].se = 5;
squares[6].nw = 10; squares[10].se = 6;
squares[7].nw = 11; squares[11].se = 7;
squares[5].ne = 8; squares[8].sw = 5;
squares[6].ne = 9; squares[9].sw = 6;
squares[7].ne = 10; squares[10].sw = 7;
//

squares[8].nw = 13; squares[13].se = 8; 
squares[9].nw = 14; squares[14].se = 9;
squares[10].nw = 15; squares[15].se = 10;
squares[8].ne = 12; squares[12].sw = 8;
squares[9].ne = 13; squares[13].sw = 9;
squares[10].ne = 14; squares[14].sw = 10;
squares[11].ne = 15; squares[15].sw = 11;
//

squares[12].nw = 16; squares[16].se = 12;
squares[13].nw = 17; squares[17].se = 13;
squares[14].nw = 18; squares[18].se = 14;
squares[15].nw = 19; squares[19].se = 15;
squares[13].ne = 16; squares[16].sw = 13;
squares[14].ne = 17; squares[17].sw = 14;
squares[15].ne = 18; squares[18].sw = 15;
//

squares[16].nw = 21; squares[21].se = 16;
squares[17].nw = 22; squares[22].se = 17;
squares[18].nw = 23; squares[23].se = 18;
squares[16].ne = 20; squares[20].sw = 16;
squares[17].ne = 21; squares[21].sw = 17;
squares[18].ne = 22; squares[22].sw = 18;
squares[19].ne = 23; squares[23].sw = 19;
//

squares[20].nw = 24; squares[24].se = 20;
squares[21].nw = 25; squares[25].se = 21;
squares[22].nw = 26; squares[26].se = 22;
squares[23].nw = 27; squares[27].sw = 23;
squares[21].ne = 24; squares[24].sw = 21;
squares[22].ne = 25; squares[25].sw = 22;
squares[23].ne = 26; squares[26].sw = 23;
//

squares[24].nw = 29; squares[29].se = 24;
squares[25].nw = 30; squares[30].se = 25;
squares[26].nw = 31; squares[31].se = 26;
squares[24].ne = 28; squares[28].sw = 24;
squares[25].ne = 29; squares[29].sw = 25;
squares[26].ne = 30; squares[30].sw = 26;
squares[27].ne = 31; squares[31].sw = 27;

return;
}