#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>

void list_users() {
    struct passwd* pw;
    while ((pw = getpwent()) != NULL) {
        printf("User: %s, Home Directory: %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}
