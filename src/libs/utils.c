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
        if (line[1] == 'R')
        {
            int id;
            char name[50], email[50], password[50], dob[50], city[50], state[50], country[50];
            int zip;
            sscanf(line, "%*s %d %s %s %s %s %s %s %d %s", &id, name, email, password, dob, city, state, &zip, country);
            printf("Action: R, ID: %d, Name: %s, Email: %s, Password: %s, DOB: %s, City: %s, State: %s, ZIP: %d, Country: %s\n", id, name, email, password, dob, city, state, zip, country);
        }
        else if (line[1] == 'A')
        {
            char mid[50], company[50], departure_time[50], arrival_time[50], arrival_location[50], departure_loc[50];
            int cost;
            sscanf(line, "%*s %s %s %d %s %s %s %s", mid, company, &cost, departure_time, arrival_time, arrival_location, departure_loc);
            printf("Action: A, MID: %s, Company: %s, Cost: %d, Departure Time: %s, Arrival Time: %s, Arrival Location: %s, Departure Location: %s\n", mid, company, cost, departure_time, arrival_time, arrival_location, departure_loc);
        }
        else
            printf("what?");
    }

    fclose(file);
    return 0;
}

