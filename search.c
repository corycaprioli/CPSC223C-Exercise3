#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int copyfile(char[], char*);
extern void output_integers(int[], int);

int main(int argc, char const *argv[]) {

  char * filename = (char *)malloc(4096 * sizeof(char));
  char * file_content = (char *)malloc(16384 * sizeof(char));
  char * key = (char *)malloc(4096 * sizeof(char));
  char * search;
  int * key_arr = (int *)malloc(4096 * sizeof(int));
  int size;
  int count;
  int key_size;

  printf("Welcome to Find Your Match produced by Orange Blossom Lucky Software, Inc.\n"); // greet the user
  printf("Project leader: Cory Caprioli\n");
  printf("This program will find the matching strings in any file.\n\n"); // tell the user what the program does

  printf("Please enter the name of the file to be searched: ");
  scanf("%s", filename); // get file name from the user
  printf("Thank you. You entered %s\n", filename); // repeat what was entered to the user
  size = copyfile(filename, file_content);

  printf("Please enter the search pattern you are seeking: ");
  scanf("%s", key); // get key from user
  printf("Thank you. You entered %s.\n\n", key); // repeat the key back to the user

  search = &file_content[0];
  key_size = strlen(key);
  int i = 0;
  while(strlen(search) < key_size) {
    search = strstr(search, key);
    key_arr[i] = (int)(search - file_content);
    search += key_size;
    i++;
  }

  count = sizeof(key_arr) / sizeof(key_arr[0]);
  printf("The search has completed. The search key %s is found in these positions within the file:\n", key); // tell the user all the positions where the key was found in the array
  output_integers(key_arr, count);  // print the locations of the key
  printf("That completes the string search. Please enjoy your matches.\n");
  printf("A zero will be returned to the operating system.\n");             // tell the user the program is done
  printf("Bye.\n");
  return 0;
}
