# Makefile code
# Created by Kris Jermvivatkul
# 11 April 2017

# src directory
SRCDIR = src
# bin directory
BINDIR = bin
# all .o files directory
OBJDIR = obj
# db code files
DBDIR = $(SRCDIR)/db

# List of binary files (Currently : 1 file)
EXECUTABLES = $(BINDIR)/movies

# when run 'make' or 'make all', it will start here
all : $(EXECUTABLES)
	./$(BINDIR)/movies

# Compile all object files
$(EXECUTABLES) : $(SRCDIR)/movies.c $(OBJDIR)/dbAdd.o \
				 $(OBJDIR)/dbDelete.o $(OBJDIR)/dbEdit.o \
				 $(OBJDIR)/dbFind.o $(OBJDIR)/dbUtil.o \
				 $(OBJDIR)/dbDump.o $(OBJDIR)/dateFunctions.o
	gcc -o $@ $^

# Compile all file into object file, for debugging
check : $(OBJDIR)/dbAdd.o $(OBJDIR)/dbDelete.o \
		$(OBJDIR)/dbEdit.o $(OBJDIR)/dbFind.o \
		$(OBJDIR)/dbUtil.o $(OBJDIR)/dbDump.o \
		$(OBJDIR)/dateFunctions.o
# Compile all C files into object files (.o).
$(OBJDIR)/dbAdd.o : $(DBDIR)/dbAdd.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dbDelete.o : $(DBDIR)/dbDelete.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dbEdit.o : $(DBDIR)/dbEdit.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dbFind.o : $(DBDIR)/dbFind.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dbDump.o : $(DBDIR)/dbDump.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dbUtil.o : $(DBDIR)/dbUtil.c $(DBDIR)/moviesDB.h
	gcc -c $< -o $@
$(OBJDIR)/dateFunctions.o : $(DBDIR)/dateFunctions.c $(DBDIR)/dateFunctions.h
	gcc -c $< -o $@

# clean all files including database files.
clean :
	-rm $(OBJDIR)/*.o
	-rm $(BINDIR)/movies
	-rm movie.json
	-rm movie.table
