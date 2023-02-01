# makefile for scheduling program
#
# make rr - for round-robin scheduling
# make fcfs - for FCFS scheduling
# make sjf - for SJF scheduling
# make priority - for priority scheduling
# make priority_rr - for priority with round robin scheduling

CC=gcc
CFLAGS=-Wall -Wextra

clean:
	rm -rf bin/*.o
	rm -rf bin/fcfsbin/schedule_sjf.o
	rm -rf bin/sjf
	rm -rf bin/rr
	rm -rf bin/priority
	rm -rf bin/priority_rr

rr: driver.o list.o cpu.o schedule_rr.o
	$(CC) $(CFLAGS) -o bin/rr bin/list.o bin/cpu.o bin/schedule_rr.o bin/driver.o 

sjf: driver.o list.o cpu.o schedule_sjf.o
	$(CC) $(CFLAGS) -o bin/sjf bin/list.o bin/cpu.o bin/schedule_sjf.o bin/driver.o  

fcfs: driver.o list.o cpu.o schedule_fcfs.o
	$(CC) $(CFLAGS) -o bin/fcfs bin/list.o bin/cpu.o bin/schedule_fcfs.o bin/driver.o 

priority: driver.o list.o cpu.o schedule_priority.o
	$(CC) $(CFLAGS) -o bin/priority bin/list.o bin/cpu.o bin/schedule_priority.o bin/driver.o

priority_rr: driver.o list.o cpu.o schedule_priority_rr.o
	$(CC) $(CFLAGS) -o bin/priority_rr bin/list.o bin/cpu.o bin/schedule_priority_rr.o bin/driver.o
	
driver.o: src/driver.c
	$(CC) $(CFLAGS) -o bin/driver.o -c src/driver.c

schedule_fcfs.o: src/schedule_fcfs.c inc/schedulers.h
	$(CC) $(CFLAGS) -o bin/schedule_fcfs.o -c src/schedule_fcfs.c

schedule_sjf.o: src/schedule_sjf.c inc/schedulers.h
	$(CC) $(CFLAGS) -o bin/schedule_sjf.o -c src/schedule_sjf.c

schedule_priority.o: src/schedule_priority.c inc/schedulers.h
	$(CC) $(CFLAGS) -o bin/schedule_priority.o -c src/schedule_priority.c

schedule_rr.o: src/schedule_rr.c inc/schedulers.h
	$(CC) $(CFLAGS) -o bin/schedule_rr.o -c src/schedule_rr.c

schedule_priority_rr.o: src/schedule_priority_rr.c inc/schedulers.h
	$(CC) $(CFLAGS) -o bin/schedule_priority_rr.o -c src/schedule_priority_rr.c

list.o: src/list.c inc/list.h
	$(CC) $(CFLAGS) -o bin/list.o -c src/list.c

cpu.o: src/cpu.c inc/cpu.h
	$(CC) $(CFLAGS) -o bin/cpu.o -c src/cpu.c
