#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Process (FILE *IN, char *str, FILE *OUT) {
    while (fgets(str, 8196, IN) != NULL) {
        if (strncmp(str, "\n", 1) != 0 ) { //Сравниваем 2 строки, если пустая, то удаляем
            fprintf(OUT, "%s", str);
        }
    }
}


int main(void) {
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");
    char str[8196];

    if (IN == NULL) {
        printf("File not opened!\n");
        return -1;
    }

    if (OUT == NULL) {
        printf("File not opened!\n");
        fclose(IN);
        return -2;
    }

    Process (IN, str, OUT);

    return 0;

    }
