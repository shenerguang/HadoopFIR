#! /bin/sh -


echo clear yarn data folder...
rm -rf /mnt/namenode
rm -rf /mnt/datanode
rm -rf /mnt/hadoop/tmp/*

echo formatting namenode....
cd /mnt/hadoop-2.4.0/
bin/hadoop namenode -format
bin/hadoop datanode -format

echo now start hadoop...
cd /root/
./gohadoop.sh

echo wait 10 seconds for datanode ...
sleep 10
echo copying new file to hadoop....
cd /mnt/hadoop-2.4.0/
bin/hadoop dfs -copyFromLocal /mnt/in/ /in

echo copy finished!

bin/hadoop dfs -ls /in

echo test done!
