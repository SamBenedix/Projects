/*
Sam Benedix
Master Mind Program 3
2/19/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*globally defined */
int** guesses;
int slotsAndPegs, numSlots, numColors, numMoves, count=0;

/*prototypes*/
void permute(int* permutations, int peg, int hole); /*creates all the permutations for each case*/
int totalcheck(int* permutations, int* theGuesses); /*checks for the total amount of pegs being the same for the test case and the guess*/
int blacktotal(int* permutations, int* theGuesses); /*checks for the black pegs being the same for the test case and the guess*/

int main()
{
    int i=0, j=0, z=0;
    int numCases;
    int checker;
    count=0;

    int* pass;

    scanf("%d", &numCases);

    for(z=0; z<numCases; z++)
    {

    scanf("%d %d %d", &numSlots, &numColors, &numMoves);

    slotsAndPegs= numSlots + 2;

    guesses = (int**)malloc(numMoves * sizeof(int*));

    for(i=0; i<numMoves; i++)
		guesses[i] = (int*)malloc(slotsAndPegs * sizeof(int));

	for(i=0; i<numMoves; i++)
        for(j=0; j<slotsAndPegs; j++)
			scanf("%d", &guesses[i][j]);

    pass = (int*)malloc(numSlots * sizeof(int));

    for(i=0; i < numColors; i++)
    {
       permute(pass, i, 0);
    }


    printf("%d\n", count);
    count = 0;

    for(i=0; i<numMoves; i++)
    {
        free(guesses[i]);
    }
   free(guesses);
   free(pass);

}
return 0;
}


void permute(int* permutations, int peg, int hole) /*creates all the permutations for each case*/
{
    int i;
    permutations[hole] = peg;


    if( hole == numSlots - 1) /*full permutation*/
    {
        for(i=0; i<numMoves; i++)
            {
                if (totalcheck(permutations, guesses[i]) == 0)
                {
                    return;
                }

                 if (blacktotal(permutations, guesses[i]) == 0)
                {
                    return;
                }
            }
        count++; /*if it makes it through the checks, it is a possible outcome and is added to the count*/

        return;
       }

    else /*not full permutation*/
    {   hole++;
        for(i = 0; i < numColors; i++)
        {
            permute(permutations, i, hole);
        }
    }
}

int totalcheck(int* permutations, int* theGuesses)  /*checks for the total amount of pegs being the same for the test case and the guess*/
{
    int i=0,j=0;
    int tableGuess[numColors]; /*frequency table for the guesses*/
    int tablePerm[numColors]; /*frequency table for the permutations*/
    int totalCount = 0;
    int pegSum;

    for(i = 0; i < numColors; i++)
    {
        tableGuess[i] = 0;
        tablePerm[i] = 0;
    }

    for(i=0; i<numColors; i++) /*creates the frequency tables*/
    {
        for(j=0; j<numSlots; j++)
        {

          if(permutations[j] == i)
          {
              tablePerm[i]+= 1;
          }

          if(theGuesses[j] == i)
          {
              tableGuess[i]+= 1;
          }

        }
    }
    for(i=0; i<numColors; i++)
        {
            if(tableGuess[i]<tablePerm[i])
                totalCount+= tableGuess[i];
            else
                totalCount+=tablePerm[i];
        }

    pegSum = theGuesses[numSlots] + theGuesses[numSlots+1];

    if(totalCount==pegSum)
        return 1;
    else
        return 0; /*returns 0 if the total pegs are not the same with the guess and the permutations*/

}

int blacktotal(int* permutations, int* theGuesses) /*checks for the black pegs being the same for the test case and the guess*/
{
    int i=0;
    int blackCount=0;

    for(i=0; i<numSlots; i++)
   {
      if(permutations[i]==theGuesses[i])
          blackCount++;
    }

   if(blackCount==theGuesses[numSlots])
        return 1;
    else
        return 0;  /*returns 0 if the black pegs are not the same with the guess and the permutations*/

}
