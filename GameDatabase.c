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

// Function Prototypes
void print_welcome_message(); 
void print_menu();
void print_collection(Game *head); 
Game *add_game(Game *head);
Game *remove_game(Game *head); 

int main() {
    
    Game *head = NULL;

    print_welcome_message(); 
    
    int i = 0; 
    while (i != 1) {
        print_menu();
        int selection;
        scanf("%d", &selection);
        getchar(); // Clears the input buffer.
        
        switch (selection) {
            case 1:
                print_collection(head); 
                break; 
            case 2: 
                head = add_game(head); 
                break;
            case 3:
                head = remove_game(head);
                break;
            case 4:
                printf("Thanks for using Game Archiver!\n"); 
                printf("Goodbye!\n"); 
                return 0; 
            case 5:
            default: 
                printf("Please enter a valid command.\n"); 
        }
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

Game *add_game(Game *head) {
        // Creates a new game node and adds it to the linked list.
        
        Game *new_game = malloc(sizeof(Game));
        printf("Enter the title of the game: ");
        scanf("%[^\n]", new_game->title);
        while(getchar() != '\n'); // Clears the input buffer.
        
        printf("Enter the release year of the game: ");
        scanf("%d", &new_game->year);
        while(getchar() != '\n'); // Clears the input buffer.
        
        printf("Enter the platform of the game: ");
        scanf("%[^\n]", new_game->platform);
        while(getchar() != '\n'); // Clears the input buffer.

        printf("Enter the price of the game: ");
        scanf("%f", &new_game->price);
        while(getchar() != '\n'); // Clears the input buffer.

        new_game->next = NULL;
        if (head == NULL) {
            // If the list is empty, set the new node as the head.
            head = new_game;
            return head;
        } else {
            // If the list is not empty, set the new node as the next node.
            Game *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_game;
            return head;
        }
} 
        
Game *remove_game(Game *head) {
    // Removes a game from the linked list.
    char to_remove[MAX_STRING_LENGTH]; 
    printf("Which game would you like to remove?\n");
    scanf("%[^\n]", to_remove);
    while(getchar() != '\n'); // Clears the input buffer. 
    
    if (head == NULL) {
        // If the list is empty, print the appropriate error message...
        printf("Your game collection is empty. Please add games to your collection.\n");
        return head;
    } else if (strcmp(head->title, to_remove) == 0) {
        // If the list is not empty, and the head node is the game to remove...
        Game *temp = head;
        head = head->next;
        free(temp);
        return head;
    } else if (strcmp(head->next->title, to_remove) == 0) {
        // If the list is not empty, and the next node is the game to remove...
        Game *temp = head->next;
        head->next = head->next->next;
        free(temp);
        return head;
    } else {
        // If the list is not empty, and the game to remove is not the head or next node...
        Game *current = head;
        while (current->next != NULL) {
            if (strcmp(current->next->title, to_remove) == 0) {
                // If the next node is the game to remove...
                Game *temp = current->next;
                current->next = current->next->next;
                free(temp);
                return head;
                break;
            } else {
                // If the next node is not the game to remove...
                current = current->next;
                break;
            } 
            return head;
            break;
        }
    }
    return head; 
}









