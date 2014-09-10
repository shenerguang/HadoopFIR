#! /bin/sh -


cd /mnt/hadoop-2.4.0/
sbin/start-dfs.sh
sbin/start-yarn.sh

jps
echo "please wait..."
while [ `netstat -ntlp | grep 9000` -eq `echo` ]
do
sleep 1
done
netstat -ntlp

echo hadoop start successfully
bin/hadoop dfs -ls /
echo test finished

