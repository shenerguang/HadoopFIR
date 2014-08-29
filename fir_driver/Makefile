# Makefile for globalmm Driver
#			Program start 2014.3.14
# 如果已经定义了KERNELRELEASE,则说明从内核构造系统调用的。
# 因此可以利用其内建语句
ifneq ($(KERNELRELEASE),)
	obj-m := fir_driver.o
# 否则，要直接从命令行调用
# 这时要调用内核构造系统
else
KERNELDIR = /root/zybo_gpio/linux-digilent/
PWD := $(shell pwd)   
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules ARCH=arm
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.* Module.*
endif
