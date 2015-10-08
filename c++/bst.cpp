#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "bst.h"

using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
};

bstree::bstree() {
  root = NULL;
}

bstree::~bstree() {
  destroy_tree();
}

void bstree::insert(int key) {
  if (root != NULL) {
    insert(key, root);
  } else {
    root = new node;
    root->key = key;
    root->left = NULL;
    root->right = NULL;
  }
  insert(key, root);
}

void bstree::print_in_order() {
  print_in_order(root);
}

void bstree::destroy_tree() {
  destroy_tree(root);
}

void bstree::insert(int key, node *leaf) {
  if (key < leaf->key) {
    if (leaf->left != NULL) {
      insert(key, leaf->left);
    } else {
      leaf->left = new node;
      leaf->left->key = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  } else if (key > leaf->key) {
    if (leaf->right != NULL) {
      insert(key, leaf->right);
    } else {
      leaf->right = new node;
      leaf->right->key = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  } else {
    return;
  }
}

void bstree::print_in_order(node *leaf) {
  if (leaf != NULL) {
    print_in_order(leaf->left);
    cout << leaf->key << endl;
    print_in_order(leaf->right);
  }
}

void bstree::destroy_tree(node *leaf) {
  if (leaf != NULL) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
