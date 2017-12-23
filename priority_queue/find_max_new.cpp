#include <iostream>
void heapify(int *array, int size, int i) {
	int left = 2 * i + 1;
	int right = left + 1;
	int min_id = i;
	if (left < size && array[left] > array[min_id])
		min_id = left;
	if (right < size && array[right] > array[min_id])
		min_id = right;	
	if (min_id != i) {
		std::swap(array[i], array[min_id]);
		heapify(array, size, min_id);
	}
}
int extract_max(int *array, int *size){
	int ret = array[0];
	array[0] = array[*size - 1];
	-- *size;
	heapify(array, *size, 0);
	return ret;
}
void insert(int *array, int size, int data) {
	int curr = size;
	array[curr] = data;
	size ++;
	int par = (curr - 1) / 2;
	while (par >= 0 && array[par] < data) {
		array[curr] = array[par];
		curr = par;
		par = (curr - 1) / 2;
	}
	array[curr] = data;
}
void build_heap(int *array, int size) {
	int first_nonleaf = (size - 2) / 2;
	for (int i = first_nonleaf; i >= 0; i --)
		heapify(array, size, i);
}
int *find_max(int *array, int max_num, int size) {
	const int sort_num = 64;
	int *max_arr = new int[max_num];
	int *buffer = new int[sort_num];
	for (int i = 0; i < max_num; i ++) {
		max_arr[i] = array[i];
		size --;
	}
	array += max_num;
	while (size) {
		int cp_size_num = (size > sort_num - max_num)? sort_num - max_num : size;
		int total_num = cp_size_num + max_num;
		std::copy(max_arr, max_arr + max_num, buffer);
		std::copy(array, array + cp_size_num, buffer + max_num);
		build_heap(buffer, total_num);
		for (int i = 0; i < max_num; i ++)
			max_arr[i] = extract_max(buffer, &total_num);
		array += cp_size_num;
		size -= cp_size_num;
	}
	return max_arr;
}
int main() {
	int count = 0;
	int array[10000];
	int num;
	std::cin >> num;
	while (std::cin >> array[count])
		count ++;
	int *max = find_max(array, num, count);
	for (int i = 0; i < num; i ++)
		std::cout << max[i] << " \n"[i == num - 1];
	return 0;
}
