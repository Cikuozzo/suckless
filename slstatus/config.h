/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

// static const Block blocks[] = {
//    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
//    {"^d^ ^b#d65d0e^^c#1d2021^  ^b#fe8019^ ", "xbps-install -unM | wc -l",                                     21600,   10},
//    {"^d^ ^b#b16286^^c#1d2021^  ^b#d3869b^ ", "block-keymap ",                                                 0,       12},
//    {"^d^ ^b#98971a^^c#1d2021^  ^b#b8bb26^ ", "block-cpu perc",                                                5,       0},
//    {"^d^ ^b#458588^^c#1d2021^  ^b#83a598^ ", "block-temperature /sys/class/thermal/thermal_zone0/temp",       5,       0},
//    {"^d^ ^b#689d6a^^c#1d2021^  ^b#8ec07c^ ", "block-ram used",                                                10,      0},
//    {"^d^ ^b#d79921^^c#1d2021^  ^b#fabd2f^ ", "block-battery perc BAT0",                                       60,      0},
//   {"^d^ ^b#cc241d^^c#1d2021^  ^b#fb4934^ ", "block-datetime \"%H:%M\"",                                      60,      0},
//    {"^d^ ", "",                                        0,       0},

//};


/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
	//{ datetime, "%s",           "%F %T" },
	//{ wifi_perc, "W: (%3s%% on ", "wlp8s0" },
        //{ netspeed_rx, "%sB/s  ", "enp0s3" },
	{ run_command,"^c#1d2021^ ^b#83a598^" "[VOL: %4s]", "amixer sget Master | awk -F\"[][]\" '/%/ { print $2 }' | head -n1" },
	{ cpu_perc, "^c#1d2021^ ^b#b8bb26^" "[CPU: %s%%]", NULL },
	{ ram_perc, "^c#1d2021^ ^b#d79921^" "[RAM:%s%]", NULL },
	{ datetime, "^c#1d2021^ ^b#fb4934^" "[%s]",           "%r" },
};
