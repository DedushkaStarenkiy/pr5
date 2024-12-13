#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "file_utils.h"

int main(int argc, char* argv[]) {
    char* log_path = NULL;
    char* error_path = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            redirect_output(log_path, error_path);
            list_users();
        }
        else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            redirect_output(log_path, error_path);
            list_processes();
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        }
        else if ((strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) && i + 1 < argc) {
            log_path = argv[++i];
        }
        else if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) && i + 1 < argc) {
            error_path = argv[++i];
        }
        else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    return 0;
}
