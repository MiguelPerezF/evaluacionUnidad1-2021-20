#include <stdlib.h>
#include "student.h"
#include <string.h>
#include <ctype.h>


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
    char salto = 10; //10 es una nueva linea en ASCII
    int cont2 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    do{
        status2 = fgets(buffer2, sizeof(buffer2),fin);
        cont2++;
        if(status2 != NULL){
            for(int i = strlen(buffer2); i >= 0; i--){
                if (buffer2[i] == 10)
                {
                    salto = buffer2[i]; //guardo el '10' del salto en ASCII en la variable salto
                }
                if(buffer2[i] != 0 || buffer2[i] != 10) //evitar el 0 y el salto de linea: 00 y 10 en ASCII
                buffinv[strlen(buffer2)-i-2] = buffer2[i]; //-2 para evitar el 0 del fin de la cadena y el salto de linea
                //printf("Array inverso en posicion %ld: %d\n", (strlen(buffer2) - i), buffer2[i]);
                if (i == strlen(buffer2)-1)
                {
                    buffinv[i] = buffer2[i]; //agrego el salto de lìnea en el arreglo para que feature3 escriba en la siguiente linea
                }
            }
            fputs(buffinv, fout);
        }
    }while (cont2 <= 0);
    printf("\n");
}

void feature3(FILE *fin, FILE *fout){ 
    char buffer3[128];
    char *token;
    char *status3 =  NULL;
    int suma = 0;
    int cont3 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    do{
        status3 = fgets(buffer3, sizeof(buffer3),fin);
        cont3++;
        if(status3 != NULL){
            token = strtok(buffer3, " "); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
            if (token == NULL)
            {
                printf("No hay elementos en el arreglo");
                return (EXIT_FAILURE);
            }
            suma+=atoi(token); //atoi es para convertir a entero el char que tiene token
            while (token != NULL)
            {
                token = strtok(NULL, " ");
                if (token != NULL)
                {
                    suma+=atoi(token);
                }    
            }
            //printf("La suma total es: %d\n", suma);
            fprintf(fout, "%d", suma);
        }                  
    }while (cont3 <= 0);
    printf("\n");
}

void feature4(FILE *fin, int **parr, int *length, char **op){ }

void feature5(FILE *fout, int *parr, int length, char *op){ }

void feature6(FILE *fin, struct Obj_t *pobj){ }

void feature7(FILE *fout, struct Obj_t *pobj){ }

void feature8(FILE *fin, struct Obj_t **pobj,int *length){ }

void feature9(FILE *fout, struct Obj_t *pobj,int length){ }


