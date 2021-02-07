#include <stdio.h>
#include <stdlib.h>

// For stat()
// Run "man 2 stat" for detail
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../lib/shell_array.h"

long *Array_Load_From_File(char *filename, int *size) {
  struct stat st;      // Status structure of the file
  FILE *fp;            // FILE pointer
  int i;
  long *arr, n;

  if (stat(filename, &st)) {
    fprintf(stderr, "'%s': File does not exist \n", filename);
    return NULL;
  }

  if (!(fp = fopen(filename, "rb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return NULL;
  }

  *size = st.st_size / sizeof(long);

  arr = (long *)malloc(sizeof(long) * (*size));
  if (!arr) {
    fprintf(stderr, "Insufficent Memory: Cannot allocate memory \n");
    return NULL;
  }

  fread(arr, sizeof(long), *size, fp);

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

