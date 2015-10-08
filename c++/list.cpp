#include <cstdio>
#include <cstdlib>
#include "list.h"

struct node *list_create(int item) {
  struct node *list = (struct node*)malloc(sizeof(struct node));
  if (list == NULL) {
    printf("ERROR: append ran out of memory\n");
    exit(EXIT_FAILURE);
  }
  list->item = item;
  list->next = NULL;
  return list;
}

struct node *list_insert_beginning(int item, struct node *list) {
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("ERROR: append ran out of memory\n");
    exit(EXIT_FAILURE);
  }
  newnode->item = item;
  newnode->next = list;
  return newnode;
}

struct node *list_remove_beginning(struct node *list) {
  struct node *next = list->next;
  free(list);
  return next;
}

struct node *list_find_node(int item, struct node *list) {
  while (list != NULL) {
    if (list->item == item) {
      return list;
    }
    list = list->next;
  }
  return NULL;
}

void list_print(struct node *list) {
  while (list != NULL) {
    printf("%d", list->item);
    if (list->next != NULL) {
      printf(":");
    }
    list = list->next;
  }
  printf("\n");
}

void list_destroy(struct node *list) {
  struct node *next = NULL;
  while (list != NULL) {
    next = list->next;
    free(list);
    list = next;
  }
}