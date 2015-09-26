#ifndef BST_H_
#define BST_H_

#include "bt_node.h"

struct bt_node *bst_create(int item);

struct bt_node *bst_insert(int item, struct bt_node *node);

struct bt_node *bst_find(int item, struct bt_node *node);

void bst_print_in_order(struct bt_node *node);

void bst_destroy(struct bt_node *node);

#endif // BST_H_