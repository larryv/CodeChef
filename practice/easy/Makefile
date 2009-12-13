# Compile every C file into an executable of the same name, without the .c
SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:%.c=%)

# Compile using GCC, with lots of warnings, and define LOCAL
CC := gcc
CFLAGS := -Wall -D LOCAL

# Debugging?
ifeq ($(DEBUG), 1)
CFLAGS := $(CFLAGS) -g -D DEBUG
endif


all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(TARGETS)
