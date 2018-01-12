#include <iostream>
#include <cstdlib>
#include <ctime>
int partition(int *arr, int left, int right) {
	int num = right - left + 1;
	int pivot = left + rand() % num;
	std::swap(arr[pivot], arr[right]);
	int p = left;
	for (int q = left; q < right; q ++) {
		if (arr[q] < arr[right]) {
			std::swap(arr[p], arr[q]);
			p ++;
		}
	}
	std::swap(arr[p], arr[right]);
	return p;
}
void quick_sort(int *arr, int left, int right) {
	if (right <= left) return;
	int pivot = partition(arr, left, right);
	quick_sort(arr, left, pivot);
	quick_sort(arr, pivot + 1, right);
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
