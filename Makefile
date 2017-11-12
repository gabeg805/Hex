# ------------------------------------------------------------------------------
# Project
PROJECT = hex

# ------------------------------------------------------------------------------
# Options
WORD_SIZE = 32

# ------------------------------------------------------------------------------
# Compiler settings
CC      = gcc
CFLAGS  = -g -Wall
LIBS    =
DEFS    = -DWORD_SIZE=$(WORD_SIZE)

# ------------------------------------------------------------------------------
# Directories
BUILDDIR = .
SRCDIR   = $(BUILDDIR)/src
INCDIR   = $(BUILDDIR)/include
OBJDIR   = $(BUILDDIR)/obj

# ------------------------------------------------------------------------------
# Files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ------------------------------------------------------------------------------
# Redefine compiler settings
LIBS += -I$(INCDIR)

# ------------------------------------------------------------------------------
# Targets
all: $(PROJECT)

$(PROJECT): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) \
		-o $(PROJECT) $(OBJ)

$(OBJDIR):
	@mkdir -pv $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LIBS) $(DEFS) \
		-o $@ \
		-c $<

.PHONY: clean
clean : 
	@rm -v -f $(OBJ)
	@rm -v -f $(PROJECT)
