#ifndef FACULTY_RECORD
#define FACULTY_RECORD

struct Faculty
{
    int faculty_id; // 0, 1, 2 ....
    char name[25];
    char gender; // M -> Male, F -> Female, O -> Other
    int age;
    char city[25];
    int phone[10];
    char dept[20];
    char course[20];
    int courseid[10];
    char login[30]; // Format : name
    char password[30];
};

#endif
