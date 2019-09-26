#include<stdio.h>

struct rec
{
	int x;
};

int main()
{
	// write 
	int operation=0;

	// read
	operation=1;

	int counter;
	FILE *ptr_myfile;
	struct rec my_record;

	// write 
	if(operation==0)
		ptr_myfile = fopen("m_file.bin","wb");

	// read
	else if(operation==1)
		ptr_myfile = fopen("m_file.bin","rb");

	if(!ptr_myfile)
	{
		printf("Unable to Open File");
		return 0;
	}
	
	for(counter=1;counter<=10;counter++)
	{
		if(operation==1)
		{
			fread(&my_record,sizeof(struct rec),1,ptr_myfile);
			printf("Record : %d\n",my_record.x);
		}

		if(operation==0)
		{
			my_record.x = counter;
			fwrite(&my_record,sizeof(struct rec),1,ptr_myfile);
		}
	}

	fclose(ptr_myfile);
	return 0;
}