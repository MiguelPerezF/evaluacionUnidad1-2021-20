#include <stdlib.h>
#include "student.h"
#include <string.h>

void feature1(FILE *fin, FILE *fout){

    char buffer[64];
    char *status =  NULL;
    int cont = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    do{
        status = fgets(buffer, sizeof(buffer),fin);
        cont++;
        if(status != NULL){
            //printf("%s",buffer);
            fputs(buffer, fout);
        }
    }while (cont <= 0);
    printf("\n");

}

void feature2(FILE *fin, FILE *fout){ 
    char buffer2[256];
    char buffinv[256];
    char *status2 =  NULL;
    int cont2 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    do{
        status2 = fgets(buffer2, sizeof(buffer2),fin);
        cont2++;
        if(status2 != NULL){
            for(int i = strlen(buffer2); i >= 0; i--){
                if(buffer2[i] != 0 || buffer2[i] != 10) //evitar el 0 y el salto de linea: 00 y 10 en ASCII
                buffinv[strlen(buffer2)-i-2] = buffer2[i];
                //printf("Array inverso en posicion %ld: %d\n", (strlen(buffer2) - i), buffer2[i]);
            }
            fputs(buffinv, fout);
        }
    }while (cont2 <= 0);
    printf("\n");
}

void feature3(FILE *fin, FILE *fout){ }

void feature4(FILE *fin, int **parr, int *length, char **op){ }

void feature5(FILE *fout, int *parr, int length, char *op){ }

void feature6(FILE *fin, struct Obj_t *pobj){ }

void feature7(FILE *fout, struct Obj_t *pobj){ }

void feature8(FILE *fin, struct Obj_t **pobj,int *length){ }

void feature9(FILE *fout, struct Obj_t *pobj,int length){ }


