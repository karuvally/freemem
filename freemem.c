// freemem, alpha release
// Copyright 2019, Aswin Babu Karuvally

// import all the serious stuff
#include<stdio.h>
#include<stdlib.h>


// free the memory
int free_memory(char* value)
{
	// open the drop_caches file
	FILE *file_pointer;
	file_pointer = fopen("/proc/sys/vm/drop_caches", "w");

	// if NULL pointer is returned, exit
	if(file_pointer == NULL)
	{
		printf("you need to be root :(\n");
		return(1);
	}
	
	// write to the file
	fprintf(file_pointer, value); 
	
	// close the file
	fclose(file_pointer);
	
	// exit
	printf("memory cleared!\n");
	return 0;
}


// the main function
int main()
{
	// free the memory
	free_memory("1");

	return 0;
}
