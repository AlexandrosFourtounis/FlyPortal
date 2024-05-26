#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

user *users = NULL;


void registerUser(int uid, char *name, char *email, char *password, char *phone, char *address,  char *city, char *state, char *zip,char *country){

    user *newUser = (user *)malloc(sizeof(user));
    if (newUser == NULL) {
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newUser->uid = uid;
    newUser->name = strdup(name);
    newUser->email = strdup(email);
    newUser->password = strdup(password);
    newUser->phone = strdup(phone);
    newUser->address = strdup(address);
    newUser->city = strdup(city);
    newUser->state = strdup(state);
    newUser->zip = strdup(zip);
    newUser->country = strdup(country);
    newUser->flights_head = NULL;
    newUser->flights_tail = NULL;
    newUser->flights = NULL;
    newUser->next = NULL;


    if(users == NULL){
        users = newUser;
    }else{
        user *current = users;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newUser;
    }
 
}

int print_users(){
    printf("Printing users\n");
    user *current = users;
    while(current != NULL){
        printf("Name: %s\n", current->name);
        current = current->next;
    }
}

int parse_file(const char *filename)
{
    if (!filename)
    {
        fprintf(stderr, "filename is null\n");
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char action[2];

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (line[0] == '-')
        {
            int id;
            char action[2], name[50], email[50], password[50], telephone[50], address[50], city[50], state[50], zip[50], country[50];
            sscanf(line, "%*s %s %d %s %s %s %s %s %s %s %s %s", action, &id, name, email, password, telephone, address, city, state, zip, country);
            // printf("Action: %s, ID: %d, Name: %s, Email: %s, Password: %s, Telephone: %s, Address: %s, City: %s, State: %s, ZIP: %s, Country: %s\n", action, id, name, email, password, telephone, address, city, state, zip, country);
            registerUser(id, name, email, password, telephone, address, city, state, zip, country);
        }
        else
            printf("what?");
    }

    fclose(file);
    return 0;
}

