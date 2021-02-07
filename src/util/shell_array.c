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
  unsigned char *num;  // 
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

  num = (unsigned char *)malloc(sizeof(unsigned char) * (sizeof(long) + 1));
  if (!num) {
    fprintf(stderr, "Insufficent Memory: Cannot allocate memory \n");
    return NULL;
  }

  for (i = 0; fread(num, sizeof(long), 1, fp) == 1; i++) {
    arr[i] = atoi(num);
  }

  free(num);
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

