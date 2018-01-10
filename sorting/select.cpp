#include <iostream>
#include <limits>
void select(int *arr, int n) {
	for (int i = 0; i < n - 1; i ++) {
		int min = std::numeric_limits<int>::max();
		int min_id;
		for (int j = i; j < n; j ++) {
			if (arr[j] < min) {
				min = arr[j];
				min_id = j;
			}
		}
		std::swap(arr[i], arr[min_id]);
	}

}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	select(arr, n);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
