#include <stdio.h>

/*
Day 14 - Pattern priniting
    3 3 3 3 3
    3 2 2 2 3
    3 2 1 2 3
    3 2 2 2 3
    3 3 3 3 3
*/

int min(int a, int b) {
    int minimum = (a < b) ? a : b;
    return minimum;
}

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int size = 2 * rows - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", rows - min(min(i, j), min(size - i - 1, size - j - 1)));
        }
        printf("\n");
    }

    return 0;
}
