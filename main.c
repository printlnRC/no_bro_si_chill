#include "Menu/menu.h"
#include <stdio.h>
#include <windows.h>

int main(void) {
    int nb = 64;

    printf(
        " _______           __________                 .___         _________ .__    .__.__  .__   \n"
        " \\      \\   ____   \\______   \\_______  ____   |   | ______ \\_   ___ \\|  |__ |__|  | |  |  \n"
        " /   |   \\ /  _ \\   |    |  _/\\_  __ \\/  _ \\  |   |/  ___/ /    \\  \\/|  |  \\|  |  | |  |  \n"
        "/    |    (  <_> )  |    |   \\ |  | \\(  <_> ) |   |\\___ \\  \\     \\___|   Y  \\  |  |_|  |__\n"
        "\\____|__  /\\____/   |______  / |__|   \\____/  |___/____  >  \\______  /___|  /__|____/____/\n"
        "        \\/                 \\/                          \\/          \\/     \\/              \n"
    );

    do {
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
