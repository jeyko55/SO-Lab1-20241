#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ARGS 3

#define MAX_LINE_LENGTH 201
#define MAX_NUM_LINES 1000
#define SIZE_TEST_7 100

int main(int argc, char *argv[]) {
    

    //test 1
    
    if (argc > MAX_ARGS) {
        //muchos argumentos
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    //test2
    FILE *archivo = fopen(argv[1], "r");
    if(archivo == NULL){
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }

    //test3
    // Abriendo el archivo
    FILE *archivo_salida = fopen(argv[2], "w");
    // Verificando que el archivo de entrada se pueda abrir
    if(archivo_salida == NULL){
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }

    //test4
    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

    //test5
    struct stat input_stat, output_stat;
    if (stat(argv[1], &input_stat) == 0 && stat(argv[2], &output_stat) == 0) {
        if (input_stat.st_ino == output_stat.st_ino) {
            fprintf(stderr, "reverse: input and output file must differ\n");
            exit(1);
        }
    }
    //test6

    char line[MAX_LINE_LENGTH];
    char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];
    int numLines = 0;

    FILE *iF = fopen(argv[1], "r");
    // Leer y almacenar las líneas del archivo en un arreglo
    while (fgets(line, MAX_LINE_LENGTH, iF) != NULL && numLines < MAX_NUM_LINES) {
        strcpy(lines[numLines], line);
        numLines++;
    }

    fclose(iF);

     // Abrir el archivo "6.other" para escritura
    FILE *oF = fopen(argv[2], "w");
    // Almacenar las líneas en orden inverso en el archivo "6.other"
    for (int i = numLines - 1; i >= 0; i--) {
        fprintf(oF, "%s", lines[i]);
    }

    fclose(oF);

    return 0;

////////////////////////////////////////////////////////
    //test7

    char line7[SIZE_TEST_7];

    // Leer desde la entrada estándar (stdin) y escribir en la salida estándar (stdout)
    while (fgets(line7, SIZE_TEST_7, stdin) != NULL) {
        // Escribir la línea leída en la salida estándar
        printf("%s", line7);
    }

    return 0;
    
/*
    char input[SIZE_TEST_7];
    
    fgets(input, sizeof(input), stdin);

    fprintf(stdout, "%s\n", input);

    //comparar stdin con stdout
    if (strcmp(input, stdout) == 0) {
        return 0;
    }

*/
    //imprimir argumentos
    int i;
    for(i = 0; i < MAX_ARGS; ++i){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
      
}
