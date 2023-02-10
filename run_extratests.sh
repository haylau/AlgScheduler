make clean

make fcfs
make sjf
make rr
make priority
make priority_rr

echo -e "\n-- Running FCFS --" 
./bin/fcfs tests/schedule.txt
echo -e "\n"

echo -e "-- Running SJF --" 
./bin/sjf tests/schedule.txt
echo -e "\n"

echo -e "-- Running RR --" 
./bin/rr tests/schedule.txt
echo -e "\n"

echo -e "-- Running PRI --" 
./bin/priority tests/schedule.txt
echo -e "\n"

echo -e "-- Running RR-PRI --" 
./bin/priority_rr tests/schedule.txt
echo -e "\n"