#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nmap_simple_scan(void) {
    char ip[50];
    char mask[6] = "/24"; // Masque de sous-réseau par défaut
    char command[100];

    printf("Enter IP address to scan the network: ");
    scanf("%49s", ip);
    printf("Enter mask (default is /24): ");
    scanf("%6s", mask);

    snprintf(command, sizeof(command), "nmap -sn %s%s", ip, mask);

    system(command);
}

void nmap_ip_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to scan : ");
    scanf("%49s", ip);

    snprintf(command, sizeof(command), "nmap %s", ip);

    system(command);
}

void nmap_fast_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to fast scan : ");
    scanf("%49s", ip);
;

    snprintf(command, sizeof(command), "nmap -F %s", ip);

    system(command);
}

void nmap_ssh_http_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to scan ssh and http service : ");
    scanf("%49s", ip);

    snprintf(command, sizeof(command), "nmap -p 22,80 %s", ip);

    system(command);
}

void nmap_all_port_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to scan all open port : ");
    scanf("%49s", ip);

    snprintf(command, sizeof(command), "nmap -p- %s", ip);

    system(command);
}

void nmap_specifed_port_scan(void) {
    char ip[50];
    char ports[50];
    char command[100];

    printf("Enter IP address to scan specified port : ");
    scanf("%49s", ip);
    printf("Enter ports to scan exexple format 22,80,443, ... : ");
    scanf("%49s", ports);

    snprintf(command, sizeof(command), "nmap -p %s %s", ip, ports);

    system(command);
}

void nmap_s_option_scan(void) {
    char ip[50];
    char option[2];
    char command[100];

    printf("option avec -s : ");
    printf("S : Scan furtif without completed connection(default)\n");
    printf("V : Scan for collect version service work on port\n");
    printf("T : Scan for TCP Connect\n");
    printf("U : Scan for UDP ports ( DNS, DHCP, ... )\n");
    printf("Enter IP address to scan service : ");
    scanf("%49s", ip);
    printf("Enter option to scan (S, V, T, U) : ");
    scanf("%1s", option);

    snprintf(command, sizeof(command), "nmap -s%s %s", ip, option);

    system(command);
}

void nmap_os_version_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to scan os version : ");
    scanf("%49s", ip);

    snprintf(command, sizeof(command), "nmap -O %s", ip);

    system(command);
}

void nmap_speed_scan(void) {
    char ip[50];
    char speed[2];
    char command[100];

    printf("Speed of scan : \n");
    printf("0 : Paranoid\n");
    printf("1 : Sneaky\n");
    printf("2 : Polite\n");
    printf("3 : Normal (default)\n");
    printf("4 : Aggressive\n");
    printf("5 : Insane\n");
    printf("Enter IP address to scan speed : ");
    scanf("%49s", ip);
    printf("Enter speed to scan (0, 1, 2, 3, 4, 5) : ");
    scanf("%1s", speed);

    snprintf(command, sizeof(command), "nmap -T%s %s", speed, ip);

    system(command);
}

void nmap_save_scan(void) {
    char ip[50];
    char filename[50];
    char command[150];

    printf("Enter IP address to scan and save results : ");
    scanf("%49s", ip);
    printf("Enter filename to save results (without extension) : ");
    scanf("%49s", filename);

    snprintf(command, sizeof(command), "nmap -oN %s.txt %s", filename, ip);

    system(command);
}

void nmap_delay_scan(void) {
    char ip[50];
    char delay[4];
    char command[100];

    printf("Enter IP address to scan with delay : ");
    scanf("%49s", ip);
    printf("Enter delay in milliseconds between packets (e.g., 1000 for 1 second): ");
    scanf("%3s", delay);

    snprintf(command, sizeof(command), "nmap --scan-delay %sms %s", delay, ip);

    system(command);
}

void nmap_spoofing_scan(void) {
    char ip[50];
    char mac[18];
    char command[150];

    printf("Enter IP address to scan with MAC spoofing : ");
    scanf("%49s", ip);
    printf("Enter MAC address to spoof (e.g., 00:11:22:33:44:55): ");
    scanf("%17s", mac);

    snprintf(command, sizeof(command), "nmap --spoof-mac %s %s", mac, ip);

    system(command);
}

void nmap_fragmentation_scan(void) {
    char ip[50];
    char command[100];

    printf("Enter IP address to scan with packet fragmentation : ");
    scanf("%49s", ip);

    snprintf(command, sizeof(command), "nmap -f %s", ip);

    system(command);
}

void nmap_custom_scan(void) {
    char args[256];
    char command[320];

    printf("Entrez vos options nmap (ex: -sS -p 22,80 192.168.1.0/24) :\n> ");
    if (fgets(args, sizeof(args), stdin) == NULL) {
        printf("Lecture annulée.\n");
        return;
    }

    /* supprimer le '\n' final si présent */
    size_t len = strlen(args);
    if (len > 0 && args[len - 1] == '\n') {
        args[len - 1] = '\0';
    }

    if (args[0] == '\0') {
        printf("Aucune option fournie.\n");
        return;
    }

    /* Construire la commande en limitant la taille pour éviter overflow */
    if (snprintf(command, sizeof(command), "nmap %s", args) >= (int)sizeof(command)) {
        printf("Commande trop longue.\n");
        return;
    }

    printf("Exécution : %s\n", command);
    system(command);
}
