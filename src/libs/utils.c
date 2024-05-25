#include "utils.h"
#include <stdlib.h>
#include <string.h>

user *users = NULL;


void registerUser(int uid, char *name, char *email, char *password, char *phone, char *address,  char *city, char *state, char *zip,char *country){

   
    user* newUser = (user*)malloc(sizeof(user));
    

    if (newUser == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
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
    
    

   
    
   
    

     
 
 
}


