#include <stdio.h>

void output_integers(int[], int);

void output_integers(int match_location[], int count) {
  for(int i = 0; i < count; i++) {
    printf("%d\n", match_location[i]);
  }
}
