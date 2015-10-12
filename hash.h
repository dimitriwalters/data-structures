#ifndef HASH_H_
#define HASH_H_

struct entry;

class hash_table {
public:
  hash_table(int size);
  ~hash_table();

  void set(const char *key, int val);
  void print_table();

private:
  int hash(const char *str);
  int size;
  entry *table;
};

#endif // HASH_H_