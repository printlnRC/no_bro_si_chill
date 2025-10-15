#include "ssh.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h> 


void ssh_menu(void) {
    int choice = 0;

    do {
        printf("=== SSH Menu ===\n");
        printf("[1] Connect to SSH\n");
        printf("[2] Connect to SSH with Key\n");
        printf("[3] Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // pour consommer le \n restant

        switch (choice) {
        case 1 :
            printf("Ssh connect with no key.\n");
            ssh_connect();
        break;
        case 2 :
            printf("Ssh connect with key.\n");
        break;
        case 3 :
            printf("Back.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 3);
}