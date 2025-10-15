#include <stdio.h>
#include <stdlib.h> 

void nmap_simple_scan(void) {
    char ip[50];
    char mask[6] = "/24"; // Masque de sous-réseau par défaut
    char command[100];

    printf("Enter IP address to scan: ");
    scanf("%49s", ip);
    printf("Enter mask (default is /24): ");
    scanf("%6s", mask);

    snprintf(command, sizeof(command), "nmap -sn %s%s", ip, mask);

    system(command);
}