#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char sourceFile[100], destFile[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%s", destFile);

    src = fopen(sourceFile, "r");
    if (src == NULL) {
        printf("Cannot open source file %s\n", sourceFile);
        exit(1);
    }

    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Cannot open destination file %s\n", destFile);
        fclose(src);
        exit(1);
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully!\n");

    fclose(src);
    fclose(dest);
    return 0;
}
