#include <stdio.h>
#include <ctype.h>

int main(){

    FILE *ptr_file; ptr_file = fopen("input", "r");
    char buffer_read[50];
    int total_num = 0;
    int buffer_num;

    while (fgets(buffer_read, 50, ptr_file) != NULL) {
        char *buffer_line = buffer_read;
        int num1 = 99; // These are set to double digit numbers as placeholders
        int num2 = 99; // because we're only parsing for single digits
        for (char *buffer_line = buffer_read; *buffer_line; buffer_line++) {
            if (isdigit(*buffer_line)) {
                if (num1 == 99) {
                    // NOTE: (num) - '0' notation converts ASCII glyph of a 
                    // number into its integer equivalent
                    num1 = *buffer_line - '0';
                } else {
                    num2 = *buffer_line - '0';
                }
            }
        }

        // Used if only one number is found in the string
        if (num2 == 99) {
            num2 = num1;
        }

        // This acts the same as if we were putting the two numbers together
        int line_num = ((num1 * 10) + num2);

        total_num += line_num;

    }

    fclose(ptr_file);
    printf("total_num = %d\n", total_num);

}

