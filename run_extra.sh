make clean

make fcfs
make sjf
make rr
make priority
make priority_rr

echo -e "\n-- Running FCFS --" 
./bin/fcfs tests/book.txt
echo -e "\n"
./bin/fcfs tests/schedule.txt
echo -e "\n"

echo -e "-- Running SJF --" 
./bin/sjf tests/book.txt
echo -e "\n"
./bin/sjf tests/schedule.txt
echo -e "\n"

echo -e "-- Running RR --" 
./bin/rr tests/schedule.txt
echo -e "\n"
./bin/rr tests/rr-schedule.txt
echo -e "\n"

echo -e "-- Running PRI --" 
./bin/priority tests/schedule.txt
echo -e "\n"
./bin/priority tests/pri-schedule.txt
echo -e "\n"

echo -e "-- Running RR-PRI --" 
./bin/priority_rr tests/rr-schedule.txt
echo -e "\n"
./bin/priority_rr tests/schedule.txt
echo -e "\n"