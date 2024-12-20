#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include "log.h"

void handle_users(const char *log_path) {
    struct passwd *pw;
    FILE *output = setup_log(log_path);

    while ((pw = getpwent()) != NULL) {
        fprintf(output, "User: %s, Home Directory: %s\n", pw->pw_name, pw->pw_dir);
    }

    endpwent();
    if (log_path) fclose(output);
}
