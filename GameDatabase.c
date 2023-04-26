#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_welcome_message(); 
void print_menu(); 

int main() {
    
    print_welcome_message(); 
    print_menu();

    printf("\nHello World!\n");
    
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