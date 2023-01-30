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
	rm -rf bin/fcfs
	rm -rf bin/sjf
	rm -rf bin/rr
	rm -rf bin/priority
	rm -rf bin/priority_rr

rr: driver.o list.o CPU.o schedule_rr.o
	$(CC) $(CFLAGS) -o bin/rr bin/driver.o bin/schedule_rr.o bin/list.o bin/CPU.o

sjf: driver.o list.o CPU.o schedule_sjf.o
	$(CC) $(CFLAGS) -o bin/sjf bin/driver.o bin/schedule_sjf.o bin/list.o bin/CPU.o

fcfs: driver.o list.o CPU.o schedule_fcfs.o
	$(CC) $(CFLAGS) -o bin/fcfs bin/driver.o bin/schedule_fcfs.o bin/list.o bin/CPU.o

priority: driver.o list.o CPU.o schedule_priority.o
	$(CC) $(CFLAGS) -o bin/priority bin/driver.o bin/schedule_priority.o bin/list.o bin/CPU.o

priority_rr: driver.o list.o CPU.o schedule_priority_rr.o
	$(CC) $(CFLAGS) -o bin/priority_rr bin/driver.o bin/schedule_priority_rr.o bin/list.o bin/CPU.o
	
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

list.o: src/list.c inc/list.h
	$(CC) $(CFLAGS) -o bin/list.o -c src/list.c

CPU.o: src/CPU.c inc/cpu.h
	$(CC) $(CFLAGS) -o bin/CPU.o -c src/CPU.c
