#ifndef BST_H_
#define BST_H_

struct node;

class bstree {
public:
  bstree();
  ~bstree();

  void insert(int key);
  void print_in_order();
  void destroy_tree();

private:
  void insert(int key, node *leaf);
  void print_in_order(node *leaf);
  void destroy_tree(node *leaf);

  node *root;
};

#endif // BST_H_