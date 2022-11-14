#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this

  //Prints the head. Then call the function with the next element as the head until P is empty(NULL)
  if(p != NULL){
    printf("%d ", p->value);
    print_list(p->next);
  }
  printf("\n");
} 

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  
  //Base case the list has been exhausted return 0.
  if(p == NULL){
    return 0;
  }
  //Square p and add it to the next value of p squared until p is NULL.
  return square(p->value) + sum_squares(p->next);
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3

  //Base case
  if(p == NULL){
    return NULL;
  }
  //Create a new node to hold the summed squares to far and replace it as the current node.
  //Call recursively on the next node.
  node *temp= malloc(sizeof(node));
  temp->value = f(p->value);
  temp->next = map(p->next, f);
  return temp;
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
