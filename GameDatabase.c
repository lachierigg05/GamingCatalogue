#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX_TITLE_LENGTH 70
#define MAX_PLATFORM_LENGTH 70

struct Game {
    char title[MAX_TITLE_LENGTH]; 
    int year;
    char platform[MAX_PLATFORM_LENGTH];
    struct Game *next; 
};

void save_game_collection(struct Game *head);
void print_game_collection(struct Game *head); 

int main() {

    struct Game *game_collection = NULL; 

    printf("\n=============================\n"); 
    printf("Welcome to GAME ARCHIVER 1.0\n");
    printf("=============================\n"); 
    int selection;  

    do {
        printf("\nPlease select from the following options: \n\n"); 
        printf("1. Print Game Collection.\n"); 
        printf("2. Add a game to my collection.\n"); 
        printf("3. Remove a game from my collection.\n"); 
        printf("4. Edit a game information from my collection.\n");
        printf("5. Quit\n\n");
        scanf("%d", &selection);

        if (selection == 1) {
            print_game_collection(game_collection); 
        }

        // } else if (selection == 2) {

        // } else if (selection == 3) {

        // } else if (selection == 4) {

        // } 

    } while (selection != 5); 
    
    printf("\nThanks for using GAME ARCHIVER. Goodbye!\n\n"); 

    return 0; 
}


void print_game_collection(struct Game *head) {
    if (head == NULL) {
        printf("Your collection is currently empty.\n");
        printf("Please add games to your collection and try again.\n"); 
    } 
    struct Game *current = head; 

    while (current != NULL) {
        printf("%s (%d) (%s)", current->title, current->year, current->platform);
        current = current->next;  
    }

} 
