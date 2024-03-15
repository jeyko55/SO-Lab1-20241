#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>




int tests(int argc, char *argv[]){
    // Atributos y constantes
    #define MAX_ARGS 3
    #define SIZE 20
    #define MAX_LINE_LENGTH 100
    #define MAX_NUM_LINES 100
    #define SIZE_TEST_7 100
    #define INITIAL_SIZE 5
    
    
    FILE *archivo_entrada = fopen(argv[1], "r"); // Abrir archivo de entrada para lectura
    FILE *archivo_salida = fopen(argv[2], "w"); // Abrir archivo de salida para escritura
    struct stat input_stat, output_stat;
    char line[MAX_LINE_LENGTH];
    char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];
    int numLines = 0;

    //test 1
    if (argc > MAX_ARGS) {
        // Muchos argumentos
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    // Test 2
    // Abriendo el archivo
    if(archivo_entrada == NULL){
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    // Test 3
    // Abriendo el archivo
    // Verificando que el archivo de salida se pueda abrir
    if(archivo_salida == NULL){
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        exit(1);
    }

    // Test 4
    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

    // Test 5
    if (stat(argv[1], &input_stat) == 0 && stat(argv[2], &output_stat) == 0) {
        if (input_stat.st_ino == output_stat.st_ino) {
            fprintf(stderr, "reverse: input and output file must differ\n");
            exit(1);
        }
    }

    // Test 6
    // Leer y almacenar las líneas del archivo de entrada en un arreglo
    while (fgets(line, MAX_LINE_LENGTH, archivo_entrada) != NULL && numLines < MAX_NUM_LINES) {
        strcpy(lines[numLines], line);
        numLines++;
    }

    // Almacenar las líneas en orden inverso en el archivo "6.other"
    for (int i = numLines - 1; i >= 0; i--) {
        fprintf(archivo_salida, "%s", lines[i]);
    }

    //******************************************************************************
    //Ojo: Cuando terminemos el 7, quitar este return:
    return 0;

    // Test 7
    /*
    char **lineas = (char **)malloc(INITIAL_SIZE * sizeof(char *));
    if (lineas == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }

    // Número actual de elementos en el array
    int num_lineas = 0;
    
    // Capacidad actual del array
    int capacidad = INITIAL_SIZE;
    
    // Bucle para leer líneas desde la entrada estándar
    char buffer[MAX_LINE_LENGTH]; // Suponemos líneas de no más de 100 caracteres

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {

        // Elimina el carácter de nueva línea si está presente
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Copia la línea en una nueva área de memoria
        char *nueva_linea = strdup(buffer);
        if (nueva_linea == NULL) {
           fprintf(stderr, "Error de asignación de memoria\n");
           exit(1);
        }
        
        // Aumenta la capacidad del array si es necesario
        if (num_lineas >= capacidad) {
           capacidad *= 2;
           char **nuevo_array = (char **)realloc(lineas, capacidad * sizeof(char *));

            if (nuevo_array == NULL) {
                fprintf(stderr, "Error de reasignación de memoria\n");
                exit(1);
            }
        lineas = nuevo_array;
        }
        
        // Agrega la nueva línea al array
        lineas[num_lineas] = nueva_linea;
        num_lineas++;
    }

    //Operación de invertir
    for (int i = num_lineas - 1; i >= 0; i--) {
        fprintf(stdout, "%s", lineas[i]);
    }

    // Libera la memoria asignada
    for (int i = 0; i < num_lineas; i++) {
        free(lineas[i]);
    }
    free(lineas);

    return 0;
    */

   // Cerrando los archivos de entrada y salida
   fclose(archivo_entrada);
   fclose(archivo_salida);
}



int main(int argc, char *argv[]) {

    tests(argc, argv);
}
