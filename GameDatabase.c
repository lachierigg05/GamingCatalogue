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
void sort_by_platform(struct Game *head); 
void remove_game_from_collection(struct Game **head); 
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
        printf("5. Sort library by platform.\n"); 
        printf("6. Quit\n\n");

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
            remove_game_from_collection(&head); 
        } else if (selection == 4) {
            
        } else if (selection == 5) {
            sort_by_platform(head); 
        }
        
        else if (selection > 6 || selection < 1) {
            printf("Please enter a valid command.\n");
        }

    } while (selection != 6); 
    
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
    clear_screen();  
    getchar(); 
    printf("Please enter the title of your game: ");
    fgets(new_game->title, MAX_TITLE_LENGTH, stdin);
    new_game->title[strcspn(new_game->title, "\n")] = '\0';
    
    printf("Please enter the year your game was released: ");
    scanf("%d", &new_game->year);

    getchar(); 
    printf("Please enter the platform of your game: ");
    fgets(new_game->platform, MAX_PLATFORM_LENGTH, stdin);
    new_game->platform[strcspn(new_game->platform, "\n")] = '\0';

    struct Game **current = head;

    while (*current != NULL && strcmp(new_game->title, (*current)->title) > 0) {
        current = &(*current)->next;
    }

    new_game->next = *current;
    *current = new_game;

    printf("\nYour game has been added to the library.\n");
    printf("Press enter to continue...");
    fflush(stdout);
    getchar();

    clear_screen(); 
  
} 

void remove_game_from_collection(struct Game **head) {
    if (*head == NULL) {
        clear_screen();  
        printf("Your collection is currently empty.\n");
        printf("Please add games to your collection and try again.\n");
        printf("Press Enter to continue... ");
        getchar();
        getchar(); // Waits for user to press the enter key   
        clear_screen();
        return;
    }

    printf("Please enter the title of the game you want to remove: ");
    char game_title[MAX_TITLE_LENGTH];
    getchar();
    fgets(game_title, MAX_TITLE_LENGTH, stdin);
    game_title[strcspn(game_title, "\n")] = '\0';

    struct Game *current = *head;
    struct Game *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->title, game_title) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("\nThe game '%s' has been removed from the library.\n", game_title);
            printf("Press enter to continue...");
            fflush(stdout);
            getchar();
            clear_screen();
            return;
        }
        previous = current;
        current = current->next;
    }
    
    clear_screen();  
    printf("\nSorry, the game '%s' was not found in your collection.\n", game_title);
    printf("Press enter to continue...");
    fflush(stdout);
    getchar();
    clear_screen();
}

void sort_by_platform(struct Game *head) {
    struct Game *current = head;
    struct Game *next_game = NULL;
    int swapped = 0;
    char temp_platform[MAX_PLATFORM_LENGTH];
    
    if (head == NULL) {
        clear_screen();
        printf("Your collection is currently empty.\n");
        printf("Please add games to your collection and try again.\n");
        printf("Press Enter to continue... ");
        getchar();
        getchar(); // Waits for user to press the enter key
        clear_screen();   
        return;
    } 

    do {
        swapped = 0;
        current = head;
        
        while (current->next != next_game) {
            if (strcmp(current->platform, current->next->platform) > 0) {
                strcpy(temp_platform, current->platform);
                strcpy(current->platform, current->next->platform);
                strcpy(current->next->platform, temp_platform);
                swapped = 1;
            }
            current = current->next;
        }
        next_game = current;
    } while (swapped);

    clear_screen();
    printf("Your library has been sorted.\n");
}

void clear_screen() {
    printf("\033[2J\033[1;1H"); // ANSI escape codes to clear the screen
}
