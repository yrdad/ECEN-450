/*  devtest.c -- user application to read and write to device file. This program
		will test the character device driver to make sure it is fully functional */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	unsigned int result, read_i, read_j;
	int fd;   /* file descriptor */
	static int i, j; /* loop variables */
	int rtrn = 0;
	char input = 0;
	char* data = (char*)malloc(12);
	/* open device file for reading and writing */
	/* use open to open '/dev/multiplier'  	    */
	fd = open("/dev/multiplier", O_RDWR);
	/* error handling for: open */
	if(fd == -1){
		printf("Failed to open device file!\n");
		return -1;
	}

	// this while loop is dumb
	while(input != 'q'){	/* continue unless user enters 'q' */
		for (i = 1; i <= 16; i++){
			for(j = 0; j <= 16; j++){
				/* write values to registers using character device */
				/* use write to write i and j to peripheral */
				int* array = (int*)malloc(sizeof(int)*2);

				array[0] = i;	// reg 0
				array[1] = j;	// reg 1

				// writing to registers
				rtrn = write(fd,array, sizeof(int)*2);
				// error handling
				if(rtrn < 1){
					printf("Failed to write to registers\n");
					return -1;
				}
				//printf("Reg0: wrote %d\n", array[0]);
				//printf("Reg1: wrote %d\n", array[1]);
				rtrn = 0;
				free(array);

				/* use read to read from peripheral */
				// read 12 bytes. (3 ints, int = 4 bytes)
				rtrn = read(fd,data,12);
				if(rtrn == -1){
					printf("Failed to retrieve register values\n");
					return -1;
				}
				printf("Read %d bytes\n", rtrn);

				int* int_data = (int*)data;

				read_i = int_data[0];
				read_j = int_data[1];
				result = int_data[2];

				/* print unsigned ints to screen */
				printf("%u * %u = %u", read_i, read_j, result);

				/* validate result */
				if(result == (i*j))
					printf("  Result Correct   **\n\n");
				else {
					printf("  Result Incorrect -\n\n");
					return -1;
				}
				/* read from terminal */
				input = getchar();
			}	//for(j)
		} //for(i)
	} // while()
	close(fd);
	return 0;
}
