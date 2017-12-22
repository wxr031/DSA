#include <iostream>
#define ARR_MAX 16384
class priority_queue {
	int *heap;
	int size;
	void heapify(int pos);
public:
	priority_queue(): size(0) {
		heap = new int[ARR_MAX];
	}
	int get_max();
	int extract_max();
	void insert(int);
	void get_size();
};
void priority_queue::heapify(int pos) {
	int left = pos * 2 + 1;
	int right = left + 1;
	int max = pos;
	if (left < size && heap[left] > heap[max])
		max = left;
	if (right < size && heap[right] > heap[max])
		max = right;
	if (max != pos) {
		std::swap(heap[max], heap[pos]);
		heapify(max);
	}
}
int priority_queue::get_max() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	return heap[0];
}
int priority_queue::extract_max() {
	if (size <= 0) {
		std::cout << "Priority Queue Underflow" << std::endl;
		return INT_MIN;
	}
	int max = heap[0];
	heap[0] = heap[size - 1];
	size --;
	heapify(0);
	return max;
}
void priority_queue::insert(int data) {
	heap[size] = data;
	int curr = size;
	int par = (curr - 1) / 2;
	size ++;
	while (curr >= 0 && heap[par] < heap[curr]) {
		heap[curr] = heap[par];
		curr = par;
		par = (curr - 1) / 2;
	}
	heap[curr] = data;
}
int main() {
	/* Add test code */
	return 0;
}
