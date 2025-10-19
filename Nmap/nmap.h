#ifndef NMAP_H
#define NMAP_H

void nmap_menu(void);
void nmap_simple_scan(void);
void nmap_ip_scan(void);
void nmap_fast_scan(void);
void nmap_ssh_http_scan(void);
void nmap_all_port_scan(void);
void nmap_specifed_port_scan(void);
void nmap_s_option_scan(void);
void nmap_os_version_scan(void);
void nmap_speed_scan(void);
void nmap_save_scan(void);
void nmap_delay_scan(void);
void nmap_spoofing_scan(void);
void nmap_fragmentation_scan(void);
void nmap_custom_scan(void);

#endif