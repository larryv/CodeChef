# Compile every C file into an executable of the same name, without the .c
SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:%.c=%)

# Compile using GCC, with lots of warnings
CC := gcc
CFLAGS := -Wall

# Enable local code
LOCAL := 1

# Debugging?
ifeq ($(DEBUG), 1)
CFLAGS := $(CFLAGS) -g
endif


all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(TARGETS)
