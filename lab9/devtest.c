#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/ioctl.h>
#include "sound.h"




int main(void){
	int fd = 0;
	fd = open("/dev/ac97", O_RDWR);
	if(fd < 0 ) return -1;

	printf("part '1' or '2'\n");
	char buffer[10];
	char *line;
	line = fgets(buffer,sizeof(buffer),stdin);
	
	if (line[0] == '1'){
		/* running code for part 1 */
		printf("playing music for part 1...\n");
	
		while(1) {
			line = fgets(buffer,sizeof(buffer), stdin);
			if((line == NULL) || (toupper(line[0]) == 'Q')) break;
		}
	}
	
	else {
		/* running code for part 2 */
		unsigned short int val = 0;
		printf("playing music for part 2...\n");
		usleep(2000000);
		
		printf("lowering aux volume\n");
		val = AC97_VOL_MIN;
		ioctl(fd,0x01DEAD,&val);
		usleep(4000000);
		
		printf("raising aux volume\n");
		val = AC97_VOL_MAX;
		ioctl(fd,ADJUST_AUX_VOL,&val);
		usleep(4000000);

		printf("lowering master volume\n");
		val = AC97_VOL_MUTE;
		ioctl(fd,ADJUST_MAST_VOL,&val);
		usleep(4000000);
	
		printf("raising master volume\n");
		val = AC97_VOL_MAX;
		ioctl(fd,ADJUST_MAST_VOL,&val);
		usleep(4000000);
		
		printf("decreasing playback rate\n");
		val = AC97_PCM_RATE_8000_HZ;
		ioctl(fd,ADJUST_PLAYBACK_RATE,&val);
		usleep(4000000);
		
		printf("increasing playback rate\n");
		val = AC97_PCM_RATE_48000_HZ;
		ioctl(fd,ADJUST_PLAYBACK_RATE,&val);
		usleep(4000000);
		
		printf("done!\n");
	}
	printf("closing device\n");
	close(fd);
	return 0;
}
