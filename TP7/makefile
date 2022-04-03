##################
# Ch Jallet
# projet : file
# fichier : makefile, v2
# date : 2021/12/14
##################

CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lm
EXE = Liste_test

DEP=$(wildcard *.h)
SRC=$(wildcard *.c)
OBJ =$(SCR .C=.O)

##############################
### regle principale (la 1ere)
all : $(EXE)
			
##############################
### generation des modules objet

principal.o : principal.c $(DEP)
	$(CC) $(CFLAGS) $< -c
%.o : %.c %.h
	$(CC) $(CFLAGS) $< -c
		
##############################
### regle principale : edition de lien
$(EXE) : $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
	
##############################
### regles complementaires usuelles
.PHONY : clean mrproper

clean : 
	@rm -f *.o
mrproper : clean
	@rm -f *~ a.out $(EXE)
