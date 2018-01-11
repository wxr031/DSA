#include <iostream>
void merge_array(int *arr, int *temp, int l_start, int l_end, int r_end) {
	int r_start = l_end + 1;
	int t_count = l_start;
	int l_start_temp = l_start;
	while (l_start <= l_end && r_start <= r_end) { // remember there's an equal sign here
		if (arr[l_start] < arr[r_start])
			temp[t_count ++] = arr[l_start ++];
		else
			temp[t_count ++] = arr[r_start ++];
	}
	while (l_start <= l_end)
		temp[t_count ++] = arr[l_start ++];
	while (r_start <= r_end)
		temp[t_count ++] = arr[r_start ++];
	std::copy(temp + l_start_temp, temp + r_end + 1, arr + l_start_temp);
}
void merge_sort(int *arr, int *temp, int left, int right) {
	if (right <= left)
		return;
	int mid = (left + right) >> 1;
	merge_sort(arr, temp, left, mid);
	merge_sort(arr, temp, mid + 1, right);
	merge_array(arr, temp, left, mid, right);
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	int *temp = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	merge_sort(arr, temp, 0, n - 1);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
