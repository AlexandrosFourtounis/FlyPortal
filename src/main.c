#include "libs/utils.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    if(argc < 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    
    if(parse_file(filename) == -1){
        fprintf(stderr, "Error parsing file\n");
        return -1;
    }


    return 0;
}