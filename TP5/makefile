##################
# Ch Jallet
# projet : polynomes par tableaux
# fichier : makefile
# date : 2022/02/07
##################

CC = gcc
CFLAGS = -Wall #-ansi
LDFLAGS = #-lm

PRINCIPAL = princ
EXE = a.exe

DEP=$(wildcard *.h)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

##############################
### regle principale (la 1ere)
all : $(EXE)
			
##############################
### generation des modules objet

$(PRINCIPAL).o : $(PRINCIPAL).c $(DEP)
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
