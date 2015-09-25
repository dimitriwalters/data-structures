#include <stdio.h>
#include "node.h"

int main() {
  struct node *list = list_create(5);
  list = list_insert_beginning(3, list);
  list = list_insert_beginning(8, list);
  list = list_remove_beginning(list);
  list = list_insert_beginning(1, list);
  list_print(list);
  struct node *list2 = list_find_node(3, list);
  list_print(list2);
  list_destroy(list);
}
