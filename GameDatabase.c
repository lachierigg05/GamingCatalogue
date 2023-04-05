#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// system("cls || clear") is used to clear the terminal screen 
// for a better user experience. 

// Function prototypes
int print_main_menu(int selection);
void quit(); 


int main() {
    
    int selection = 0; 

    printf("\n=======================================\n");
    printf("  ||     WELCOME TO GAME ARCHIVER       || ");
    printf("\n=======================================\n");

    // Takes in user selection and initiates the appropriate function
    selection = print_main_menu(selection);
    switch (selection) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            quit(); 
            return 0;
        default: 
            printf("You entered an invalid input. Please try again."); 
    }
    
    
    return 0; 
}

// Function definitions 

int print_main_menu(int selection) {
    // Prints out the main menu where the user can input which option they would 
    // like to do on their game library. 

    printf("\nPlease choose from the following options: \n");
    printf("1. Print Game Collection\n");
    printf("2. Add Game to Collection\n");
    printf("3. Remove Game from Collection\n"); 
    printf("4. Edit a Game from Your List\n"); 
    printf("5. Quit\n\n");

    scanf("%d", &selection);  

    return selection;  
}

// Types the quit message when the user opts to quit
void quit() {
    system("clear || cls"); // Clears the terminal 
    printf("Thanks for using Game Archiver! Goodbye.\n"); 
}