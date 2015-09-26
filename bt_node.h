#ifndef BT_NODE_H_
#define BT_NODE_H_

struct bt_node {
  int item;
  struct bt_node *left;
  struct bt_node *right;
};

#endif // BT_NODE_H_