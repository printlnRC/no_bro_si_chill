#include <stdio.h>
#include <stdlib.h>

void ssh_connect(void);

void ssh_connect(void) {
    char user[50];
    char ip[50];

    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Connecting to %s@%s\n", user, ip);
    const char *command = "ssh -Y %s@%s";
    system(command);
}