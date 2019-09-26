#include<stdio.h>
#include<math.h>
#include<string.h>
// #include<stdin.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif

int main()
{
	int debug=1;
	int chunkSize = 1024*1000;

	FILE *read_file;
	FILE * new_merged_file = NULL;

	read_file = fopen("inputfiles/music.mp4","rb");
	new_merged_file = fopen("outputfiles/music_merged.mp4","wb");
	char* chunk_name = "chunks/m_";

	// read_file = fopen("inputfiles/arti.mkv","rb");
	// new_merged_file = fopen("outputfiles/arti_merged.mp4","wb");
	// char* chunk_name = "chunks/mk_";

	fseek(read_file,0L,SEEK_END);
	int size = ftell(read_file);
	printf("Actual Size: %d\n",size);

	int noofChunks = (size / chunkSize);
	int mod = size % chunkSize;

	if(mod>0)
	{
		// if(debug)
		// {
		// 	printf("Chunks Not Equal");
		// }
		noofChunks++;
	}

	printf("Chunks : %d \n",noofChunks);

	FILE *read_file_pointer;
	
	

	char all_chunk_names[1000][100];

	// all_chunk_names = (char **)
	// malloc(noofChunks*sizeof(char));

	size_t size_name = strlen(chunk_name);
	char * new_file_name = NULL;
	long long current_size = 0;

	/**/
	for(int i=0;i<noofChunks;i++)
	{
		new_file_name = (char *)malloc(size_name+10);
		strcpy(new_file_name,chunk_name);

		int tempCounter = (i+1);

		int shiftIndex=0;
		char chunkName[10];
		while(tempCounter>0)
		{
			char lastChar = tempCounter % 10;
			tempCounter = tempCounter/10;
			chunkName[shiftIndex] = lastChar + '0';
			shiftIndex++;
		}
		chunkName[shiftIndex]='\0';

		int current_index=0;
		int totalDistance  = shiftIndex;
		while(current_index<shiftIndex)
		{
			char current_char = chunkName
			[totalDistance - current_index -1];
			new_file_name[size_name+current_index]
			= current_char;
			current_index++;
		}
		new_file_name[size_name+shiftIndex] = '\0';

		// if(debug)
		// 	printf("%s ",new_file_name);

		// all_chunk_names[i] = new_file_name;

		// all_chunk_names[i] = (char *)
		// malloc((size_name+shiftIndex)*sizeof(char));
		strcpy(all_chunk_names[i],new_file_name);

		/* */ 

		FILE *new_file_name_ptr=NULL;
		new_file_name_ptr = fopen(new_file_name,"wb");

		
		fseek(read_file,chunkSize*(i),SEEK_SET);



		current_size+=chunkSize;
		if(size - chunkSize*(i) < chunkSize )
		{
			long long size_left = size - chunkSize*i;
			char newData_small_than_Chunk[size_left+1];
			fread(&newData_small_than_Chunk,chunkSize,1,read_file);
			newData_small_than_Chunk[size_left+1] = '\0';
			fwrite(&newData_small_than_Chunk,chunkSize,1,new_file_name_ptr);
		}
		else
		{
			
			long long size_left = chunkSize;
			char newData[size_left+1];
			fread(&newData,chunkSize,1,read_file);
			newData[chunkSize+1] = '\0';
			fwrite(&newData,chunkSize,1,new_file_name_ptr);

		}

		// if(i+1==chunkSize)
		// newData[chunkSize+1] = '\0';

		
		free(new_file_name);
		fclose(new_file_name_ptr);

	}



	FILE * ref_of_chunk_file = NULL;

	

	for(int i=0;i<noofChunks;i++)
	{
		char * chunk_name = all_chunk_names[i];
		printf("%s\n",chunk_name);

		ref_of_chunk_file = fopen(chunk_name,"rb");

		

		fseek(new_merged_file,chunkSize*(i),SEEK_SET);
		
		// if(i==noofChunks-1)
		// 	newData[chunkSize] = '\0';

		if(size - chunkSize*(i) < chunkSize )
		{
			long long size_left  = size - chunkSize*(i);

			char newData_small_than_Chunk[size_left+1];
			fread(&newData_small_than_Chunk,size_left,1,ref_of_chunk_file);
			// newData_small_than_Chunk[size_left] = '\0';
			fwrite(&newData_small_than_Chunk,size_left,1,new_merged_file);
		}
		else
		{
			char newData[chunkSize+1];
			fread(&newData,chunkSize,1,ref_of_chunk_file);
			fwrite(&newData,chunkSize,1,new_merged_file);
		}


		fclose(ref_of_chunk_file);
	}

	fclose(new_merged_file);

	/* 
	for(int i=0;i<noofChunks;i++)
	{
		printf("\nChunk Name New %s",all_chunk_names[i]);
	}
	*/

	fclose(read_file);

	return 0;
}