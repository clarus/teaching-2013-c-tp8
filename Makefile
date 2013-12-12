default: echo

clean:
	rm -f *.o

% : %.c
	gcc -Wall $< -o $@
