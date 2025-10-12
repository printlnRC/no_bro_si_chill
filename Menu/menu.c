#include "menu.h"
#include "ssh.h"
#include <stdio.h>
#include <stdlib.h> 

void displayMenu(void) {
    printf("\n=== MENU ===\n");
    printf("[1] Ssh\n");
    printf("[2] Option\n");
    printf("[64] Exit\n");
    printf("Choose an option: ");
}

int getUserSelectionForAllMenu(int selection) {

    system("cls");

    switch (selection)
    {
    case 1 :
        printf("Menu of ssh.\n");
        ssh_menu();
        break;
    case 2 :
        printf("Option 2 selected.\n");
        break;
    case 64 :
        break;
    
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
    return selection;
    
}