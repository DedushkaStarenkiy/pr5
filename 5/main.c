#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "errors.h"

void parse_arguments(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    parse_arguments(argc, argv);
    return 0;
}

void parse_arguments(int argc, char *argv[]) {
    char *log_path = NULL;
    char *error_path = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            handle_users(log_path);
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            handle_processes(log_path);
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            handle_help();
        } else if ((strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) && i + 1 < argc) {
            log_path = argv[++i];
        } else if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) && i + 1 < argc) {
            error_path = argv[++i];
            redirect_stderr(error_path);
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
        }
    }
}

