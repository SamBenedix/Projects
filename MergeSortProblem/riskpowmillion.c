/*
Samuel Benedix
SA383526
3/2/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mergeSort(int arr[],int start,int end); /*merge sort function*/
void merge(int arr[],int start,int mid,int end); /*Does the merging part of the merge sort function*/
int victories(int* a, int* d); /*calculates victories for optimal play and returns that value*/

int numArmies=0;

int main()
{
    int i=0, j=0, z=0;
    int cases=0;
    int* attacking;
    int* defending;

    scanf("%d", &cases);

    for(z=0; z<cases; z++) /*runs for each case*/
    {

    scanf("%d", &numArmies);

    attacking = (int*)malloc(numArmies * sizeof(int));
    defending = (int*)malloc(numArmies * sizeof(int));

    for(i=0; i<numArmies; i++)
    {
        scanf("%d", &attacking[i]);
    }

    for(i=0; i<numArmies; i++)
    {
        scanf("%d", &defending[i]);
    }

    mergeSort(attacking, 0, numArmies-1);
    mergeSort(defending, 0, numArmies-1);

    printf("%d\n", victories(attacking, defending));

    free(attacking);
    free(defending);

    }
 return 0;
}

void mergeSort(int arr[],int start,int end) /*merge sort function*/
{
    int mid;

    if(start<end)
    {
         mid=(start+end)/2;
         mergeSort(arr,start,mid);
         mergeSort(arr,mid+1,end);
         merge(arr,start,mid,end);
    }
}

void merge(int arr[],int start,int mid,int end)/*Does the merging part of the merge sort function*/
{

    int i,m,k,j,temp[numArmies];

    j=start;
    i=start;
    m=mid+1;

    while((j<=mid)&&(m<=end))
    {

         if(arr[j]<=arr[m]){
             temp[i]=arr[j];
             j++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(j>mid)
    {
         for(k=m;k<=end;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else
    {
         for(k=j;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=start;k<=end;k++)
    {
         arr[k]=temp[k];
    }
}


int victories(int* a, int* d) /*calculates victories for optimal play and returns that value*/
{
    int i=0,j=0;
    int numWins=0;

    for(i=0; i<numArmies; i++)
    {
        if(d[i]>=a[j])
            {
                numWins++;
                j++;
            }
    }
    return numWins;
}


