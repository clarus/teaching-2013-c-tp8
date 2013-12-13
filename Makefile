default: echo cat

clean:
	rm -f *.o

% : %.c
	gcc -Wall $< -o $@
