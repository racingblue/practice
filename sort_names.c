#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_names(char (*names)[20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[20];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the size: ");
    scanf("%d", &n);

    char (*names)[20] = malloc(n * sizeof(*names));
    if (names == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the %d names of length max 20 characters in each:\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d] -> ", i);
        scanf("%s", names[i]);
    }

    sort_names(names, n);

    printf("\nThe sorted names are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    free(names);
    return 0;
}

