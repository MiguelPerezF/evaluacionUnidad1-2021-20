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

void feature3(FILE *fin, FILE *fout){ 
    char buffer3[256];
    char aux1[256];
    int arrterm[256];
    int valact = 0;
    int valsig = 0;
    int val2sig = 0;
    int suma = 0;
    char *status3 =  NULL;
    int cont3 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    int posaux = 0;
    do{
        status3 = fgets(buffer3, sizeof(buffer3),fin);
        cont3++;
        if(status3 != NULL){
            for (int i = 0; i < strlen(buffer3); i++)
            {
                valact = buffer3[i] - 48;
                valsig = buffer3[i+1] - 48;
                val2sig = buffer3[i+2] - 48;
                printf("Valor actual: %d\n", valact);
                if (valact > 0)
                {
                    if (valsig >= 0)
                    {
                        valact = (((valact)*10)+valsig);
                        aux1[posaux] = valact;
                        posaux++;
                        i++;
                    }
                    else{
                        aux1[posaux] = valact;
                        posaux++;
                    }
                }
                else{
                    if (valact == -3)
                    {
                        if (val2sig >= 0)
                        {
                            valact = (((valsig)*10)+val2sig)*(-1);
                            aux1[posaux] = valact;
                            posaux++;
                            i+=2;
                        }
                        else{ 
                            valact = (valsig)*(-1);
                            aux1[posaux] = valact;
                            posaux++;
                            i++;
                        }   
                    }
                    else{
                        valact = -100; //Distintivo para cuando es un espacio
                        aux1[posaux] = valact;
                        posaux++;
                    }
                }
            }
        }              
    
    }while (cont3 <= 0);
    printf("\n");
    for (int i = 0; i < strlen(buffer3); i++)
    {
        if (aux1[i] != -100) //Sumo las casillas que no sean -100 (porque -100 significa espacio)
        {
            suma+=aux1[i];
        }
        
        printf("Arr(%d): %d\n", i, aux1[i]);
        printf("La suma es: %d\n", suma);

    }
}

void feature4(FILE *fin, int **parr, int *length, char **op){ }

void feature5(FILE *fout, int *parr, int length, char *op){ }

void feature6(FILE *fin, struct Obj_t *pobj){ }

void feature7(FILE *fout, struct Obj_t *pobj){ }

void feature8(FILE *fin, struct Obj_t **pobj,int *length){ }

void feature9(FILE *fout, struct Obj_t *pobj,int length){ }


