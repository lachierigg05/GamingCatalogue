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

void print_game_collection(struct Game *head);
void add_game_to_collection(struct Game **head);
void clear_screen();  

int main() {

    struct Game *head = NULL; 

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

        if (scanf("%d", &selection) != 1) {
            printf("Please enter a valid input.\n");
            while (getchar() != '\n');  // clear input buffer. 
            continue; // Skips back to the start of the loop. 
        }

        if (selection < 1 || selection > 9) {
            printf("Please enter a valid input.\n");
        } else if (selection == 1) {
            print_game_collection(head); 
        } else if (selection == 2) {
            add_game_to_collection(&head); 
        } else if (selection == 3) {

        } else if (selection == 4) {

        } else if (selection > 5 || selection < 1) {
            printf("Please enter a valid command.\n");
        }

    } while (selection != 5); 
    
    printf("\nThanks for using GAME ARCHIVER. Goodbye!\n\n"); 

    return 0; 
}



void print_game_collection(struct Game *head) {
    clear_screen();
    
    if (head == NULL) {
        printf("Your collection is currently empty.\n");
        printf("Please add games to your collection and try again.\n");
        printf("Press Enter to continue... ");
        getchar();
        getchar(); // Waits for user to press the enter key   
        clear_screen();
        return;
    } 
    struct Game *current = head;

    printf("\n====================================\n");
    printf("     ||  YOUR GAME COLLECTION ||    \n");
    printf("====================================\n");


    while (current != NULL) {
        printf("%s (%d) (%s)\n", current->title, current->year, current->platform);
        current = current->next;  
    }

    printf("\n\nPress Enter to continue... ");
    fflush(stdout); 
    getchar();
    getchar();

    clear_screen(); 

} 

void add_game_to_collection(struct Game **head) {
    struct Game *new_game = malloc(sizeof(struct Game));  
    
    getchar(); 
    printf("Please enter the title of your game: ");
    fgets(new_game->title, MAX_TITLE_LENGTH, stdin);
    new_game->title[strcspn(new_game->title, "\n")] = '\0';
    
    printf("Please enter the year your game was released: ");
    scanf("%d", &new_game->year);

    getchar(); 
    printf("Please enter the platform of your game: ");
    fgets(new_game->platform, MAX_TITLE_LENGTH, stdin);
    new_game->platform[strcspn(new_game->platform, "\n")] = '\0';

    struct Game **current = head;

    new_game->next = *head;
    *head = new_game;

    printf("\nYour game has been added to the library.\n");
    printf("Press enter to continue...");
    fflush(stdout);
    getchar();

    clear_screen(); 
  
}  

void clear_screen() {
    printf("\033[2J\033[1;1H"); // ANSI escape codes to clear the screen
}
