#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct AdminCredentials {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void saveCredentials(const char *filename, const struct AdminCredentials *admin) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    dprintf(fd, "%s\n%s\n", admin->username, admin->password);
    close(fd);
}

int validateCredentials(const char *filename, const struct AdminCredentials *admin) {
    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int bytesRead = scanf(fd, "%49s%49s", storedUsername, storedPassword);
    close(fd);

    if (bytesRead == 2) {
        if (strcmp(storedUsername, admin->username) == 0 &&
            strcmp(storedPassword, admin->password) == 0) {
            return 1; // Credentials are valid
        }
    }

    return 0; // Credentials are invalid
}

int main() {
    struct AdminCredentials admin;

    printf("Enter admin username: ");
    scanf("%49s", admin.username);

    printf("Enter admin password: ");
    scanf("%49s", admin.password);

    // Save admin credentials to a file
    saveCredentials("admin_credentials.txt", &admin);
    printf("Admin credentials saved.\n");

    // Now, let's validate the credentials
    printf("Enter admin username for validation: ");
    scanf("%49s", admin.username);

    printf("Enter admin password for validation: ");
    scanf("%49s", admin.password);

    if (validateCredentials("admin_credentials.txt", &admin)) {
        printf("Authentication successful. You are the admin.\n");
        // Perform admin tasks here
    } else {
        printf("Authentication failed. You are not the admin.\n");
    }

    return 0;
}

