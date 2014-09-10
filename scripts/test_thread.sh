#!/bin/sh -

if [ `ls /sd` -eq `echo` ]
then
echo sd not prepared!
mount /dev/sdb1 /sd
fi

if [ "$1" = "hw" ]
then
./hw_fir/Mapper < /sd/test/file1M &> /dev/null
./hw_fir/Mapper < /sd/test/file1M &> /dev/null
./hw_fir/Mapper < /sd/test/file1M
fi

if [ "$1" = "sw" ]
then
./sw_fir/Mapper < /sd/test/file1M &> /dev/null
./sw_fir/Mapper < /sd/test/file1M &> /dev/null
./sw_fir/Mapper < /sd/test/file1M
fi
