//enum for airlines
typedef enum {
    AEROMEXICO,
    VIVAAEROBUS,
    VOLARIS,
    INTERJET,
    TAR,
    AEROMAR,
    MAGNICHARTERS,
    MAYA
} airlines_t;

typedef struct flight_info{
    airlines_t airline;
    char *flight_number;
    char *departure;
    char *arrival;
    char *departure_time;
    char *arrival_time;
    char *price;
} flight_info;

typedef struct flight_node{
    flight_info *flight;
    struct flight_node *next;
} flight_node;

typedef struct suggested_flights{
    struct flight_info *info;
    struct flight_node *prev;
    struct flight_node *next;
} suggested_flights;

typedef struct user{
    int uid;
    char *name;
    char *email;
    char *password;
    char *phone;
    char *address;
    char *city;
    char *state;
    char *zip;
    char *country;
    struct suggested_flights *flights_head;
    struct suggested_flights *flights_tail;
    struct flight_node *flights;
    struct user *next;
} user;
void registerUser(int uid, char *name, char *email, char *password, char *phone, char *address,  char *city, char *state, char *zip,char *country);