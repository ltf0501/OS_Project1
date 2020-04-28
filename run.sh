#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "Please sudo this."
	exit 1
fi
dmesg -C

input_folder="OS_PJ1_Test"
output_folder="output" 

echo "Doing TIME_MEASUREMENT"
./main < $input_folder/TIME_MEASUREMENT.txt > $output_folder/TIME_MEASUREMENT_stdout.txt 
dmesg -c | grep Project1 > $output_folder/TIME_MEASUREMENT_dmesg.txt
	
sleep 1


for i in {1..5}; do 
 echo "Doing FIFO $i..."
 ./main < $input_folder/FIFO_${i}.txt > $output_folder/FIFO_${i}_stdout.txt
 dmesg -c | grep Project1 > $output_folder/FIFO_${i}_dmesg.txt
 sleep 1
done

for i in {1..5}; do 
 echo "Doing RR $i..."
 ./main < $input_folder/RR_${i}.txt > $output_folder/RR_${i}_stdout.txt
 dmesg -c | grep Project1 > $output_folder/RR_${i}_dmesg.txt
 sleep 1
done

for i in {1..5}; do 
 echo "Doing SJF $i..."
 ./main < $input_folder/SJF_${i}.txt > $output_folder/SJF_${i}_stdout.txt
 dmesg -c | grep Project1 > $output_folder/SJF_${i}_dmesg.txt
 sleep 1
done

for i in {1..5}; do 
 echo "Doing PSJF $i..."
 ./main < $input_folder/PSJF_${i}.txt > $output_folder/PSJF_${i}_stdout.txt
 dmesg -c | grep Project1 > $output_folder/PSJF_${i}_dmesg.txt
 sleep 1
done

