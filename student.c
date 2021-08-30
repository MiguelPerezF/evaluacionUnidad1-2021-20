#include <stdlib.h>
#include "student.h"
#include <string.h>
#include <ctype.h>

char *create_array(int);
void destroy_array(char *);

void feature1(FILE *fin, FILE *fout){

    char buffer[64];
    char *status =  NULL;
    int cont = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    status = fgets(buffer, sizeof(buffer),fin);
    cont++;
    if(status != NULL){
        //printf("%s",buffer);
        fputs(buffer, fout);
    }
    //destroy_array(buffer);
    printf("\n");
}

void feature2(FILE *fin, FILE *fout){
    char buffer2[128];
    char buffinv[128];
    char *status2 =  NULL;
    char salto = 10; //10 es una nueva linea en ASCII
    int cont2 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    status2 = fgets(buffer2, sizeof(buffer2),fin);
    cont2++;
    if(status2 != NULL){
        for(int i = strlen(buffer2); i >= 0; i--){
            if(buffer2[i] != 0 || buffer2[i] != 10) //evitar el 0 y el salto de linea: 00 y 10 en ASCII
            buffinv[strlen(buffer2)-i-2] = buffer2[i]; //-2 para evitar el 0 del fin de la cadena y el salto de linea
            //printf("Array inverso en posicion %ld: %d\n", (strlen(buffer2) - i), buffer2[i]);
            if (i == strlen(buffer2)-1)
            {
                buffinv[i] = salto; //agrego el salto de lìnea en el arreglo para que feature3 escriba en la siguiente linea
            }
        }
        fputs(buffinv, fout);
    }
    printf("\n");
}

void feature3(FILE *fin, FILE *fout){ 
    char buffer3[128];
    char *token;
    char *status3 =  NULL;
    int suma = 0;
    int cont3 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    status3 = fgets(buffer3, sizeof(buffer3),fin);
    cont3++;
    if(status3 != NULL){
        token = strtok(buffer3, " "); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
        if (token == NULL)
        {
            printf("No hay elementos en el arreglo");
            EXIT_FAILURE;
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
        fprintf(fout, "%d", suma);
    }                  
}

void feature4(FILE *fin, int **parr, int *length, char **op){ 
    char buffer4[128];
    char *token;
    char *status4 =  NULL;
    int arrint[128];
    char opaux[32];
    int cont4 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    int contop = 0;
    int contint = 0;
    status4 = fgets(buffer4, sizeof(buffer4),fin);
    //printf("buffer: %s\n", buffer4);
        
    cont4++;
    if(status4 != NULL){
        token = strtok(buffer4, " "); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
        if (token == NULL)
        {
            printf("No hay elementos en el arreglo");
            EXIT_FAILURE;
        }
            
        while (token != NULL)
        {
            if (token != NULL)
            {
                arrint[contint] = atoi(token); //Agregarà todos los elementos
            }
            token = strtok(NULL, " ");
            contint++; 
        }

        for (int i = 0; i < ((sizeof(buffer4)/sizeof(buffer4[0]))); i++) //Recorre las posiciones con la operacion
        {
            if (buffer4[i] > 64 && buffer4[i] < 123) //Que agregue posiciones al arreglo solo si son letras
            {
                opaux[contop] = buffer4[i];
                contop++;
            }
        }
        *length=contint-1; //-1 para evitar el 0 que pone por la posicion de la operacion siendo el arreglo solo de enteros
        *parr = arrint;
        *op = opaux;
    }                  
}

void feature5(FILE *fout, int *parr, int length, char *op){ 
    fprintf(fout, "\n");
    int suma = 0;
    int min = 10000000;
    int max = 0;
    int resultado = 0;
    int tstavg = 0;
    for (int i = 0; i < length; i++)
    {
        if (op[0] == 97 && op[1] == 118 && op[2] == 103) //Equivalente a avg
        {
            suma+=parr[i];
            tstavg = 1;
            //resultado se calcula aparte verificando tstavg = 1 para no ser afectado por el ciclo grande
        }
        if (op[0] == 109 && op[1] == 105 && op[2] == 110) //Equivalente a min
        {
            if (parr[i] < min)
            {
                min = parr[i];
                resultado = min;
            }
        }
        if (op[0] == 109 && op[1] == 97 && op[2] == 120) //Equivalente a max
        {
            if (parr[i] > max)
            {
                max = parr[i];
                resultado = max;
            }
        }
        if (tstavg == 1) //Verificar si la operacion fue average para calcular bien el resultado
        {
            resultado = suma/length;
        }
    }
    fprintf(fout, "%d", resultado);   
}

void feature6(FILE *fin, struct Obj_t *pobj){ 

    char *buffer6[128];
    fgets(buffer6, sizeof(buffer6),fin);
    char *token;
    token = strtok(buffer6, ","); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
    if (token == NULL)
    {
        printf("No hay elementos en el arreglo");
        EXIT_FAILURE;
    }
    char *nombre = token;
    char *token2;
    token2 = strtok(NULL,"");
    int ced = atoi(token2);
            
    pobj->nombre = nombre;
    pobj->cedula = ced;                   
}

void feature7(FILE *fout, struct Obj_t *pobj){
    fprintf(fout, "\n");
    fprintf(fout,"%d",pobj->cedula);
    fprintf(fout, ", ");
    fprintf(fout,"%s",pobj->nombre);
}

void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){ 
    char buffer8[64];
    char *status8 =  NULL;
    char *token;
    char *token2;
    int nrocursos = 0;
    char namecurso[32];
    int creditos;
    float nota;

    int cont8 = 0; //Para controlar el ciclo que se haga solo para leer la primera linea del archivo
    char datos[256];
    status8 = fgets(buffer8, sizeof(buffer8),fin);
    
    if(status8 != NULL){
        //printf("f8: %s",buffer8);
        token = strtok(buffer8, ""); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
        if (token == NULL)
        {
            printf("No hay elementos en el arreglo");
            EXIT_FAILURE;
        }
        nrocursos = atoi(token); //Length es el entero leido de fin
        *length=nrocursos;
        //printf("f8 Length conseguido: %d\n", nrocursos);

        struct _courseInfo_t *arrcursos = malloc(sizeof(*arrcursos));
        int control = 0;
        for (int i = 0; i < nrocursos; i++)
        {
            struct _courseInfo_t curso;
            printf("Ingrese el curso %d: curso, creditos, nota:\n",i+1);
            scanf("%s", datos);
            //printf("Datos: %s\n", datos);
            token2 = strtok(datos, ","); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
            if (token2 == NULL)
            {
                printf("No hay elementos en el arreglo");
                EXIT_FAILURE;
            }
            strcpy(curso.name,token2);
            //printf("Nombre: %s\n", curso.name);
            //printf("Curso: %s\n", token2);
            while (token2 != NULL)
            {
                token2 = strtok(NULL, ",");
                if (token2 != NULL)
                {
                    if (control == 0)
                    {
                        creditos = atoi(token2);
                        curso.credits = creditos;
                        //printf("Creditos: %d\n", curso.credits);
                        //printf("Creditos: %d\n", atoi(token2));
                        control++;
                    }
                    else{
                        nota = atof(token2);
                        curso.grade = nota;
                        ////printf("Nota: %.2f\n", curso.grade);
                        //printf("Nota: %.2f\n", atof(token2));
                        control=0;
                    }              
                }    
            }
            arrcursos[i] = curso;
        }
        *pobj=arrcursos;

        /*for (int i = 0; i < nrocursos; i++)
        {
            printf("arrcursos[%d]: %s, %d, %.2f\n",i+1, (arrcursos+i)->name, (arrcursos+i)->credits, (arrcursos+i)->grade);
            //printf("Arrcursos[%d]: %s, %d, %.2f\n", i+1, arrcursos[i].name,arrcursos[i].credits, arrcursos[i].grade);
        }*/  
    }
    printf("\n");
}

void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){ 
    //printf("f9 length: %d\n", length);
    float suma = 0;
    int sumacrd = 0;
    float prom = 0;
    char respuesta[4];
    for (int i = 0; i < length; i++)
        {
            //printf("f9 Arrcursos[%d]: %s, %d, %.2f\n", i, (pobj+i)->name, (pobj+i)->credits, (pobj+i)->grade);
            suma+=((pobj+i)->grade)*(pobj+i)->credits;
            sumacrd+=(pobj+i)->credits;
        }
        prom = suma/sumacrd;

        //printf("Promedio: %.2f\n", prom);

        printf("Deseas almacenar la informacion (s) o (n)\n");
        scanf("%s", respuesta);
        //printf("Respuesta: %s\n", respuesta);
        if (respuesta[0] == 110 || respuesta[0] == 78) //n o N
        {
            fprintf(fout,"\n");
            fprintf(fout,"%s","Promedio ponderado: ");
            fprintf(fout,"%.2f", prom);
        }
        if (respuesta[0] == 115 || respuesta[0] == 83) //s o S
        {
            for (int i = 0; i < length; i++)
            {
                fprintf(fout, "\n");
                fprintf(fout,"%s",(pobj+i)->name);
                fprintf(fout, ", ");
                fprintf(fout,"%d",(pobj+i)->credits);
                fprintf(fout, ", ");
                fprintf(fout,"%.2f",(pobj+i)->grade);
                //fprintf("%s, %d, %.2f\n", i, (pobj+i)->name, (pobj+i)->credits, (pobj+i)->grade);
            }
            fprintf(fout,"\n");
            fprintf(fout, "Promedio ponderado: ");
            fprintf(fout,"%.2f", prom);   
        }
}

char *create_array(int size){
    return (char * ) malloc(sizeof(int)* size );
}
void destroy_array(char *this){
    free(this);
}

