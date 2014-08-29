#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

static int led_fd;

int main(void)
{
	int i;
        // open device
        led_fd = open("/dev/gpio_dev", 0);
        if (led_fd < 0) {
                perror("open device gpio_dev error!\n");
                exit(1);
        }

        printf("Please look at the leds\n");
}
