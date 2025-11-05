#include "wpscan.h"
#include "menu.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h> 

void wpscan_menu(void) {
    int choice = 0;

    do {
        print_logo();
        printf("=== WPScan Menu ===\n");
        printf("[1] Scan WordPress Site\n");
        printf("[64] Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1 :
            printf("Scanning WordPress site...\n");
        break;
        case 2 :
            printf("Back.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 64);
}