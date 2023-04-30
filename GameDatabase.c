#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct Game {
    char title[MAX_STRING_LENGTH];
    int year; 
    char platform[MAX_STRING_LENGTH];
    float price;
    struct Game *next; 
};

typedef struct Game Game; 

void print_welcome_message(); 
void print_menu();
void print_collection(Game *head); 

int main() {
    
    Game *head = NULL;
    
    print_welcome_message(); 
    
    int i = 0; 
    while (i != 1) {
        print_menu();
        int selection;
        scanf("%d", &selection); 
        
        switch (selection) {
            case 1:
                print_collection(head); 
                break; 
            case 2: 
                break;
            case 3:
                break;
            case 4:
                printf("Thanks for using Game Archiver!\n"); 
                printf("Goodbye!\n"); 
                return 0; 
            case 5:
            default: 
                printf("Please enter a valid command.\n"); 
        }
        getchar(); // To clear the input buffer after a selection is made.
    }

    printf("\n");
    
    return 0; 
}

void print_welcome_message() {
    printf("\nWelcome to Game Archiver (v1.0)\n\n"); 
}
void print_menu() {
    printf("Please select one of the following options: \n");
    printf("1. View Game Catalogue.\n");
    printf("2. Add Game to Catalogue.\n"); 
    printf("3. Remove Game from Catalogue.\n");
    printf("4. Quit\n"); 
}
void print_collection(Game *head) {
    // If the list is empty, print the appropriate error message... 
    if (head == NULL) {
        printf("Your game collection is empty. Please add games to your collection.\n");
        return; 
    }

    // If list is not empty... 
    Game *current = head; 

    while (current != NULL) {
        int i = 1; // Game number counter
        printf("\n%d. %s\n", i, current->title); 
        printf("Release Date: %d\n", current->year); 
        printf("Platform: %s\n", current->platform);
        printf("Value: $%.2f\n\n", current->price); 
        i++; 
        current = current->next; 
    }
} 
