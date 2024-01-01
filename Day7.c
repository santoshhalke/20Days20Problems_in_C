#include <stdio.h>
#include <string.h>
/* Day 7 -
String manipulation in c language
1. Reverse a String
2. Count Alphabets, Vowels and Consonants
3. Check Palindrome
4. Exit
*/
//Function to print the menu 
void printMenu(){
    printf("\n***** MENU ***** \n");
    printf("Enter 0 : To exit..\n");
    printf("Enter 1 : To update your string\n");
    printf("Enter 2 : To reverse string\n");
    printf("Enter 3 : To count the number of words in string\n");
    printf("Enter 4 : To get vowel number\n");
    printf("Enter 5 : To get consonant number\n");
    printf("Enter 6 : To check if string is palindrome\n");
    printf("Enter your choice :");
}

// Function to reverse string 
char* reverseString(char string[],int size){
    char *ptr=string;
    for(int i=0,j=1; i<(strlen(string))/2; i++,j++){
        char temp = ptr[i];
        ptr[i] = ptr[strlen(string)-j];
        ptr[strlen(string)-j] = temp;
    }
    return ptr;
}

//Function to count the number of alphabets in string
void countAlphabets(char string[],int size){
    int count = strlen(string);
    printf("\nNumber of alphabets are %d\n",count);
} 

//Calculates the number of vowels in the string
void countVowels(char string[],int size){
    int count=0;
    for(int i=0; i<strlen(string); i++){
        if(string[i] == 'A' || string[i] == 'a') {
            count++;
        }
        else if(string[i] == 'E' || string[i] == 'e') {
            count++;
        }
        else if(string[i] == 'I' || string[i] == 'i') {
            count++;
        }
        else if(string[i] == 'O' || string[i] == 'o') {
            count++;
        }
        else if(string[i] == 'U' || string[i] == 'u') {
            count++;
        }
        else {
            continue;
        }
    }
    printf("\nThe number of vowels are %d\n",count);
}

//Calculates the number of Consonants in the string  
void countConsonants(char string[],int size){
    int count=0;
    for(int i=0; i<strlen(string); i++){
        if(string[i] == 'A' || string[i] == 'a') {
            continue;
        }
        else if(string[i] == 'E' || string[i] == 'e') {
            continue;
        }
        else if(string[i] == 'I' || string[i] == 'i') {
            continue;
        }
        else if(string[i] == 'O' || string[i] == 'o') {
            continue;
        }
        else if(string[i] == 'U' || string[i] == 'u') {
            continue;
        }
        else {
            count++;
        }
    }
    printf("\nThe number of consonants are %d\n",count);
}

//Functions to check if given string is palindrome or not 
int palindrome(char string[],int size){
    for(int i=0,j=(strlen(string)-1); i<(strlen(string)/2); i++,j--){
        if(string[i] != string[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int choice=0;
    char string[1000],*ptr;
    printf("Enter your string :");
    scanf("%s",string);
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("\nExiting..\n");
                break;
            case 1:
                printf("\nYour previous string is : %s",string);
                printf("\nEnter new string :");
                scanf("%s",string);
                printf("\nUpdation Complete..\n");
                break;
            case 2:
                ptr = reverseString(string,1000);
                printf("%s\n",ptr);
                printf("String reversed successfully..\n");
                break;
            case 3:
                countAlphabets(string,1000);
                break;
            case 4:
                countVowels(string,1000);
                break;
            case 5:
                countConsonants(string,1000);
                break;
            case 6:
                if(palindrome(string,1000)) {
                    printf("\nGiven string is palindrome..\n");
                }
                else {
                    printf("\nGiven string is not palindrome..\n");
                }
                break;
            default :
                printf("\nInvalid choice..\n***Enter valid choice***\n");
        }
    }while(choice);
    return 0;
}