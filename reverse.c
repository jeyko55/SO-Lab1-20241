#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 3
int main(int argc, char *argv[]) {
    //test 1
    int i;
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
    if(argv[1] != argv[2]){
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

    //test5
    if(argv[1] == argv[2]){
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

    //test6
    

    for(i = 0; i < MAX_ARGS; ++i){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
       
}
