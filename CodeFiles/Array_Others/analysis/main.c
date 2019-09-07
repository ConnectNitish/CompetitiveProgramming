#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Data
{
	int startTime;
	int endTime;
	char* location;
	int channelNumber;
};


int main()
{

	int sizeofdata = 100000;

 printf(" AAAAA ");

	
	int chunkSize = 12;

 printf(" AAAAA ");


	struct Data * pointerToData = (struct Data *)malloc(sizeof(struct Data)*chunkSize);

	int startTime,endTime,channelNumber;
	char* location;

// 	FILE *fp;

 
//     fp = fopen("input.txt", "r");
 
//     if(fp == NULL)
//     {
//         printf("Error opening input file\n");
//         exit(1);
//     }

     printf(" AAAAA ");

	for(int indexToChunk = 0;indexToChunk<chunkSize;indexToChunk++)
	{
	    scanf("%d",&startTime);
	   	scanf("%d",&endTime);
	    scanf("%s",&location);
	    scanf("%d",&channelNumber);
	    printf("%s",location);
	    
		//pointerToData[i] = 
	}

	return 0;	
	
}