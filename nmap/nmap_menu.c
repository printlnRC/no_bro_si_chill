#include "nmap.h"

#include <stdio.h>
#include <stdlib.h> 

void nmap_menu(void) {
    int choice = 0;

    do {
        printf("=== NMAP Menu ===\n");
        printf("[1] Simple scan with nmap\n");
        printf("[2] p\n");
        printf("[3] Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1 :
            printf("Simple scan with nmap.\n");
            nmap_simple_scan();
        break;
        case 2 :
            printf("p.\n");
        break;
        case 3 :
            printf("Back.\n");
            system("cls");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 3);
}