#! /bin/sh -

insmod led_driver.ko

mknod /dev/gpio_dev c 248 0

./led_app
