#include <iostream>
#include "list.h"

using namespace std;

struct node {
  int data;
  struct node *next;
};

list::list() {
  head = NULL;
}

list::~list() {
  destroy_list(head);
}

void list::push_front(int val) {
  if (head == NULL) {
    head = new node;
    head->data = val;
    head->next = NULL;
  } else {
    node *newnode = new node;
    newnode->data = val;
    newnode->next = head;

    head = newnode;
  }
}

void list::print_list() {
  print_list(head);
  cout << endl;
}

void list::print_list(node *el) {
  if (el == NULL) {
    return;
  } else {
    if (el != head) {
      cout << " -> ";
    }
    cout << el->data;
    print_list(el->next);
  }
}

void list::destroy_list(node *el) {
  if (el == NULL) {
    return;
  } else {
    destroy_list(el->next);
    delete el;
  }
}