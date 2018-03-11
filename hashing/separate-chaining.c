#include <stdio.h>
#include <stdlib.h>
#define LOAD_FACTOR 16

struct node {
	int key, data;
	struct node *next;
};
typedef struct node Node;

struct hash {
	Node **table;
	int size, count;
};
typedef struct hash Hash;

Node *create_node(int key, int data) {
	Node *node = (Node *)malloc(sizeof(Node));
	if(!node) {
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	node->key = key;
	node->data = data;
	node->next = NULL;
	return node;
}

Hash *create_hash(int size) {
	Hash *hash = (Hash *)malloc(sizeof(Hash));
	if(!hash) {
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	hash->table = (Node **)calloc(size, sizeof(Node *));
	if(!hash->table) {
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	hash->count = 0;
	hash->size = size;
	return hash;
}

int hash_func(Hash *hash, int key) {
	return key % hash->size;
}
int search(Hash *hash, int key) {
	int hash_val = hash_func(key);
	Node *curr = hash->table[hash_val];
	while(curr) {
		if(curr->)
	}
}
