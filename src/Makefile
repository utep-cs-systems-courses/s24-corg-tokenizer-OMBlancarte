

CFLAGS = -g -O3

all: tokenizer

tokenizer: tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

tokenizer.o: tokenizer.h
uimain.o: tokenizer.h

clean:
	rm -f *.o *.c~ tokenizer

run: tokenizer
	./tokenizer
