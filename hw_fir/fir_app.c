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
	unsigned int val;
        // open device
        fir_fd = open("/dev/fir_mod", 0);
        if (fir_fd < 0) {
                perror("open device gpio_dev error!\n");
                exit(1);
        }

        printf("read fir devide successful\n");
	ioctl(fir_fd,1,0x9000);
	ioctl(fir_fd,3,&val);	
	printf("val = 0x%x\n",val);
}

