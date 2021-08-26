#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Se deben pasar obligatoriamente 3 argumentos");
        return(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1],"r");
    if (fin == NULL){
        perror("Falla en la apertura del archivo de entrada: ");
        return(EXIT_FAILURE);
    }

    FILE *fout = fopen(argv[2],"a+");
    if (fout == NULL){
        perror("Falla en la apertura del archivo de salida: ");
        return(EXIT_FAILURE);
    }

    feature1(fin, fout);
    feature2(fin, fout);
    feature3(fin, fout);

    return EXIT_SUCCESS;
}
