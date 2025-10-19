#include "nmap.h"

#include <stdio.h>
#include <stdlib.h> 

void nmap_menu(void) {
    int choice = 0;

    do {
       printf("=== NMAP Menu ===\n");

    printf("%-40s%-40s%-40s%-40s\n",
           "[1] Scan your network",
           "[2] Scan one ip",
           "[3] Fast scan",
           "[4] Scan ssh and http service");

    printf("%-40s%-40s%-40s%-40s\n",
           "[5] Scan all open port",
           "[6] Scan specified port",
           "[7] Scan with -s option",
           "[8] Scan OS version");

    printf("%-40s%-40s%-40s%-40s\n",
           "[9] Speed of scan",
           "[10] Save scan result to file",
           "[11] Scan with delay between packets",
           "[12] Scan with MAC spoofing");

    printf("%-40s%-40s%-40s\n",
           "[13] Scan with packet fragmentation",
           "[14] Custom scan",
           "[64] Back to Main Menu");

    printf("\nChoose an option: ");
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
        case 64 :
            printf("Back.\n");
            system("cls");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 3);
}