#include <stdio.h>
#include <stdlib.h>
#include "atoi.h"

int main(){
    
    char * mot;
    char buffer[256];

    printf("Merci de saisir une suite \n");
    mot = fgets (buffer, 256, stdin);

    mon_atoi_a_moi(mot);

    return 0;
    
}