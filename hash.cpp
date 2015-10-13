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
  } else {
    bool done = false;
    int new_hash_code;

    while (!done) {
      this->size *= 2;
      new_hash_code = hash(key);
      done = true;

      for (int i=0; i<this->size; i++) {
        if (table[i].active) {
          if (new_hash_code == hash(table[i].key)) {
            done = false;
            break;
          }
        }
      }
    }

    table[new_hash_code].key = key;
    table[new_hash_code].val = val;
    table[new_hash_code].active = true;
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