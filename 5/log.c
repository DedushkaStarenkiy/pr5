#include <stdio.h>
#include <stdlib.h>
#include "log.h"

FILE *setup_log(const char *log_path) {
    if (log_path) {
        FILE *file = fopen(log_path, "w");
        if (!file) {
            fprintf(stderr, "Error: Unable to open log file %s\n", log_path);
            exit(EXIT_FAILURE);
        }
        return file;
    }
    return stdout;
}
