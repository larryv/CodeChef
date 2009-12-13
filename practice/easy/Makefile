# Compile every C file into an executable of the same name, without the .c
SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:%.c=%)

# Compile using GCC, with lots of warnings
CC := gcc
CFLAGS := -Wall


all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(TARGETS)
