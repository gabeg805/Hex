CC      = gcc
CFLAGS  = -g -Wall -O2

PROGRAM = hex
NAMES = $(PROGRAM)
SOURCES = $(addprefix ./src/, $(addsuffix .c, $(NAMES)))
HEADERS = $(addprefix ./hdr/, $(addsuffix .h, $(NAMES)))
OBJECTS = $(addprefix ./obj/, $(addsuffix .o, $(NAMES)))

all: $(PROGRAM)

./obj/%.o: ./src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROGRAM) 

.PHONY: clean
clean : 
	@rm -v -f $(OBJECTS)
	@rm -v -f $(PROGRAM)
