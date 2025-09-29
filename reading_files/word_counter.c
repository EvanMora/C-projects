#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("How to use it [word_counter file_name word_to_count]");
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    int count = 0;
    char word[50];

    if (file == NULL) { 
        printf("Couldn't find the file '%s'", argv[1]);
        exit(1); 
    }

    char letter;
    for (int i = 0; (letter = fgetc(file)) != EOF; i++) {
        word[i] = letter;

        if (letter == ' ' || letter == '\n') {
            word[i] = '\0'; 
            printf("%s -> %s\n", word, argv[2]);

            if (strcmp(argv[2], word) == 0) { count++; }
            i = -1;
        }
    }

    fclose(file);
    printf("%d", count);
    return 0;
}