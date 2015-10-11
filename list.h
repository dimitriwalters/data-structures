#ifndef LIST_H_
#define LIST_H_

struct node;

class list {
public:
  list();
  ~list();

  void push_front(int val);
  void print_list();

private:
  void print_list(node *el);
  void destroy_list(node *el);

  node *head;
};

#endif // LIST_H_