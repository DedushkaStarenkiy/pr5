#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void redirect_output(const char* log_path, const char* error_path) {
    if (log_path) {
        int log_fd = open(log_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (log_fd == -1) {
            perror("Failed to open log file");
            exit(1);
        }
        dup2(log_fd, STDOUT_FILENO);
        close(log_fd);
    }

    if (error_path) {
        int error_fd = open(error_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (error_fd == -1) {
            perror("Failed to open error file");
            exit(1);
        }
        dup2(error_fd, STDERR_FILENO);
        close(error_fd);
    }
}
