#include <stdio.h>
#include <stdlib.h>

#include "../lib/list_of_list.h"

/**
 *  Read long type integers from an input file to the list
 *
 *  Parameters:
 *  - char *filename: Input filename
 *
 *  Return Value (Node *):
 *  - Head of the list of long integers from an input file
 *
 **/
Node *List_Load_From_File(char *filename) {
  FILE *fp;    // FILE pointer
  long value;  // Temporary integer
  Node *head;  // Head of the list
  Node *tail;  // Tail of the list
  Node *tmp;   // Temporary Node

  // Open file as read mode for a binary file & handle exception
  if (!(fp = fopen(filename, "rb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return NULL;
  }
 
  // Read long type integers from the file
  for (head = NULL; fread(&value, sizeof(long), 1, fp) == 1; tail = tmp) {

    // Create new Node & assign the value
    tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;

    // Connect new Node to the list
    if (head) tail->next = tmp;
    else head = tmp;
  }

  // Close the file & return the list
  fclose(fp);
  return head;
}


/**
 *  Write long type integer values from the list to an output file
 *
 *  Parameters:
 *  - char *filename: Output filename
 *  - Node *list: List of long integers (i.e. sorted list)
 *
 *  Return Value (int):
 *  - Count of successfully written integers
 *
 **/
int List_Save_To_File(char *filename, Node *list) {
  FILE *fp;         // File pointer
  int cnt_output;   // Count of successfully written integers
  Node *tmp;        // Temporary pointer for the list

  // Open file as write mode for a binary file & handle exception
  if (!(fp = fopen(filename, "wb"))) {
    fprintf(stderr, "'%s': Cannot read this file \n", filename);
    return 0;
  }

  // Write long type integers to the file & count successfully written integers
  for (tmp = list; tmp; tmp = tmp->next, cnt_output++) {
    if (fwrite(&(tmp->value), sizeof(long), 1, fp) != 1) {
      cnt_output--;
    }
  }

  // Close the file & return the count of successfully written integers
  fclose(fp);
  return cnt_output;
}


/**
 *  Shell-Sort the given list
 *
 *  Parameters:
 *  - Node *list: The given list
 *  - long *n_comp: Number of comparison
 *
 *  Return Value (Node *):
 *  - Head of the sorted list
 *
 **/
Node *List_Shellsort(Node *list, long *n_comp) {
  // TODO: Shell Sort linked list
  // 1. Evaluate the size of the list
  // 2. Evaluate Knuth's Sequence
  *n_comp = 0;
  return list;
}

