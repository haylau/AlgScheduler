make clean

make fcfs
make sjf
make rr
make priority
make priority_rr

valgrind -s --leak-check=full --show-leak-kinds=all ./bin/fcfs tests/schedule.txt
valgrind -s --leak-check=full --show-leak-kinds=all ./bin/sjf tests/schedule.txt
valgrind -s --leak-check=full --show-leak-kinds=all ./bin/rr tests/schedule.txt
valgrind -s --leak-check=full --show-leak-kinds=all ./bin/priority tests/schedule.txt
valgrind -s --leak-check=full --show-leak-kinds=all ./bin/priority_rr tests/schedule.txt