#include <iostream>
void insert(int *arr, int n) {
	for (int i = 1; i < n; i ++) {
		int temp = arr[i];
		int pos;
		for (pos = i - 1; pos >= 0 && temp < arr[pos]; pos --)
			arr[pos + 1] = arr[pos];
		arr[pos + 1] = temp;
	}
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	insert(arr, n);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
