#include <iostream>
#include <limits>
int binary_search(int *arr, int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else return mid;
	}
	return std::numeric_limits<int>::min();
}
int binary_search_recursive(int *arr, int key, int left, int right) {
	if (left > right)
		return std::numeric_limits<int>::min();
	int mid = (left + right) >> 1;
	if (key < arr[mid])
		return binary_search_recursive(arr, key, left, mid - 1);
	else if (key > arr[mid])
		return binary_search_recursive(arr, key, mid + 1, right);
	else return mid;
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	int key;
	while (std::cin >> key)
		std::cout << binary_search_recursive(arr, key, 0, n - 1) << std::endl;
	return 0;
}
