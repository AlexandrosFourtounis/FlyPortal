#include "libs/utils.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    if(argc < 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    registerUser(1,"Ayo","t","t","t","t","t","t","t","t\n");
    registerUser(2,"Stelios","t","t","t","t","t","t","t","t\n");
    deleteUser(3,"Alex");
    registerUser(3,"Alex","t","t","t","t","t","t","t","t\n");
    deleteUser(3,"Alex");
    
    printf("\n");
    insert_flight_schedule(1, "12abc", "katerini", "dubai", "12", "6", "500$\n");
    print_flights();
    int all_users = print_users();
    printf("User count: %i\n", all_users);
    


    
    const char *filename = argv[1];
    if(parse_file(filename) == -1){
        fprintf(stderr, "Error parsing file\n");
        return -1;
    }
    
   

    return 0;

}