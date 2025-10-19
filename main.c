#include "Menu/menu.h"
#include "Display/display.h"
#include <stdio.h>
#include <windows.h>

int main(void) {
    int nb = 64;

    do {
        print_logo();
        displayMenu();
        scanf("%d", &nb);
        printf("%d\n", nb);
        getUserSelectionForAllMenu(nb);
        if (nb != 1) {
            printf("\nPress ENTER to return to the menu...");
            getchar(); // Pour consommer le '\n'
            getchar(); // Attendre que l'utilisateur appuie sur Entrée
            system("cls"); // Efface avant de revenir au menu
        }
    } while (nb != 64);

    printf("Exiting program...\n");
    return 0;
}
