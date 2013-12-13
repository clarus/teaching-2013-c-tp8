default: echo cat ls

clean:
	rm -f *.o

% : %.c
	gcc -Wall $< -o $@
