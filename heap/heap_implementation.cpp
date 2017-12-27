#include <iostream>
#define ARR_MAX 16384
class priority_queue {
	int *heap;
	int size;
	void heapify(int pos);
	void heapify_by_index();
public:
	priority_queue(): size(0) {
		heap = new int[ARR_MAX];
	}
	int get_max();
	int extract_max();
	void insert(int);
	int get_size();
	int get_kth_max(int);

	friend class index_priority_queue;
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
int priority_queue::get_size() {
	return size;
}
class index_priority_queue {
	int *index_heap;
	int index_size;
public:
	index_priority_queue(): index_size(0) {
		index_heap = new int[ARR_MAX];
	}
	~index_priority_queue() {
		delete [] index_heap;
	}
	void index_heapify(int index_pos) {
		int left = index_pos * 2 + 1;
		int right = left + 1;
		int max = index_pos;
		if (left < index_size && heap[index_heap[left]] > heap[index_heap[max]])
			max = left;
		if (right < size && heap[index_heap[right]] > heap[index_heap[max]])
			max = right;
		if (max != index_pos) {
			std::swap(index_heap[max], index_heap[pos]);
			index_heapify(max);
		}
	}
	int index_extract_max() {
		int max = index_heap[0];
		index_heap[0] = index_heap[size - 1];
		size --;
		index_heapify(0);
		return max;
	}
	void index_insert(int data) {
		index_heap[size] = data;
		int curr = size;
		int par = (size - 1) / 2;
		index_size ++;
		while (par >= 0 && heap[index_heap[par]] < heap[index_heap[curr]]) {
			index_heap[curr] = index_heap[par];
			curr = par;
			par = (curr - 1) / 2;
		}
		index_heap[curr] = data;
	}
};
int priority_queue::get_kth_max(int k) {
	index_priority_queue aux;
	aux.index_insert(0);
	int count = 0;
	while (true) {
		int max_temp = aux.index_extract_max();
		if (++ count == k)
			return heap[max_temp];
		aux.index_insert(2 * max_temp + 1);
		aux.index_insert(2 * max_temp + 2);
	}
}
int main() {
	priority_queue pq;
	pq.insert(5);
	pq.insert(17);
	pq.insert(19);
	pq.insert(8);
	pq.insert(0);
	pq.insert(7);
	pq.insert(14);
	pq.insert(23);
	pq.insert(9);
	pq.insert(13);
	pq.insert(6);
	pq.insert(4);
	pq.insert(3);
	int n;
	std::cin >> n;
	std::cout << pq.get_kth_max(n) << std::endl;
	return 0;
}
