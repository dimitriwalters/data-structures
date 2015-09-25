#ifndef NODE_H_
#define NODE_H_

struct node;

struct node *list_create(int item);

struct node *list_insert_beginning(int item, struct node *list);

struct node *list_remove_beginning(struct node *list);

struct node *list_find_node(int item, struct node *list);

void list_print(struct node *list);

void list_destroy(struct node *list);

#endif // NODE_H_