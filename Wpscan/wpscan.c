#include <stdio.h>
#include <stdlib.h>


void wpscan_scan(void) {
    char url[100];
    char command[200];

    printf("Enter the WordPress site URL (e.g., http://example.com): ");
    scanf("%99s", url);

    printf("Scanning WordPress site at %s...\n", url);

    snprintf(command, sizeof(command), "wpscan --url %s --enumerate u", url);

    system(command);
}