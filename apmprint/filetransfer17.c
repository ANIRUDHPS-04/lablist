
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File data successfully transferred from '%s' to '%s'.\n", argv[1], argv[2]);

    fclose(source);
    fclose(destination);

    return 0;
}

/*  OUTPUT



*/
