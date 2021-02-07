#include <stdio.h>
#include <stdlib.h>

// For stat()
// Run "man 2 stat" for detail
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../lib/shell_array.h"

long *Array_Load_From_File(char *filename, int *size) {
  struct stat st;  // Status structure of the file
  FILE *fp;        // FILE pointer
  int i;           // Loop index
  long *arr;       // Input array

  // Get file info using stat structure & handle exception
  // (stat() returns nonzero value on error)
  if (stat(filename, &st)) {
    fprintf(stderr, "'%s': File does not exist \n", filename);
    return NULL;
  }

  // Open file as read mode for a binary file & handle exception
  if (!(fp = fopen(filename, "rb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return NULL;
  }

  // Calculate the size of the array
  *size = st.st_size / sizeof(long);

  // Allocate memory for the array & handle exception
  arr = (long *)malloc(sizeof(long) * (*size));
  if (!arr) {
    fprintf(stderr, "Insufficent Memory: Cannot allocate memory \n");
    return NULL;
  }

  // Read long-type integers from the file
  fread(arr, sizeof(long), *size, fp);

  // Close the input file & return the array
  fclose(fp);
  return arr;
}

int Array_Save_To_File(char *filename, long *array, int size) {
  FILE *fp;
  int cnt_output = 0;
  int i;

  if (!(fp = fopen(filename, "wb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return 0;
  }

  for (i = 0; i < size; i++) {
    //
  }

  return cnt_output;
}

void Array_Shellsort(long *array, int size, long *n_comp) {
  //
}

