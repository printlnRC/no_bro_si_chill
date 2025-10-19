#include "menu.h"
#include "ssh.h"
#include "nmap.h"
#include <stdio.h>
#include <stdlib.h> 

void displayMenu(void) {
    printf("\n=== MENU ===\n");
    printf("[1] Ssh\n");
    printf("[2] Nmap\n");
    printf("[64] Exit\n");
    printf("Choose an option: ");
}

int getUserSelectionForAllMenu(int selection) {

    system("cls");

    switch (selection)
    {
    case 1 :
        ssh_menu();
        break;
    case 2 :
        nmap_menu();
        break;
    case 64 :
        break;
    
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
    return selection;
    
}