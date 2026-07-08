#include <stdio.h>
#include <string.h>

struct Student{
    char name [50];
    int roll;
    float marks;
};
int main(){
    struct Student S1;
    S1.roll = 12;
    S1.marks = 95.5;
    strcpy(S1.name, "Ramesh");

    printf("Name: %s\n", S1.name);
    printf("Roll no %d\n", S1.roll);
    printf("Marks: %.2f\n", S1.marks);
     printf("%s %d %.1f", S1.name, S1.roll, S1.marks);
    return 0;
}