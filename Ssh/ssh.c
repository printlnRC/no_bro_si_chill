#include <stdio.h>
#include <stdlib.h>

void ssh_connect(void) {
    char user[50];
    char ip[50];
    char command[150];

    printf("Enter username: ");
    scanf("%49s", user);

    printf("Enter IP address: ");
    scanf("%49s", ip);

    printf("Connecting to %s@%s\n", user, ip);

    snprintf(command, sizeof(command), "ssh -Y %s@%s", user, ip);

    system(command);
}
