#include <iostream>
#include "hash.h"

using namespace std;

struct entry {
  const char *key;
  int val;
  bool active;
};

hash_table::hash_table(int size) {
  this->size = size;
  table = new entry[size];
}

hash_table::~hash_table() {
  delete[] table;
}

void hash_table::set(const char *key, int val) {
  int hashCode = hash(key);
  if (!table[hashCode].active) {
    table[hashCode].key = key;
    table[hashCode].val = val;
    table[hashCode].active = true;
  } else {
    cout << "collision for key: " << key << endl;
  }
}

void hash_table::print_table() {
  bool firstEntry = true;

  cout << "[ ";
  for (int i=0; i<this->size; i++) {
    if (table[i].active) {
      if (!firstEntry) {
        cout << ", ";
      } else {
        firstEntry = false;
      }
      cout << "(" << table[i].key << ": " << table[i].val << ")";
    }
  }
  cout << " ]" << endl;
}

int hash_table::hash(const char *str) {
  int h = 0;
  while (*str) {
    h = h << 1 ^ *str++;
  }
  return (h > 0 ? h : -h) % this->size;
}