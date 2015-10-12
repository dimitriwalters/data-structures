#include "list.h"
#include "bst.h"
#include "graph.h"

int main() {  
  list my_list;
  my_list.push_front(7);
  my_list.push_front(4);
  my_list.push_front(11);
  my_list.print_list();

  bstree my_bst;
  my_bst.insert(7);
  my_bst.insert(4);
  my_bst.insert(11);
  my_bst.print_in_order();

  graph my_graph(3);
  my_graph.add_edge(0, 1);
  my_graph.add_edge(1, 2);
  my_graph.add_edge(0, 2);
  my_graph.print_graph();
}