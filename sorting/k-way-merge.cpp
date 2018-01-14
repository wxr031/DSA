#include <iostream>
#include <limits>
struct node {
	int chunk;
	int data;
};
void heapify(node *arr, int n, int i) {
	int min = i;
	int left = (i << 1) + 1;
	int right = left + 1;
	if (left < n && arr[left].data < arr[min].data)
		min = left;
	if (right < n && arr[right].data < arr[min].data)
		min = right;
	if (min != i) {
		std::swap(arr[min], arr[i]);
		heapify(arr, n, min);
	}
}
void heapify(int *arr, int n, int i) {
	int min = i;
	int left = (i << 1) + 1;
	int right = left + 1;
	if (left < n && arr[left] < arr[min])
		min = left;
	if (right < n && arr[right] < arr[min])
		min = right;
	if (min != i) {
		std::swap(arr[min], arr[i]);
		heapify(arr, n, min);
	}
}
void insert(node *arr, int &n, node put) {
	int curr = n;
	int par = (curr - 1) >> 1;
	arr[n ++] = put;
	while (par >= 0 && arr[par].data > put.data) {
		arr[curr] = arr[par];
		curr = par;
		par = (curr - 1) >> 1;
	}
	arr[curr] = put;
}
void build_heap(node *arr, int n) {
	int last_leaf = (n - 2) >> 1;
	for (int i = last_leaf; i >= 0; i --)
		heapify(arr, n, i);
}
void build_heap(int *arr, int n) {
	int last_leaf = (n - 2) >> 1;
	for (int i = last_leaf; i >= 0; i --)
		heapify(arr, n, i);
}
node extract(node *arr, int &n) {
	node ret = arr[0];
	arr[0] = arr[-- n];
	heapify(arr, n, 0);
	return ret;
}
int *mergeKArrays(int **arr, int k)
{
	node *aux = new node[k];
	int *res = new int[k * k];
	int *load_num = new int[k]();
	int empty_chunk = k;
	int curr = 0;
	for (int i = 0; i < k; i ++) {
		build_heap(arr[i], k);
		aux[i].chunk = i;
		aux[i].data = arr[i][load_num[i] ++];
	}
	build_heap(aux, k);
	while (empty_chunk) {
		node get = extract(aux, k); // k is now one smaller than its origin value
		res[curr ++] = get.data;
		node put;
		put.chunk = get.chunk;
		if (load_num[get.chunk] > k) { /* note that k is one smaller that its origin value
		that's why we use > instead of >= */
			put.data = std::numeric_limits<int>::max();
			empty_chunk --;
		}
		else put.data = arr[get.chunk][load_num[get.chunk] ++];
		insert(aux, k, put); // the value of k turns back to normal
	}
	return res;
}
int main() {
	int n;
	std::cin >> n;
	int **arr = new int * [n];
	for (int i = 0; i < n; i ++)
		arr[i] = new int [n];
	for(int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			std::cin >> arr[i][j];
	int *res = mergeKArrays(arr, n);
	for(int i = 0; i < n * n; i ++)
		std::cout << res[i] << " \n"[i == n * n- 1];
	return 0;
}
