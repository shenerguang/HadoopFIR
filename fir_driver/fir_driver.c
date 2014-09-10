#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/ioctl.h>

#include <asm/io.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <linux/wait.h>
#include <linux/cdev.h>

#include <linux/interrupt.h>
#include <asm/signal.h>
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/semaphore.h>

#define DEVICE_NAME "fir_dev"
#define FIR_BASEADDR 0x43C00000


#define XFIR_DATA_IN_OFFSET	0x1C
#define XFIR_DATA_OUT_OFFSET	0x14
#define XFIR_CTRL_OFFSET	0x00
#define XFIR_DONE_OFFSET	0x10

static unsigned long fir_addr = 0;

static struct class* fir_class = NULL;
static struct device* fir_device = NULL;

static int fir_major = 0;

static struct semaphore sem;

//arg means the led number, cmd controls it on or off
static ssize_t fir_ioctl(struct file *file, unsigned int cmd, long *arg)
{
	//printk("fun(gpio_ioctl):");
	long status = 0xff;
	int ret,ii;
	printk("******** in ioctl ************\n");
	switch(cmd){
		case 0:
		case 1:
			//init fir put 59 zero 
			for(ii=0;ii<59;ii++)
			{
				iowrite32(0x0,fir_addr+XFIR_DATA_IN_OFFSET);
				iowrite32(0x1,fir_addr+XFIR_CTRL_OFFSET);
				iowrite32(0x0,fir_addr+XFIR_CTRL_OFFSET);
				while(!ioread32(fir_addr+XFIR_DONE_OFFSET));
			}
			//now read data from fir y
			//status = ioread32(fir_addr+FIR_DATA_OUT_OFFSET);
			//printk("59 zeros has been put to fir!!\n");
			return 0;
		case 3:
			//printk("in data = %ld\n",*arg);
			iowrite32(*arg,fir_addr+XFIR_DATA_IN_OFFSET);
			iowrite32(0x1,fir_addr+XFIR_CTRL_OFFSET);
			iowrite32(0x0,fir_addr+XFIR_CTRL_OFFSET);
			//now wait for fir generate ok
			while(!ioread32(fir_addr+XFIR_DONE_OFFSET));
			//now read data from fir y
			status = ioread32(fir_addr+XFIR_DATA_OUT_OFFSET);
			ret = __put_user(status, (long *)arg);
			//printk("out data = 0x%x\n",status);
			return 0;
		case 5:
			up(&sem);
			//printk("sema up\n");
			return 0;
		default:
			//printk("default cmd=%d\n",cmd);
			return -EINVAL;
	}
}

int fir_open(struct inode *inode, struct file *filp)
{
	sema_init(&sem,1);
	down(&sem);
	printk("sema down\n");
	return 0;
}


static struct file_operations fir_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = fir_ioctl,
	.open = fir_open,
};

static int __init fir_init(void)
{
	int ret;
	ret = register_chrdev(0,DEVICE_NAME, &fir_fops);
	if(ret < 0)
	{
		printk("fir: can't get major number\n");
		return ret;
	}

	fir_major = ret;
	fir_class = class_create(THIS_MODULE, "fir_class");
	if(IS_ERR(fir_class))
	{
		printk("fir: failed in creating class\n");
		unregister_chrdev(fir_major, DEVICE_NAME);
		return -1;
	}

	fir_device = device_create(fir_class,NULL,MKDEV(fir_major,0),NULL,DEVICE_NAME);
	if(IS_ERR(fir_device))
	{
		printk("fir: failed in creating device!\n");
		unregister_chrdev(fir_major, DEVICE_NAME);
		class_unregister(fir_class);
		class_destroy(fir_class);
		return -1;
	}
	
	fir_addr = (unsigned long) ioremap(FIR_BASEADDR, sizeof(u32));

	printk("fir installed successfully!\n");
	return 0;
}

static void __exit fir_exit(void)
{
	device_destroy(fir_class,MKDEV(fir_major, 0));
	class_unregister(fir_class);
	class_destroy(fir_class);
	unregister_chrdev(fir_major,DEVICE_NAME);
	printk("fir module exit!");
}

module_init(fir_init);
module_exit(fir_exit);


MODULE_AUTHOR("erguangs");
MODULE_LICENSE("GPL");

