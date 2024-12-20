#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void redirect_stderr(const char *error_path) {
    if (error_path) {
        FILE *file = freopen(error_path, "w", stderr);
        if (!file) {
            fprintf(stderr, "Error: Unable to redirect stderr to %s\n", error_path);
            exit(EXIT_FAILURE);
        }
    }
}
