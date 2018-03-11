#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024
typedef struct listnode {
  int array[MAXN + 2];
  struct listnode *prev, *next;
} Listnode;
Listnode *new_node(void) {
  Listnode *new = (Listnode *)malloc(sizeof(Listnode));
  new->prev = new->next = NULL;
  return new;
}
void insert_data(Listnode *head, int pos, int data) {
  memmove(head->array + pos + 1, head->array + pos, head->size - pos);
  head->array[pos] = data;
}
void split_node(Listnode *head) {
  Listnode *new = new_node();
  new->size = head->size >> 1;
  int remain_size = head->size - new->size;
  memcpy(new, head->array + remain_size, new->size);
  head->size = remain_size;
  new->next = head->next;
  new->prev = head;
  head->next = new;
  if(new->next)
    new->next->prev = new;
}
void merge_node(Listnode *head1, Listnode *head2) {
  memcpy(head1->array + head1->size, head2->array, head2->size);
  head1->size += head2->size;
  head1->next = head2->next;
  if (head1->next)
    head1->next->prev = head1;
  free(head2);
}
int cmp(const void *n1, const void *n2) {
  return (n1 > n2) ? 1 : (n1 < n2) ? -1 : 0;
}
void insert(Listnode *head, int data) {
  int right;
  int flag = 1;
  while (head) {
    if (data >= head->array[0] && data <= head->array[head->size - 1]) {
      /* add binary search */
      insert_data(head, pos, data);
      if (head->size > MAXN) {
	split_node(head);
      }
      break;
    }
    head = head->next;
  }
}
void delete(Listnode *head, int data) {
  while (head) {
    if (data >= head->array[0] && data <= head->array[head->size - 1]) {
      /* add binary search */
      if (head->)
    }
  }
}
int main() {
  
}
