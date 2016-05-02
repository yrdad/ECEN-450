#include <sys/types.h>
#include <sys/stat.h>
#include <linux/unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEVICE_FILE "/dev/irq_test"
#define WAIT_VAL 0x0100000/2 // iterations to wait in delay
int main()
{
	printf("Beginning DEV TEST\n");

	int fd;
	printf("about to open file \n");
        fd = open(DEVICE_FILE, O_RDWR);
	printf("finished opening file \n");
	

	if(fd == -1) {
		printf("Device open error\n");
		return -1;
	}
	char* buffer=(char*)malloc(2*10);//each message is only 2 bytes
	char* buffer_1 = (char*) malloc(20); //second buffer
	memset(buffer,'0',20);
	//memset(buffer_1,'0',20);
	int message;
	char* msg_ptr=(char*)&message;//char buffer for copy of int
	int i = 0;
	while (i < 200)
	{

		delay();
		printf("about to read \n");
		read(fd, (char *) buffer,4, 0);
		//read(fd, (char *) buffer_1, 2, 0);
		printf("finished reading \n");
		printf("The message was: %x\n", *buffer);
		memset(buffer,0,20);
		//memset(buffer_1,'0',20);
		++i;
		
	}
	free(buffer);
	close(fd);
	return 0;
}



int delay (void)
{
	volatile int delay_count=0; // volatile prevents compiler optimization
	while(delay_count<WAIT_VAL)
		delay_count++;// each iteration of while loop is 2 clock cycles
	return(0);
}
		
	
	
	
