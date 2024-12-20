#include <stdio.h>

void handle_help() {
    printf("Usage:\n");
    printf("  -u, --users        List users and their home directories.\n");
    printf("  -p, --processes    List running processes.\n");
    printf("  -h, --help         Display this help message.\n");
    printf("  -l PATH, --log PATH   Log output to the specified file.\n");
    printf("  -e PATH, --errors PATH Redirect errors to the specified file.\n");
}
