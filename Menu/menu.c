#include "menu.h"
#include <stdio.h>

void displayMenu(void) {
    printf("\n=== MENU ===\n");
    printf("1. Exit\n");
    printf("Choose an option: ");
}

int getUserSelection(int selection) {
    switch (selection)
    {
    case 1 :
        break;
    
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
    return selection;
    
}