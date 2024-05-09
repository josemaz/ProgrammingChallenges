#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCOLS 13
#define MAXROWS 4
#define MAXCHAR 1024

void mayus(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int find_index(char c, int matrix[][MAXCOLS], int *row) {
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            if (matrix[i][j] == c) {
                *row = i; // Set the row index
                return j; // Retorna la posición del carácter
            }
        }
    }
    return -1; // Si no se encuentra el carácter
}

int main() {
    int matrix[MAXROWS][MAXCOLS] = {
        {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
        {'Q','W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
        {'A','S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
        {'Z','X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}
    };

    char e[MAXCHAR];

    
    while (fgets(e, sizeof(e), stdin) && strlen(e) > 1) {
        int len = strlen(e);
        if (e[len - 1] == '\n') {
            e[len - 1] = '\0';
            len--;
        }

        mayus(e);

        if (strchr(e, 'A') != NULL || strchr(e, 'Q') != NULL || strchr(e, 'Z') != NULL || strchr(e, '\'') != NULL) {
            printf("Invalid character(s) detected. Exiting...\n");
            exit(1); // Sale del programa con un estado no cero
        }

        for (int i = 0; i < len; i++) {
            int row;
            int pos = find_index(e[i], matrix, &row);
            char cout;
            if (pos != -1 && pos > 0) {
                cout = matrix[row][pos - 1];  // Reemplazar con el carácter a la izquierda
                printf("%c", cout);
            } else {
                printf("%c", e[i]); // Si no se encuentra, imprimir el carácter como está
            }
        }
        printf("\n");
    }

    return 0;
}
