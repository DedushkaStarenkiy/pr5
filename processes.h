#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

void list_processes() {
    DIR* dir = opendir("/proc");
    if (!dir) {
        perror("Unable to open /proc");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            printf("PID: %s\n", entry->d_name);
        }
    }
    closedir(dir);
}
