#include <iostream>
void shell(int arr[], int n) {
	for (int gap = n >> 1; gap > 0; gap >>= 1) {
		for (int i = gap; i < n; i ++) {
			int temp = arr[i];
			int j;
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	shell(arr, n);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
