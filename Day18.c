#include <stdio.h>
#include <stdlib.h>

//Day 18 - Implementation of Singly linked list

//Structure for node
struct Node{
    int data;
    struct Node *next;
};

// Function to print the menu
void printMenu(){
    printf("\n\t****Menu****\t\n");
    printf("Enter 1 : To add node at start\n");
    printf("Enter 2 : To add node at end\n");
    printf("Enter 3 : To add node at particular index\n");
    printf("Enter 4 : To delete node from beginning\n");
    printf("Enter 5 : To delete node from end\n");
    printf("Enter 6 : To delete node from index\n");
    printf("Enter 7 : To show linked list\n");
    printf("Enter your choice :");
}

// Function to count the number of nodes
int countNodes(struct Node *head){
    int count=0;
    if(head == NULL){
        return count;
    }
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;
}

// Function to print the linked list 
void printLinkedList(struct Node *head){
    if(head == NULL){
        printf("Linked List empty..\n");
        return;
    }
    printf("\nYour Linked List is :");
    while(head != NULL){
        printf("\t%d",head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to add node at starting of linked list 
struct Node* insertAtBegin(struct Node *head){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data :");
    scanf("%d",&node->data);
    if(head == NULL){  // Checks if head is null or not 
        node->next = NULL;
        printf("Inserted Successfully...\n");
    }
    else{
        node->next = head;
        printf("Inserted Successfully...\n");
    }
    printLinkedList(node);
    return node;
}

// Function for adding node at end of linked list 
struct Node* insertAtEnd(struct Node *head){
    struct Node *node,*temp;
    node = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){  // Checks if head is null or not 
        printf("Enter data to Insert :");
        scanf("%d",&node->data);
        node->next = NULL;
        printf("Inserted Successfully...\n");
        return node;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    printf("Enter data :");
    scanf("%d",&node->data);
    node->next = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    printf("Successfully Inserted...\n");
    printLinkedList(head);
    // free(node);
    // free(temp);
    return head;
}

// Function for inserting at index
struct Node* insertAtIndex(struct Node *head){
    int index;
    printf("Enter index :");
    scanf("%d",&index);
    if(index == 0){
        head = insertAtBegin(head);
    }
    else if(index == countNodes(head)){
        head = insertAtEnd(head);
    }
    else if(index < countNodes(head)){
        struct Node *temp,*node;
        node = (struct Node *)malloc(sizeof(struct Node));
        // temp = (struct Node *)malloc(sizeof(struct Node));
        temp = head;
        printf("Enter data:");
        scanf("%d",&node->data);
        while(--index){
            temp = temp->next;
        }
        printf("Enter data :");
        scanf("%d",&node->data);
        node->next = temp->next;
        temp->next = node;
        printf("Inserted Successfully...\n");
        // free(temp);
        // free(node);
        printLinkedList(head);
    }
    else{
        printf("Invalid index...\n");
    }
    
    return head;
}

// Function to Delete a node from beginning of linked list
struct Node* deleteFromBegin(struct Node *head){
    head = head->next;
    printf("Deleted Successfully..\n");
    printLinkedList(head);
    return head;
}

// Function to delete from ending of linked list
struct Node* deleteFromEnd(struct Node *head){
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    if(countNodes(head) == 1){
        return NULL;
    }
    while(ptr->next->next == NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    printf("Deleted Successfully...\n");
    printLinkedList(head);
    // free(ptr);
    return head;
}

// Function to delete from given index
struct Node* deleteFromIndex(struct Node *head){
    int index;
    printf("Enter index :");;
    scanf("%d",&index);
    if(index == 0){
        head = deleteFromBegin(head);
    }
    else if(index == countNodes(head)){
        head = deleteFromEnd(head);
    }
    else if(index < countNodes(head)){
        struct Node *ptr;
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr = head;
        index -= 1;
        while(--index){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        printf("Deleted Successfully....\n");
        printLinkedList(head);
        // free(ptr);
    }
    return head;
}

// Driver code 
int main(){
    int choice;
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    printf("Linked List Created Successfully...\n");
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("\nExiting...");
                break;
            case 1:
                head = insertAtBegin(head);
                break;
            case 2:
                head = insertAtEnd(head);
                break;
            case 3:
                head = insertAtIndex(head);
                break;
            case 4:
                head = deleteFromBegin(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                head = deleteFromIndex(head);
                break;
            case 7:
                printLinkedList(head);
                break;
            default :
                printf("Invalid Choice..\n***Enter valid Choice\n");
        }
    }while(choice);
    free(head);
    return 0;
}