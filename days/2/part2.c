#include <stdio.h>
#include <ctype.h>

int main() {

    FILE *ptr_file; ptr_file = fopen("input", "r");
    char buffer_read[1000];

    int num;
    int answer_num = 0;

    while (fgets(buffer_read, 1000, ptr_file) != NULL) {
        int num_rnd = 0, num_red = 0, num_grn = 0, num_blu = 0;
        for (char *buffer_line = buffer_read; *buffer_line; buffer_line++) {
            if (isdigit(*buffer_line)) {
                sscanf(buffer_line, "%d", &num);

                if (num_rnd == 0) {
                    num_rnd = num;
                }

                while (isdigit(*buffer_line)) buffer_line++;    // Skip rest of number
                buffer_line ++;                                 // Skip space
                
                // Check color following number
                // Only update if larger than previous stored number
                if (*buffer_line == 'r') {
                    if (num > num_red) num_red = num;
                } else if (*buffer_line == 'g') {
                    if (num > num_grn) num_grn = num;
                } else if (*buffer_line == 'b') {
                    if (num > num_blu) num_blu = num;
                }

            }
        }

        answer_num += (num_red * num_grn * num_blu);

    }

    fclose(ptr_file);
    printf("answer_num: %d\n", answer_num);

}
