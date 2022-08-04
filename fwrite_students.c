#include <stdio.h>
typedef struct Student {
    double grade;
    unsigned int courses_taken;
    char name[8];
    unsigned char age;
}Student;

int main(){
    FILE* f = fopen("binary_structs", "wb");
    Student students[5];
    students[0] = (Student){2.3,      100, "IVAN",    25};
    students[1] = (Student){512.13,   24,  "PETAR",   21};
    students[2] = (Student){-123.51,  12,  "GEORGI",  12};
    students[3] = (Student){125.1,    50,  "EVLOGI", 122};
    students[4] = (Student){1232.213, 23, " LONG",    30};

    fwrite(students, sizeof(Student), 5, f);
    fclose(f);

    return 0;
}