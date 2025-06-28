#include<cstdlib>
#include<cstdio>
#include <stdint.h>
#include <array>

using namespace std;

#define Nb 4
// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void AddRoundKey(unsigned char state[4][4],
		 unsigned char RoundKey[240], int round)
{
  int i,j;
  for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
        {
	  state[j][i] ^= RoundKey[round * Nb * 4 + i * Nb + j];
        }
    }
}
// Cipher is the main function that encrypts the PlainText.
uint32_t Cipher(unsigned char *out,
	    unsigned char *in, unsigned char *roundkey)
{
  unsigned char state[4][4];
  int i,j=0;
  //Copy the input PlainText to state array.
  for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
        {
	  state[j][i] = in[i*4 + j];
        }
    }
    
    AddRoundKey(state, roundkey, 0);
  // The encryption process is over.
  // Copy the state array to output array.
  for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
        {
	  out[i*4+j]=state[j][i];
        }
    }
    
    return 0;
}
