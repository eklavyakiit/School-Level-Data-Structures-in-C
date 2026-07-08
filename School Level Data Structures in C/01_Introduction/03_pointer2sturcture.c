#include <stdio.h>
struct student{
    int roll;
};
int main(){
    struct student s1;
    struct student *ptr = &s1;
    ptr->roll = 10;
    // (*ptr).roll = 10;
    printf("%d", ptr->roll); //→ Accesses roll through the pointer ptr as ptr stores the address of s1.
    printf("%d", s1.roll); //→ Accesses roll directly from the structure variable s1.
}