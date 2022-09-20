Lab1_queue_v2: Lab1_queue_v2.c
	gcc -o Lab1_queue_v2 Lab1_queue_v2.o

Lab1_queue_v2.o: Lab1_queue_v2.c
	gcc -c Lab1_queue_v2.c

clean:
	rm Lab1_queue_v2.o
