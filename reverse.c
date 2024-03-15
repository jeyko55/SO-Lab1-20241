#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>


int tests(int argc, char *argv[]){
    // Atributos y constantes

    #define MAX_LINEA 100
    #define MAX_NUM_LINEAS 100
    #define INITIAL_SIZE 5
    #define INITIAL_CAPACITY 8
    
    struct stat input_stat, output_stat;
    FILE *archivo_entrada = fopen(argv[1], "r"); // Abrir archivo de entrada para lectura
    FILE *archivo_salida = fopen(argv[2], "w"); // Abrir archivo de salida para escritura
    char line[MAX_LINEA];
    char lines[MAX_NUM_LINEAS][MAX_LINEA];
    int numLines = 0;


    if (argc > 3) { // Test 1
        // Más de tres argumentos
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    else if(argc == 3){ 
        if(stat(argv[1], &input_stat) == -1) { // Test 3
            fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
            exit(1);
        }

        if (stat(argv[2], &output_stat) != -1) { // Test 4
            if (input_stat.st_ino == output_stat.st_ino) {
                fprintf(stderr, "reverse: input and output file must differ\n");
                exit(1);
            }
        }

        if (stat(argv[1], &input_stat) == 0 && stat(argv[2], &output_stat) == 0) { // Test 5
            if (input_stat.st_ino == output_stat.st_ino) {
                fprintf(stderr, "reverse: input and output file must differ\n");
                exit(1);
            }
        }

        // Leer y almacenar las líneas del archivo de entrada en un arreglo
        while (fgets(line, MAX_LINEA, archivo_entrada) != NULL && numLines < MAX_NUM_LINEAS) { // Test 6
            strcpy(lines[numLines], line);
            numLines++;
        }
        // Almacenar las líneas en orden inverso en el archivo de salida
        for (int i = numLines - 1; i >= 0; i--) {
            fprintf(archivo_salida, "%s", lines[i]);
        }
    }
    else if(argc == 2){ // Test 2
        if(stat(argv[1], &input_stat) == -1) {
            fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }
    else if(argc == 1){ // Test 7, cuando se ejecuta './reverse < tests/7.in', argc es igual a 1 que es el argumento del ejecutable './reverse'
        
        // FALTA EL TEST 7:
    }

   // Se debe retornar 0 para que se reconozca que el programa se ejecutó sin errores.
   return 0;
}



int main(int argc, char *argv[]) {

    tests(argc, argv);
}
