#include <stdio.h>
/*
Day 15 - Pattern printing
    1
   121
  12321
 1234321
123454321
*/
int main(){
    int number,rows,columns,space,extra;
    printf("Enter number of rows :");
    scanf("%d",&number);
    for(rows=1; rows<=number; rows++){
        for(space=1; space<=number-rows; space++){
            printf(" ");
        }
        for(columns=1; columns<=rows; columns++){
            printf("%d",columns);
        }
        for(extra=rows-1; extra >=1; extra--){
            printf("%d",extra);
        }
        printf("\n");
    }
    return 0;
}