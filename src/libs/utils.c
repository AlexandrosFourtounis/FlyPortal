#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

user *users = NULL;
flight_info *flights =NULL;



void registerUser(int uid, char *name, char *email, char *password, char *phone, char *address,  char *city, char *state, char *zip,char *country){
    //check if user with the samn uid already exists
    user *current = users;
    while (current != NULL) {
        if (uid == current->uid) {
            printf("User with uid %d already exists\n", uid);
            return;
        }
        current = current->next;
    }

    // Create a new user
    user *newUser = (user *)malloc(sizeof(user));
    if (newUser == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
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

    
    if (users == NULL) {
        users = newUser;
    } else {
        user *temp = users;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
}

void deleteUser(int uid, char *name){
    
    user *current = users;
    user *prev = NULL; 
    //check if the user exists or you are trolling
    while (current != NULL) {
        if (uid == current->uid) {
            if (prev == NULL) {
                users = current->next;
            } else {
                prev->next = current->next;
            }
            
            free(current->name);
            free(current->email);
            free(current->password);
            free(current->phone);
            free(current->address);
            free(current->city);
            free(current->state);
            free(current->zip);
            free(current->country);
            free(current);
            printf("User %s with uid %i erased\n", name, uid);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("User %s with uid %i does not exist\n", name, uid);
}

int print_users(){
    printf("Printing users\n");
    user *current = users;
    while(current != NULL){
        printf("Name: %s\n", current->name);
        current = current->next;
    }
}

flight_node *flights_head = NULL;

void insert_flight_schedule(airlines_t airline, char *flight_number, char *departure, char *arrival, char *departure_time, char *arrival_time, char *price) {
   
    flight_info *newFlight = (flight_info *)malloc(sizeof(flight_info));
    if (newFlight == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newFlight->airline = airline;
    newFlight->flight_number = strdup(flight_number);
    newFlight->departure = strdup(departure);
    newFlight->arrival = strdup(arrival);
    newFlight->departure_time = strdup(departure_time);
    newFlight->arrival_time = strdup(arrival_time);
    newFlight->price = strdup(price);
    
    flight_node *newNode = (flight_node *)malloc(sizeof(flight_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->flight = newFlight;
    newNode->next = NULL;
    
    if (flights_head == NULL) {
        flights_head = newNode;
    } else {
        flight_node *temp = flights_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print_flights() {
    printf("Printing flights\n");
    flight_node *current = flights_head;
    while (current != NULL) {
        printf("Airline: %d\n", current->flight->airline);
        printf("Flight Number: %s\n", current->flight->flight_number);
        printf("Departure: %s\n", current->flight->departure);
        printf("Arrival: %s\n", current->flight->arrival);
        printf("Departure Time: %s\n", current->flight->departure_time);
        printf("Arrival Time: %s\n", current->flight->arrival_time);
        printf("Price: %s\n", current->flight->price);
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
            printf("what?\n");
    }

    fclose(file);
    return 0;
}