#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include "log.h"

void handle_processes(const char *log_path) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    FILE *output = setup_log(log_path);

    if (!dir) {
        fprintf(stderr, "Error: Unable to open /proc directory\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            fprintf(output, "Process ID: %s\n", entry->d_name);
        }
    }

    closedir(dir);
    if (log_path) fclose(output);
}

