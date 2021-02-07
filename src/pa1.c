#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/shell_array.h"
#include "lib/shell_list.h"

// Help Message
// Shows correct argument format
int help_msg() {
  fprintf(stderr, "Wrong argument format \n");
  fprintf(stderr, "./pa1 -a|-l $INPUT_FILE $OUTPUT_FILE \n");
  return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
  int size;            // Size of the array/list
  int i;               // Loop index
  long *arr;           // Pointer of the array
  char *option;        // Option argument (-a|-l)
  char *input_file;    // Input filename
  char *output_file;   // Output filename

  // Validate arguments
  if (argc != 4) return help_msg();
  if (strcmp(argv[1], "-a") && strcmp(argv[1], "-l")) return help_msg();

  // Bring arguments
  option = argv[1];
  input_file = argv[2];
  output_file = argv[3];
  
  // Handle array
  if (!strcmp(option, "-a")) {
    arr = Array_Load_From_File(input_file, &size);
    if (!arr) return EXIT_FAILURE;
  
    for (i = 0; i < size; printf("%ld\n", arr[i++]));

    //

    free(arr);
  }

  // Handle linked list
  if (!strcmp(option, "-l")) {
    // TODO: Apply 
  }

  return 0;
}

