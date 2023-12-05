#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isInteger(char ch) {
   if (isdigit((unsigned char)ch) || ch == '-') {
      return true;
   }
   return false;
}

int skipInteger(char** arr, int row, int col, int cols) {
   int k = col;
   while (isInteger(arr[row][k+1])) {
      k++;
   }
   return k;
}

void replaceWithOnes(char** arr, int row, int col, int rows, int cols) {
   for(int i = row-1; i <= row+1; i++) {
      for(int j = col-1; j <= col+1; j++) {
         if(i >= 0 && i < rows && j >= 0 && j < cols) {
            arr[i][j] = '1';
         }
      }
   }
}

int main() {
   FILE* inputFile = fopen("input", "r");
   if(inputFile == NULL) {
      printf("Failed to open the input file.\n");
      return 1;
   }

   // Count the number of rows and columns in the input file
   int rows = 0, cols = 0;
   char c;
   while((c = fgetc(inputFile)) != EOF) {
      if (c == '\n') {
         rows++;
      }
      else if (rows == 0) {
         cols++;
      }
   }
   rows++; // Increment rows to account for the last line

   // Dynamically allocate memory for the input and new arrays
   char** input = (char**) malloc(rows * sizeof(char*));
   char** newArray = (char**) malloc(rows * sizeof(char*));
   for(int i = 0; i < rows; i++) {
      input[i] = (char*) malloc(cols * sizeof(char));
      newArray[i] = (char*) malloc(cols * sizeof(char));
   }

   // Reset the file pointer to the beginning of the file
   fseek(inputFile, 0, SEEK_SET);

   // Read the input file and store it in the input array
   for(int i = 0; i < rows; i++) {
      fgets(input[i], cols+1, inputFile); // +1 is to account for the null terminator
   }

   // Initialize the new array with zeroes
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         newArray[i][j] = '0';
      }
   }

   // Replace zeroes with ones around symbols
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         if((input[i][j] != '.') && (input[i][j] != ' ') && (input[i][j] != 0) && (input[i][j] != '\n')) {
            if (!isInteger((unsigned char)input[i][j])) {
               printf("Found symbol! %c\n", input[i][j]);
               printf("Found symbol! %d\n", input[i][j]);
               j = skipInteger(input, i, j, cols);
               replaceWithOnes(newArray, i, j, rows, cols);
               newArray[i][j] = input[i][j];
            }
         }
      }
   }

   // Print the new array
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         printf("%c ", newArray[i][j]);
      }
      printf("\n");
   }

   // Free the dynamically allocated memory
   for(int i = 0; i < rows; i++) {
      free(input[i]);
      free(newArray[i]);
   }
   free(input);
   free(newArray);

   // Close the input file
   fclose(inputFile);

   return 0;
}
