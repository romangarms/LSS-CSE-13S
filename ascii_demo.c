#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
   printf("ascii value of 'a' is : %d\n", 'a');


   char * string = "here is a string";
   char * string2 = "i'm string 2";

   for (int i = 0; i < 30; i++){
      printf("%c", string[i]);
   }

   printf("\n");

   for (int j = 0; j < strlen(string); j++){
      printf("%c", string[j]);
   }
}

