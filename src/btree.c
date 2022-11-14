#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  /* Because the only rule we need to follow when inserting is smaller elements to the left 
   * and larger elements to the right there will always be space for an element as a child
   * to one of the elements at the bottom of the tree.
  */

  //This means we hit a leaf to a node this is a valid space to put the element.
  if(t == NULL){
    //Create node and fill out
    struct tree_node *temp = malloc(sizeof(struct tree_node));
    temp->item = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  //Find a space for the element. If the element already exist I place it to the left of the element.
  if(x <= t->item){
    //Recursively look at the subtree to the left.
    t->left = Insert(x, t->left);
    return t;
  }
  if(x > t->item){
    //Recursively look at the subtree to the left.
    t-> right = Insert(x, t->right);
    return t;
  }
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  /* Works by finding the element to be removed by calling recursively on the left or right
   * sub-tree. Once the element to be removed has been found find the left most node in the right
   * sub-tree as this node needs to take the space of the removed element.
   * If not right sub-tree exists the root node of the left sub-tree the element that should take
   * the place.
  */

  //Check that the element actually exists to be removed.
  if(!Contains(x, t)) return t;
  //Once the element has been found.
  if(x == t->item){
    //If the right sub-tree doesn't exist set the left sub-tree in place of the removed element.
    if(t->right == NULL){
      t = t->left;
      return t;
    }
    //The right sub-tree exists. Find the left most node of this tree.
    t = t->right;
    while(t != NULL){
      t = t->left;
    }
  return t;
  }
  //The element to be removed hasn't been found yet. Look to the left or the right based on the
  //value of the current root until it has been found.
  if(t->item != x){
    if(x < t->item){
      t->left = Remove(x, t->left);
    }else
      t->right = Remove(x, t->right);
  }
  return t;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  //Base case 1: The tree has been exhausted and the element doesn't exist.
  if(t == NULL) return false;
  //Base case 2: The tree contains the element and it has been found.
  if(t->item == x) return true;
  //The element has not been found yet. Call left or right sub-tree based on the value of the current
  //root to find the element.
  if(x < t->item){
    return Contains(x, t->left);
  } else 
  return Contains(x, t->right);
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  //Empty tree is NULL. 
  //Creation of the root nodes is handled in insert when the root has a value to give.
  t = NULL;
  return t;
}

int Empty(struct tree_node *t) {
  //The tree is empty if the root is NULL.
  return t == NULL;
}

int Full(struct tree_node *t) {
  // Test if full
  //Doesn't make sense?
  return 1;
}
