#! /bin/sh -


cd /mnt/hadoop-2.4.0/
sbin/hadoop-daemon.sh start namenode
sbin/hadoop-daemon.sh start datanode
sbin/hadoop-daemon.sh start secondarynamenode
sbin/yarn-daemon.sh start resourcemanager
sbin/yarn-daemon.sh start nodemanager
sbin/mr-jobhistory-daemon.sh start historyserver

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

