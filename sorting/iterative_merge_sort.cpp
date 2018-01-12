#include <iostream>
void merge(int *arr, int *temp, int l_start, int r_start, int r_end) {
	int l_end = r_start - 1;
	int count_t = l_start;
	int cp_start = l_start;
	while (l_start <= l_end && r_start <= r_end) {
		if (arr[l_start] <= arr[r_start])
			temp[count_t ++] = arr[l_start ++];
		else temp[count_t ++] = arr[r_start ++];
	}
	while (l_start <= l_end)
		temp[count_t ++] = arr[l_start ++];
	while (r_start <= r_end)
		temp[count_t ++] = arr[r_start ++];
	std::copy(temp + cp_start, temp + r_end + 1, arr + cp_start);
}
void iterative_merge_sort(int *arr, int *temp, int n) {
	for (int size = 1; size <= n; size <<= 1) {
		for (int left = 0; left + size < n; left += (size << 1)) {
			int right = std::min(left + (size << 1), n);
			merge(arr, temp, left, left + size, right - 1);
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	int *temp = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	iterative_merge_sort(arr, temp, n);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
