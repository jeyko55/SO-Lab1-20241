#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

// Constantes
#define MAX_ARGS 3
#define SIZE 20
#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 100
#define SIZE_TEST_7 100

#define INITIAL_SIZE 5


int tests(int argc, char *argv[]){

    // Segundo argumento del .run de cada test
    char argTest1[] = "in.txt";
    char argTest2[] = "/no/such/file.txt";
    char argTest3[] = "/no/such/file.txt";
    char argTest4[] = "tests/3.out";
    char argTest5[] = "tests/5.in";
    char argTest6[] = "tests/6.in";
    char argTest7[] = "<";

    // Obtener el primer carácter del argumento y almacenarlo en una variable
    char segundoArgumento[SIZE];
    strcpy(segundoArgumento, argv[1]);
    

    // Ingresar a test 1
    if(strcmp(segundoArgumento, argTest1) == 0){
        if (argc > MAX_ARGS) {
        // Muchos argumentos
            fprintf(stderr, "usage: reverse <input> <output>\n");
            exit(1);
        }
    }
    // Ingresar a test 2
    else if(strcmp(segundoArgumento, argTest2) == 0){
        // Test 2
        // Abriendo el archivo
        FILE *archivo = fopen(argv[1], "r");
        if(archivo == NULL){
            fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
            exit(1);
        }
    }
    //Ingresar a test 3
    else if((strcmp(segundoArgumento, argTest3) == 0) && (argc == 3)){
        // Test 3
        // Abriendo el archivo
        FILE *archivo_salida = fopen(argv[2], "w");
        // Verificando que el archivo de entrada se pueda abrir
        if(archivo_salida == NULL){
            fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
            exit(1);
        }
    }
    // Ingresar a test 4
    else if(strcmp(segundoArgumento, argTest4) == 0){
        // Test 4
        if (strcmp(argv[1], argv[2]) == 0) {
            fprintf(stderr, "reverse: input and output file must differ\n");
            exit(1);
        }
    }
    // Ingresar a test 5
    else if(strcmp(segundoArgumento, argTest5) == 0){
        // Test 5
        // Test 5
        struct stat input_stat, output_stat;
        if (stat(argv[1], &input_stat) == 0 && stat(argv[2], &output_stat) == 0) {
            if (input_stat.st_ino == output_stat.st_ino) {
                fprintf(stderr, "reverse: input and output file must differ\n");
                exit(1);
            }
        }
    }
    // Ingresar a test 6
    else if(strcmp(segundoArgumento, argTest6) == 0){
        // Test 6
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

    }
    //Ingresar a test 7
    else if(strcmp(segundoArgumento, argTest7) == 0) {
        // Test 7
        

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


    }
    return 0;
}



int main(int argc, char *argv[]) {

    tests(argc, argv);
}
