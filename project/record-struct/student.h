#ifndef STUDENT_RECORD
#define STUDENT_RECORD

struct Customer
{
    int student_id; // 0, 1, 2 ....
    char name[25];
    char gender; // M -> Male, F -> Female, O -> Other
    int age;
    char city[25];
    int phone[10];
    // Login Credentials
    char login[30]; // Format : name
    char password[30];
    // login credentials
};

#endif
