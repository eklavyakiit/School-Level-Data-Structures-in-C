#include <stdio.h>

int main() {
    int score = 100;
    int *pScore = &score;

    printf("Old score: %d\n", score);

    // Modify the value at the address pScore is holding
    *pScore = 150; 

    printf("New score (via variable): %d\n", score);
    printf("New score (via pointer): %d\n", *pScore);

    return 0;
}