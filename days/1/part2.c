#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char *num_chars[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// Scry next few chars of *str to check if it is a written word number
int isnumword(char *str) {
    for (int i = 0; i < 9; i++) {
        if (strncmp(str, num_chars[i], strlen(num_chars[i])) == 0)
            return i + 1;
    }
    return 0;
}

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
            bool is_num = false;
            int word_num = isnumword(buffer_line);
            if (isdigit(*buffer_line)) {
                buffer_num = *buffer_line - '0';
                is_num = true;
            } else if (word_num) {
                buffer_num = word_num;
                is_num = true;
            }
            if (is_num) {
                if (num1 == 99) {
                    num1 = buffer_num;
                } else {
                    num2 = buffer_num;
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

