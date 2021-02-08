#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/shell_array.h"
#include "lib/shell_list.h"

/**
 *  Help Message
 *  (Shows correct arugment format)
 *
 **/
int help_msg() {
  fprintf(stderr, "Wrong argument format \n");
  fprintf(stderr, "./pa1 -a|-l $INPUT_FILE $OUTPUT_FILE \n");
  return EXIT_FAILURE;
}


/**
 *  Entry Function (main)
 *
 *  Parameters:
 *  - int argc: Count of arugments passed by user (including a name of the execution file)
 *  - char *argv[]: Arguments passed by user (including a name of the execution file)
 *
 *  Return Value (int):
 *  - Flag to notify an end status of the program to OS
 *
 **/
int main(int argc, char *argv[]) {
  int size;            // Size of the array/list
  int cnt_output;      // Number of integers successfully written in an output file
  long *arr;           // Pointer of the array
  long n_comp;         // Number of comparison

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

    Array_Shellsort(arr, size, &n_comp);

    if ((cnt_output = Array_Save_To_File(output_file, arr, size)) < size) {
      fprintf(stderr, "'%s': Only %d integer(s) written \n", output_file, cnt_output);
      return EXIT_FAILURE;
    }

    printf("%ld\n", n_comp);

    free(arr);
  }

  // Handle linked list
  if (!strcmp(option, "-l")) {
    // TODO: Use helper functions in shell_list.c
  }

  return 0;
}

