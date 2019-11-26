//Samuel Benedix
//Hill Cipher
//CIS 3360 Spring 2017


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv)
{

    int i = 0;

    char* fname = argv[ 1 ];

    FILE *file1 = fopen( fname, "r" );
     if ( file1 == 0 )
     {
        printf( "Could not open file\n" );
     }
     else
     {

     }


    char* fname2 = argv[ 2 ];


	FILE *file2 = fopen( fname2, "r" );

     if ( file2 == 0 )
     {
        printf( "Could not open file\n" );
     }
     else
     {

     }


/*--------------------------------------------------------------------------------------*/

	int key[10][10];
	char message[10000];
	int cipher[10000];
	char cipherText[10000];
	int messageNum[10000];

	int numCount=0;

	fscanf(file1,"%d", &numCount);
	int j=0;
	int k=0;

	printf("Key matrix:\n");

	for(j = 0; j < numCount; j++)
	{
		printf("\n");
		for(k = 0; k< numCount; k++)
			{
				fscanf(file1, "%d", &key[j][k]);
				printf("%d" " ", key[j][k]);
			}
	}


	int length=0;
	int m=0;
	int n=0;
	char temp;


	while (fscanf(file2, "%c", &temp) != EOF)
    {
      if (isalpha(temp))
	  {
	  	temp = tolower(temp);
	  	message[length]=temp;

	  	length++;
	  }
    }
    printf("\n \n");

    printf("Plaintext:\n");

    while(message[m] != '\0')
    {
    	if(m % 80 == 0)
    		printf("\n");

    	printf("%c", message[m]);

    	m++;
    }
    m=0;

    for(i=0; i<length; i++)
    {
    	messageNum[i] = message[i] - 'a';
	}


	int padNum = 0;
	int lengthCount = length;

	while(lengthCount % numCount !=0)
	{
		lengthCount++;
		padNum++;
	}


	for (i=0; i<padNum; i++)
	{
		messageNum[length + i] = 23;
	}

	//Encryption algorithm
	int blockSet = lengthCount/numCount;
	int location = 0;
	int position = 0;
	int total = 0;
	int cipherInput=0;

	for(i=0; i<blockSet; i++)
	{
		for(j=0; j<numCount; j++)
		{
			location = position;

			for(k=0; k<numCount; k++)
			{
				total += key[j][k] * messageNum[location];
				location++;
			}
			total = (total % 26) ;
			cipher[cipherInput] = total;
			total = 0;
			cipherInput++;
		}
		position += numCount;
	}

	printf("\n");

	for(i=0; i<lengthCount; i++)
    {
    	cipherText[i] = (char) (cipher[i] + 'a');
	}

	printf("\n");
	printf("Ciphertext:\n");

	while(cipherText[m] != '\0')
    {
    	if(m % 80 == 0)
    		printf("\n");

    	printf("%c", cipherText[m]);

    	m++;
    }
    m=0;

	printf("\n");

	fclose( file1 );
	fclose( file2 );

     return 0;


}
