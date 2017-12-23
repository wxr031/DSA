#include <stdio.h>
#include <stdlib.h>

struct listnode
{
	int data;
	struct listnode *next;
};
void swapNodes(struct listnode **head_ref, int x, int y)
{
    if (x == y) return;
    struct listnode *node1, *node2, *prev1 = NULL, *prev2 = NULL;
    struct listnode *track = *head_ref, *prev = NULL;
    int find_first = 1;
    while (track != NULL) {
        if (track->data == x || track->data == y) {
            if (find_first) {
                prev1 = prev;
                node1 = track;
                find_first = 0;
            }
            else {
                prev2 = prev;
                node2 = track;
                break;
            }
        }
        prev = track;
        track = track->next;
    }
    if (!prev1 && node1 == prev2) {
        node1->next = node2->next;
        node2->next = node1;
        *head_ref = node2;
        return;
    }
    else if (!prev1) {
        struct listnode *temp = node1->next;
        node1->next = node2->next;
        prev2->next = node1;
        node2->next = temp;
        *head_ref = node2;
    }
    else if (node1 == prev2) {
        prev1->next = node2;
        node1->next = node2->next;
        node2->next = node1;
    }
    else {
        struct listnode *temp = node2->next;
        prev1->next = node2;
        node2->next = node1->next;
        prev2->next = node1;
        node1->next = temp;
    }
}
int main() {
	/* Add test code */
	return 0;
}
