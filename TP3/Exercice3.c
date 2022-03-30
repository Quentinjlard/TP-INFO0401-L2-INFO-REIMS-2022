#include <stdio.h>
#include <stdlib.h>

typedef struct bloc bloc;

struct bloc
{
    int valeur;
    bloc *ptr;
};


void AllocationStruct(bloc* ptr)
{

    ptr = (bloc*)malloc(sizeof(bloc));

    for(int i = 0; i < 3; i++){
        
        
        ptr->ptr=(bloc*)malloc(sizeof(bloc));

        ptr->valeur = i;
        
    }
}

void AffichageStruct(bloc* ptr)
{
    for(int i = 0; i < 4;i++)
    {
        if(ptr != NULL){
            printf("PTR n° %d : %d  \n",i, ptr->valeur );
        }
        else
        {
            printf("NULL \n");
        }
    }
}

void LiberationStruct(bloc* ptr)
{
    for(int i = 0; i < 3; i++)
    {
        free(ptr->ptr);
    }

    free(ptr->ptr);
}

int main(void)
{
    /*
    bloc x,y,z;
    
    bloc *ptr;

    x.valeur = 1;
    y.valeur = 2;
    z.valeur = 3;

    ptr = &x;
    x.ptr = &y;
    y.ptr = &z;
    z.ptr = NULL;

    printf("x : %d \ny : %d \nz : %d \n", ptr->valeur,ptr->ptr->valeur,ptr->ptr->ptr->valeur );
    */

   bloc ptr;

   AllocationStruct(&ptr);
   AffichageStruct(&ptr);
   //LiberationStruct(ptr);
}
