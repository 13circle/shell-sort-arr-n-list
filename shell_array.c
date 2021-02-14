#include <stdio.h>
#include <stdlib.h>

// For stat()
// Run "man 2 stat" for detail
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shell_array.h"


/**
 *  Read long type integers from an input file to the array
 *
 *  Parameters:
 *  - char *filename: Input filename
 *  - int *size: Size of the array (from main function)
 *
 *  Return Value (long *):
 *  - Array of long integers from an input file
 *
 **/
long *Array_Load_From_File(char *filename, int *size) {
  struct stat st;  // Status structure of the file
  FILE *fp;        // FILE pointer
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

  // Read long type integers from the file
  if(fread(arr, sizeof(long), *size, fp) != *size) {
    fprintf(stderr, "'%s': Unable to read integers from this file \n", filename);
    return NULL;
  }

  // Close the file & return the array
  fclose(fp);
  return arr;
}


/**
 *  Write long type integer values from the array to an output file
 *
 *  Parameters:
 *  - char *filename: Output filename
 *  - long *array: Array of long integers (i.e. sorted array)
 *
 *  Return Value (int):
 *  - Count of successfully written integers
 *
 **/
int Array_Save_To_File(char *filename, long *array, int size) {
  FILE *fp;         // File pointer
  int cnt_output;   // Count of successfully written integers
  int i;            // Loop index

  // Open file as write mode for a binary file & handle exception
  if (!(fp = fopen(filename, "wb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return 0;
  }

  // Write long type integers to the file & count successfully written integers
  for (i = cnt_output = 0; i < size; i++, cnt_output++) {
    if(fwrite(array + i, sizeof(long), 1, fp) != 1) {
      cnt_output--;
    }
  }

  // Close the file & return the count of successfully written integers
  fclose(fp);
  return cnt_output;
}


/**
 *  Shell-Sort the given array
 *
 *  Parameters:
 *  - long *array: The given array
 *  - int size: Size of the array
 *  - long *n_comp: Number of comparison
 *
 **/
void Array_Shellsort(long *array, int size, long *n_comp) {
  int k;     // Loop index of Knuth's Sequence
  int j;     // Outer loop index for Shell Sort
  int i;     // Inner loop index for Shell Sort
  long tmp;  // Temporary variable for Shell Sort

  // Knuth's Sequence
  for (k = 1; k < size; k = k * 3 + 1);

  // Shell Sort & count comparisons
  for (*n_comp = 0; k > 0; k /= 3) {
    for (j = k; j < size; j++) {
      tmp = array[j];
      for (i = j, (*n_comp)++; i >= k && array[i - k] > tmp; i -= k) {
        array[i] = array[i - k];
        (*n_comp)++;
      }
      array[i] = tmp;
    }
  }
}

