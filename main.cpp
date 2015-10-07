#include <cstdio>
#include "list.h"
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

  bstree my_bst;
  my_bst.insert(7);
  my_bst.insert(4);
  my_bst.insert(11);
  my_bst.print_in_order();
}
