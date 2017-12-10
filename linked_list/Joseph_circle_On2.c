#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
Listnode *newnode(Listnode *head, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	if (!head) {
		new->next = new;
		return new;
	}
	Listnode *temp = head;
	while (temp->next != head)
		temp = temp->next;
	temp->next = new;
	new->next = head;
	return head;
}
void delete(Listnode *track) {
	Listnode *temp = track->next;
	track->next = track->next->next;
	free(temp);
}
int main() {
	Listnode *head = NULL;
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i ++)
		head = newnode(head, i);
	Listnode *track = head;
	for (int i = 1; i <= N - 1; i ++) {
		for (int j = 1; j < M - 1; j ++) 
			track = track->next;
		delete(track); // the delete function deletes track->next
		track = track->next;
	}
	printf("%d\n", track->data);
	return 0;
}
