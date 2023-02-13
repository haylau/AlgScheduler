#!/bin/bash

test='a';

if [ $1 ]; then
    test=$1
  else 
    test="tests/schedule.txt"
fi

echo $test

make clean

make fcfs
make sjf
make rr
make priority
make priority_rr

echo "Running $test" 

echo -e "\n-- Running FCFS --" 
./bin/fcfs $test
echo -e "\n"

echo -e "-- Running SJF --" 
./bin/sjf $test
echo -e "\n"

echo -e "-- Running RR --" 
./bin/rr $test
echo -e "\n"

echo -e "-- Running PRI --" 
./bin/priority $test
echo -e "\n"

echo -e "-- Running RR-PRI --" 
./bin/priority_rr $test
echo -e "\n"    