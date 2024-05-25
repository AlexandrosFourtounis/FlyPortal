#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


int parse_file(const char *filename){
    if(!filename){
        fprintf(stderr, "filename is null\n");
    }
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char action[2];
    int id;
    while ((read = getline(&line, &len, file)) != -1)
    {
        sscanf(line, "- %s %d", action, &id);
        if (strcmp(action, "R") == 0)
        {
            printf("User with ID %d registered\n", id);
        }
        else if(strcmp(action,"U") == 0){
            printf("User with ID %d unregistered\n", id);
        }
    }

    fclose(file);
    return 0;
}