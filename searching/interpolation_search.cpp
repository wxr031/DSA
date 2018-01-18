#include <iostream>
#include <limits>
int interpolation_search(int *arr, int n, int key) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (key - arr[left])
		  / (arr[right] - arr[left]) * (right - left);
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else return mid;
	}
	return std::numeric_limits<int>::min();
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	int key;
	while (std::cin >> key)
		std::cout << interpolation_search(arr, n, key) << std::endl;
	return 0;
}
