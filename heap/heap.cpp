#include <iostream>
class min_heap {
private:
	int *array;
	int capacity; // maximal capacity of the heap
	int size; // size of the heap
public:
	min_heap(int):
	~min_heap();
	int parent(int);
	int left_child(int);
	int right_child(int);
	void heapify_down(int i);
	void delete_min();
	void insert(int data);

	friend min_heap build_heap(int *, int);
	friend heap_sort(int *Arr);
};
min_heap::min_heap(int Cap) {
	capacity = Cap;
	size = 0;
	array = new int[capacity];
}
min_heap::~min_heap() {
	delete [] array;
}
int min_heap::parent(int i) {
	if (i < 0 || i > size)
		return -1; // in order to fit the heapify_down function
	return (i - 1) / 2;
}
int min_heap::left_child(int i) {
	if (i < 0 || i > size)
		return -1; // inorder to fit the heapify_down function
	return 2 * i + 1;
}
int min_heap::right_child(int i) {
	if (i < 0 || i > size)
		return -1; // inorder to fit the heapify_down function
	return 2 * i + 2;
}
void min_heap::heapify(int i) {
	int left = left_child();
	int right = right_child();
	int min_id = i;
	/* find the maximum of left, right, and i */
	if (left != -1 && array[left] < array[min_id])
		min_id = left;
	if (right != -1 && array[right] < array[min_id])
		min_id = right;	
	if (min_id != i) {
		std::swap(array[i], array[min_id]);
		heapify(min_id);
	}
}
void min_heap::delete_min(){
	if (size == 0) {
		std::cout << "Heap Underflow" << std::endl;
		return;
	}
	int ret = array[0];
	array[0] = array[size - 1];
	size --;
	heapify(0);
	return ret;
}
void min_heap::insert(int data) {
	 if (size == capacity) {
		std::cout << "Heap Overflow" << std::endl;
		return;
	}
	int i = size;
	int Par = parent(i);
	while (Par != -1 && array[Par] > data) {
		array[i] = array[par];
		i = par;
		par = parent(i);
	}
	array[i] = data;
}
min_heap build_heap(int *Arr, int num) {
	min_heap new_heap(num);
	std::copy(Arr, Arr + num - 1, new_heap.array);
	int first_non_leaf_node = (num - 1) / 2;
	for (int i = first_non_leaf_node; i >= 0; i --)
		heapify(Arr, i);
	return new_heap;
}
void heap_sort(int *Arr, int num) {
	min_heap H = build_heap(Arr, num);
	for (int i = n - 1; i >= 0; i --) {
		std::swap(H.array[i], H.array[0]);
		heapify(0);
	}
}
