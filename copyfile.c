#include <string.h>
#include <stdio.h>

int copyfile(char*, char*);

int copyfile(char * filename, char * search_string) {

  FILE * file_ptr = fopen(filename, "r"); // create a file pointer and open the file to be read from

  if(!file_ptr) {
    return 0;  //return 0 if the file does not exist
  }

  char c = fgetc(file_ptr); //fget the first char of the file
  if (c == EOF) {
    return 0;  //return 0 if the first char is EOF
  } else {
    ungetc(c, file_ptr); // if the first char is not EOF put the char back
  } // checks if file is empty

  int i = 0;
  int onebyte;

  while ((onebyte = fgetc(file_ptr)) != EOF) { // read byte by byte until the end of file is reached
    search_string[i] = onebyte; // input each byte into the array
    i++; // increment to next array location
  }

  fclose(file_ptr);

  int size = strlen(search_string); //get the size of the string_search array
  return size;
}
