#include "globals.h"

BITBOARD hash[4][32];
BITBOARD lock[4][32];

BITBOARD currentkey,currentlock;
BITBOARD collisions;

BITBOARD bit_units[2];
BITBOARD mask[64];

const BITBOARD MAXHASH =  5000000;
const BITBOARD HASHSIZE = 5000000;

int hash_start,hash_dest;

struct hashp
{
BITBOARD hashlock;
int start;
int dest;
int num;
};

hashp *hashpos[2];

int Random(const int x);

void RandomizeHash()
{
int p,x;
for(p=0;p<4;p++)
	for(x=0;x<32;x++)
	{
		hash[p][x] = Random(HASHSIZE);
		hash[p][x] = Random(HASHSIZE);
		lock[p][x] = Random(HASHSIZE);
		lock[p][x] = Random(HASHSIZE);
	}
	hashpos[0] = new hashp[MAXHASH];
hashpos[1] = new hashp[MAXHASH];
}

int Random(const int x)
{
return rand() % x;
}

void Free()
{
delete hashpos[0];
delete hashpos[1];
}

void AddHash(const int s, const move m)
{
hashp* ptr = &hashpos[s][currentkey];
ptr->hashlock = currentlock;
ptr->start = m.from;
ptr->dest = m.to;
}

void AddKey(const int s,const int p,const int x)
{
  currentkey ^= hash[p][x];
  currentlock ^= lock[p][x];
}

BITBOARD GetLock()
{
BITBOARD loc=0;
int c;
for(int x=0;x<32;x++)
{
	if(board[x]!=0)
	{
		if(board[x]==BM) c = 1;
		if(board[x]==BK) c = 2;
		if(board[x]==RM) c = 3;
		if(board[x]==RK) c = 4;
		loc ^= lock[c][x];
	}
}
return loc;
}

BITBOARD GetKey()
{
BITBOARD key=0;
int c;
for(int x=0;x<32;x++)
{
	if(board[x]!=0)
	{
		if(board[x]==BM) c = 1;
		if(board[x]==BK) c = 2;
		if(board[x]==RM) c = 3;
		if(board[x]==RK) c = 4;
		key ^= hash[c][x];
	}
}
return key;
}

bool LookUp(const int s)
{
if(hashpos[s][currentkey].hashlock != currentlock)
{
  return false;
}
hash_start = hashpos[s][currentkey].start;
hash_dest = hashpos[s][currentkey].dest;
return true;
}

