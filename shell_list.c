#include <stdio.h>
#include <stdlib.h>

#include "list_of_list.h"

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

    // Connect new Node to the list
    if (head) tail->next = tmp;
    else head = tmp;
  }

  // Assign NULL at the tail to notify the end of the list
  tmp->next = NULL;

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

Node *get_pos(Node *list, int pos) {
  Node *node;
  int i;
  for (node = list, i = 0; i < pos; node = node->next, i++);
  return node;
}

Node *swap_node(Node *list, int pos1, int pos2) {
  Node *prev1;
  Node *prev2;
  Node *node1;
  Node *node2;
  Node *tmp;
  int i;

  if (!list) return NULL;

  if (pos1 == pos2) return list;

  for (node1 = list, i = 0; i < pos1; i++) {
    prev1 = node1;
    node1 = node1->next;
  }

  for (node2 = list, i = 0; i < pos2; i++) {
    prev2 = node2;
    node2 = node2->next;
  }

  if (node1 && node2) {
    if (prev1) prev1->next = node2;
    else list = node2;
    if (prev2) prev2->next = node1;
    else list = node1;
  }

  tmp = node1->next;
  node1->next = node2->next;
  node2->next = tmp;

  return list;
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
  int k;
  int j;
  int i;
  int t;
  int size;
  Node *tmp1, *tmp2;

  for (size = 0, tmp1 = list; tmp1; size++, tmp1 = tmp1->next);
  
  for (k = 1; k < size; k = k * 3 + 1);

  for (*n_comp = 0; k > 0; k /= 3) {
    for (j = k; j < size; j++) {
      tmp1 = get_pos(list, j);
      t = j;
      for (i = j; i >= k; i -= k) {
        tmp2 = get_pos(list, i - k);
        (*n_comp)++;
        if (tmp2->value <= tmp1->value) break;
        list = swap_node(list, i - k, i);
      }
      list = swap_node(list, i, t);
    }
  }

  return list;
}

