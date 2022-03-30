#include <stdio.h>
#include <stdlib.h>
#include "atoi.h"

int mon_atoi_a_moi(char * mot){
    int i , j=0 , FIN = 0, tmp, negatif = 0, *nombre;
    char buffer[256];
    nombre = (int *) malloc (sizeof(int));
    for(i=0;mot[i]!='\0';i++){
        if(mot[i] >= '0' && mot[i] <= '9'){
            if(mot[i-1] == '-'){
                negatif = 1;
            }
            nombre[j]=mot[i];
            j++;
        }
    }
    for(i=0;nombre[i]!='\0';i++){        
        tmp = nombre[i]- '0';   
        FIN *= 10;
        FIN += tmp;
    }
    FIN = (negatif == 0) ? FIN : -FIN;
    printf("\n%d\n",FIN);
}