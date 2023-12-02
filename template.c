// Used for to cover boilerplate for filereading and output

#include <stdio.h>

int main() {

    FILE *ptr_file; ptr_file = fopen("input", "r");
    char buffer_read[50];

    while (fgets(buffer_read, 50, ptr_file) != NULL) {
        printf("%s\n", buffer_read);
    }

    fclose(ptr_file);

}
