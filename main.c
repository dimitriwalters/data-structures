#include <stdio.h>
#include "node.h"
#include "bst.h"

int main() {
  struct node *list = list_create(5);
  list = list_insert_beginning(3, list);
  list = list_insert_beginning(8, list);
  list = list_remove_beginning(list);
  list = list_insert_beginning(1, list);
  printf("linked list: ");
  list_print(list);
  struct node *list2 = list_find_node(3, list);
  printf("linked list: ");
  list_print(list2);
  list_destroy(list);

  struct bt_node *bst = bst_create(5);
  bst = bst_insert(7, bst);
  bst = bst_insert(9, bst);
  printf("bst:\n");
  bst_print_in_order(bst);
  struct bt_node *bst2 = bst_find(7, bst);
  printf("bst:\n");
  bst_print_in_order(bst2);
  struct bt_node *min_node = bst_find_min(bst);
  printf("min: %d\n", min_node->item);
  struct bt_node *max_node = bst_find_max(bst);
  printf("max: %d\n", max_node->item);
  bst_destroy(bst);
}
