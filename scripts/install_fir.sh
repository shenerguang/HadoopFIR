#! /bin/sh -
insmod fir_driver.ko
cat /proc/devices | grep fir_dev
mknod /dev/fir_mod c 250 0
echo "you can use fir_mod device in your app now!"
