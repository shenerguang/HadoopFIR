#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

static int fir_fd;

int main(void)
{
        int i;
	long val;
        // open device
        fir_fd = open("/dev/fir_mod", 0);
        if (fir_fd < 0) {
                perror("open device gpio_dev error!\n");
                exit(1);
        }
	printf("fd = %d\n",fir_fd);

        printf("read fir devide successful\n");
	ioctl(fir_fd,1,0);
	for(i=0;i<60;i++)
	{
		if(i==0)
		{
			val = 1;
			ioctl(fir_fd,3,&val);	
		}
		else
		{
			val = 0;
			ioctl(fir_fd,3,&val);
			printf("%d:%ld\n",i,val);
		}

	}
	//ioctl(fir_fd,3,val);
	printf("done");
}

