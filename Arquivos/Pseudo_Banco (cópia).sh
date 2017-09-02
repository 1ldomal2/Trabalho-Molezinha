#!bin/bash
rm Hotel.txt
for i in $(seq 1 50); do
	echo "$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;$i;">>Hotel.txt
done
