// freemem, alpha release
// Copyright 2019, Aswin Babu Karuvally

// import all the serious stuff
#include<stdio.h>
#include<stdlib.h>

// the main function
int main()
{
	// open the drop_caches file
	FILE *file_pointer;
	file_pointer = fopen("/proc/sys/vm/drop_caches", "w");

	// if NULL pointer is returned, exit
	if(file_pointer == NULL)
	{
		printf("error: no permissions to write to file\n");
		exit(1);
	}
	
	// write to the file
	fprintf(file_pointer, "1");
	
	// close the file
	fclose(file_pointer);
	
	// exit
	printf("memory cleared!\n");
	return 0;
}
