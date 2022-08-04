#include <stdio.h>
typedef struct Student {
    double grade;
    unsigned int courses_taken;
    char name[8];
    unsigned char age;
}Student;

int main(){
    FILE* f = fopen("binary_structs", "rb");
    Student students[5];

    fwrite(students, sizeof(Student), 5, f);

    for(int i = 0; i < 5; i++)
    {
        printf("%lf %u %s %c\n", students[i].grade, students[i].courses_taken, 
        students[i].name, students[i].age);
    }
    fclose(f);

    return 0;
}
