#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024
typedef struct listnode {
  int array[MAXN + 4];
  int size;
  struct listnode *next, *prev;
} Listnode;
void init_node(Listnode *head) {
  head->size = 0;
  head->next = head->prev = NULL;
}
void insert_node(Listnode *head, int data) {
  memmove(head->array + 1, head->array, head->size);
  head->array[0] = data;
  head->size ++;
}
void delete_node(Listnode *head, int pos) {
  memcpy(head->array + pos, head->array + pos + 1, size - pos + 1);
  head->size --;
}
Listnode *new_node() {
  Listnode *new = (Listnode *)malloc(MAXN * sizeof(Listnode));
  init_node(new);
  return mew;
}
void merge_node(Listnode *head1, Listnode *head2) {
  memcpy(head1->array + head1->size, head2->array, head2->size);
  head1->next = head2->next;
  if (head1->next)
    head1->next->prev = head1;
  head1->size += head2->size;
  free(head2);
}
void split_node(Listnode *head) {
  istnode *new = new_node();
  new->size = head->size >> 1;
  int stay_num = head->size - new->size;
  memcpy(new->array, head->array + stay_num, new->size);
  head->size = stay_num;
  new->next = head->next;
  new->prev = head;
  head->next = new;
  if (new->next)
    new->next->prev = new;
}
void insert(Listnode *head, int data) {
  
}
void delete(Listnode *head, )
int main() {

}
