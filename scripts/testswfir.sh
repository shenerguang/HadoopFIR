#! /bin/sh -

#indir=/in
indir=/test/file1M
outdir=/outsw1Mv6


cd /mnt/hadoop-2.4.0/
bin/hadoop jar hadoop-streaming-2.4.0.jar \
-file /root/sw_fir/Mapper -mapper /root/sw_fir/Mapper \
-file /root/sw_fir/Reducer -reducer /root/sw_fir/Reducer \
-input $indir -output $outdir

echo test now finished.
echo see the results

#bin/hadoop dfs -cat $outdir/part-00000
