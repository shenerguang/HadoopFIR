#! /bin/sh -

arm-xilinx-linux-gnueabi-gcc led_app.c -o led_app
echo "finish compile app!"
make
echo "make finished!"
cp led_app led_driver.ko /media/fs/gpio_driver/
echo "copy finished!"
ls -l /media/fs/gpio_driver/ | grep 'ko'
umount /media/fs
umount /media/boot
echo "umount finished!"
