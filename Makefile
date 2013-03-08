CC := gcc
LD := $(CC)

override CFLAGS := -O3 -Wall -Wextra -g -I include/ -std=gnu99 $(CFLAGS)
override LDFLAGS := -lgmp $(LDFLAGS)

all: prime

prime: src/main.o
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f prime primes.txt
	find src/ -name '*.o' -delete

