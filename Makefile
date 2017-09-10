# Project name
PROJECT = hex

# Compiler settings
CC      = gcc
LIBS    =
CFLAGS  = -g -Wall

# Directories
BUILDDIR = .
SRCDIR   = $(BUILDDIR)/src
OBJDIR   = $(BUILDDIR)/obj
INCDIR   = $(BUILDDIR)/include

# Files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Redefine compiler settings
LIBS += -I $(INCDIR)

# Default target
all: $(PROJECT)

install: all

# Compile targets
$(PROJECT): $(OBJ)
	$(CC) $(CFLAGS) \
		-o $(PROJECT) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) $(CFLAGS) $(LIBS) \
		-c $< \
		-o $@

# Phony targets
.PHONY: clean
clean : 
	@rm -v -f $(OBJ)
	@rm -v -f $(PROJECT)
