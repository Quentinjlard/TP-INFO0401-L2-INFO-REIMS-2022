##################
# Ch Jallet
# projet : Mandelbrot
# fichier : makefile, v2
# date : 2021/12/14
##################

CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS = 
EXE1 = File_test
EXE2 = Pile_test
EXE3 = FilePile_test

DEP=$(wildcard *.h)
SRC=$(wildcard *.c)
OBJ =$(SRC:.c=.o)

##############################
### regle principale (la 1ere)
all : $(EXE1) $(EXE2) $(EXE3)
			
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
