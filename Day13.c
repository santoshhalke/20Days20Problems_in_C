#include <stdio.h>
/*
Day 13 - Pattern printing
        1
      2  2
    3  3  3
*/
int main(){
    int rows;
    printf("Enter the number of rows :");
    scanf("%d",&rows);
    for(int i=1; i<=rows; i++){
        for(int j=0; j<(rows-i); j++){
            printf("\t");
        }
        for(int k=0; k<i; k++){
            printf("%d\t\t",i);
        }
        printf("\n");
    }
    return 0;
}