#include <stdio.h>

void print_help() {
    printf("Usage:\n");
    printf("  -u, --users        List users and their home directories\n");
    printf("  -p, --processes    List running processes\n");
    printf("  -h, --help         Show this help message\n");
    printf("  -l PATH, --log PATH Log output to specified file\n");
    printf("  -e PATH, --errors PATH Redirect errors to specified file\n");
}
