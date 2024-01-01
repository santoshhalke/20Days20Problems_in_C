#include <stdio.h>

// Defining an enumeration CardSuit with values for the four suits Hearts, Diamonds, Clubs, and Spades.
enum CardSuit{
    Hearts, 
    Diamonds, 
    Clubs, 
    Spades
};

//Function printCardSuit that takes a CardSuit as a parameter and prints the corresponding suit name.
void printCardSuit(enum CardSuit current){
    switch(current){
        case Hearts:
            printf("\nThe card is Hearts.\n");
            break;
        case Diamonds:
            printf("\nThe card is Diamonds.\n");
            break;
        case Clubs:
            printf("\nThe card is Clubs.\n");
            break;
        case Spades:
            printf("\nThe card is Spades.\n");
            break;
        default :
            printf("\nInvalid card..\n");
    }
}

int main(){
    //creating variables of type CardSuit and assign values to them. 
    enum CardSuit card1 = Hearts;
    enum CardSuit card2 = Clubs;
    enum CardSuit card3 = Diamonds;
    enum CardSuit card4 = Spades;
    
    //printCardSuit function to print the names of the suits.
    printf("***Third card***");
    printCardSuit(card3);

    printf("***Second card***");
    printCardSuit(card2);

    printf("***Fourth card***");
    printCardSuit(card4);

    printf("***First card***");
    printCardSuit(card1);

    return 0;
}