#! /bin/sh -

#indir=/in
indir=/test/file1M
outdir=/outhw1Mv6

cd /root/
if [ `ls /dev/ | grep fir_mod` -eq `echo` ]
then
	./install_fir.sh
fi

echo fir run successful!

cd /mnt/hadoop-2.4.0/
bin/hadoop jar hadoop-streaming-2.4.0.jar \
-file /root/hw_fir/Mapper -mapper /root/hw_fir/Mapper \
-file /root/hw_fir/Reducer -reducer /root/hw_fir/Reducer \
-input $indir -output $outdir

echo test now finished.
#echo see the results

#bin/hadoop dfs -cat $outdir/part-00000
