#include <iostream>
int max_occurrence(int *arr, int n) {
	int max = -1, max_id;
	for (int i = 0; i < n; i ++)
		arr[arr[i] % n] += n;
	for (int i = 0; i < n; i ++)
		if (arr[i] / n > max) {
			max = arr[i] / n;
			max_id = i;
		}
	return max_id;
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	std::cout << max_occurrence(arr, n) << std::endl;
	delete [] arr;
	return 0;
}
