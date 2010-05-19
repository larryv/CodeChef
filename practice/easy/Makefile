# Compile every C file into an executable of the same name, without the .c
SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:%.c=%)

# Compile using GCC, with lots of warnings, and define LOCAL
CC := gcc -std=c99
CFLAGS := -Wall
CPPFLAGS := -D LOCAL

# Debugging?
ifeq ($(DEBUG), 1)
CPPFLAGS := $(CPPFLAGS) -D DEBUG
endif



all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(TARGETS)




# TODO
# Add individual targets for the following languages, 
# once I've learned enough about them to use them here.
# 	C (gcc 4.3.2)
# 	C++ (gcc 4.3.2)
# 	Pascal (gpc v20030830)
# 	Java / JAR files (JDK 5.0)
# 	Smalltalk (gst 2.1.7)
# 	FORTRAN (g77 3.3.3)
# 	Ada 95 (gnat 3.15p)
# 	Bash 2.05
# 	Perl 5.8.3
# 	Python 2.5
# 	Ruby 1.9.0
# 	Lua 5.0.2
# 	PHP 4.3.8-9
# 	Scheme (guile 1.6)
# 	Scala 2.7.4
# 	Haskell (ghc 6.10.1)
# 	Erlang 5.6.3
# 	OCaml 3.08.1
# 	JavaScript (rhino 1.7R1-2)