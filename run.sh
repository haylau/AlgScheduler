make clean

make fcfs
make sjf
make rr

echo -e "\nRunning FCFS\n" 
./bin/fcfs tests/book.txt
echo -e "\n"
./bin/fcfs tests/schedule.txt

echo -e "Running SJF\n" 
./bin/sjf tests/book.txt
echo -e "\n"
./bin/sjf tests/schedule.txt

echo -e "Running RR\n" 
./bin/rr tests/rr-schedule.txt
echo -e "\n"

