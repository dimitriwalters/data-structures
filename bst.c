#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct bt_node *bst_create(int item) {
  struct bt_node *node = malloc(sizeof(struct bt_node));
  node->item = item;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct bt_node *bst_insert(int item, struct bt_node *node) {
  if (node == NULL) {
    node = malloc(sizeof(struct bt_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
  } else if (item < node->item) {
    node->left = bst_insert(item, node->left);
  } else if (item > node->item) {
    node->right = bst_insert(item, node->right);
  }
  return node;
}

void bst_print_in_order(struct bt_node *node) {
  if (node == NULL) {
    return;
  } else {
    bst_print_in_order(node->left);
    printf("%d\n", node->item);
    bst_print_in_order(node->right);
  }
}

void bst_destroy(struct bt_node *node) {
  if (node == NULL) {
    return;
  } else {
    bst_destroy(node->left);
    bst_destroy(node->right);
    free(node);
  }
}