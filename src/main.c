#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "btree.h"

void print_tree (tree_node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->item);


  if (p->left)
    {
      print_tree (p->left, depth + 1);
    }

  if (p->right)
    print_tree (p->right, depth + 1);
}

// File for sandboxing and trying out code
int main(int argc, char **argv) {
  //test print
  node *ns = make_node(
        1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));
  print_list(ns);
  return 0;
}