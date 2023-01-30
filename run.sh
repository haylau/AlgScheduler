make clean

make fcfs
echo "Running FCFS" 
./bin/fcfs tests/book.txt
./bin/fcfs tests/pri-schedule.txt
./bin/fcfs tests/rr-schedule.txt
./bin/fcfs tests/schedule.txt

