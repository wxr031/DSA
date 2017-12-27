#include <iostream>
#define ARR_MAX 4096
typedef struct element {
	int data;
	int key;
} Element;
class priority_queue {
	Element *heap;
	int size;
	void heapify(int pos);
public:
	priority_queue(): size(0) {
		heap = new Element[ARR_MAX];
	}
	int get_max_val();
	int get_max_key();
	int extract_max_val();
	int extract_max_key();
	void insert(int, int);
	int get_size();
};
void priority_queue::heapify(int pos) {
	int left = pos * 2 + 1;
	int right = left + 1;
	int max = pos;
	if (left < size && heap[left].key > heap[max].key)
		max = left;
	if (right < size && heap[right].key > heap[max].key)
		max = right;
	if (max != pos) {
		std::swap(heap[max], heap[pos]);
		heapify(max);
	}
}
int priority_queue::get_max_val() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	return heap[0].data;
}
int priority_queue::get_max_key() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	return heap[0].key;
}
int priority_queue::extract_max_val() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	Element max = heap[0];
	heap[0] = heap[size - 1];
	size --;
	heapify(0);
	return max.data;
}
int priority_queue::extract_max_key() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	Element max = heap[0];
	heap[0] = heap[size - 1];
	size --;
	heapify(0);
	return max.key;
}
void priority_queue::insert(int key, int data) {
	heap[size].data = data;
	heap[size].key = key;
	int curr = size;
	int par = (curr - 1) / 2;
	size ++;
	while (curr >= 0 && heap[par].key < heap[curr].key) {
		heap[curr] = heap[par];
		curr = par;
		par = (curr - 1) / 2;
	}
	heap[curr].data = data;
	heap[curr].key = key;
}
int priority_queue::get_size() {
	return size;
}
