#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "Please sudo this."
	exit 1
fi
#dmesg -C

input_folder="OS_PJ1_Test"

for i in TIME_MEASUREMENT FIFO_1 PSJF_2 RR_3 SJF_4; do
	echo "Demo $i..."
	./main < $input_folder/$i.txt
	dmesg -C | grep Project1
	echo ""
done
