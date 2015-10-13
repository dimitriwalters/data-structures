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
  int hash_code = hash(key);

  if (!table[hash_code].active) {
    table[hash_code].key = key;
    table[hash_code].val = val;
    table[hash_code].active = true;
  } else if (key == table[hash_code].key) {
    table[hash_code].val = val;
  } else {
    bool done = false;
    int original_size = this->size;
    int new_hash_code = 0;
    int updated_hash_code = 0;
    entry *new_table;

    while (!done) {
      this->size *= 2;
      new_hash_code = hash(key);
      done = true;

      for (int i=0; i<original_size; i++) {
        if (table[i].active) {
          if (new_hash_code == hash(table[i].key)) {
            done = false;
            break;
          }
        }
      }
    }

    new_table = new entry[this->size];

    for (int i=0; i<original_size; i++) {
      if (table[i].active) {
        updated_hash_code = hash(table[i].key);
        new_table[updated_hash_code].key = table[i].key;
        new_table[updated_hash_code].val = table[i].val;
        new_table[updated_hash_code].active = true;
      }
    }
    new_table[new_hash_code].key = key;
    new_table[new_hash_code].val = val;
    new_table[new_hash_code].active = true;

    delete[] table;
    table = new_table;
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
      cout << i << ": (" << table[i].key << ": " << table[i].val << ")";
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