# ------------------------------------------------------------------------------
# Project
PROJECT = hex

# ------------------------------------------------------------------------------
# Compiler settings
CC      = gcc
CFLAGS  = -g -Wall
LIBS    =

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
	$(CC) $(CFLAGS) $(LIBS) \
		-o $@ \
		-c $<

.PHONY: clean
clean : 
	@rm -v -f $(OBJ)
	@rm -v -f $(PROJECT)
