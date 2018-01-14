#include <iostream>
void sorting(int *arr, int n, int k1, int k2, int k3) {
	int left = 0, right = n - 1, curr = 0;
	while (left <= right && arr[left] == k1)
		left ++;
	while (left <= right && arr[right] == k3)
		right --;
	while (left < right) {
		if (arr[left] == k2) {
			int curr = left;
			while (curr <= right && arr[curr] != k1)
				curr ++;
			if (curr <= right) {
				std::swap(arr[curr], arr[left]);
				left ++;
			}
			else {
				while (left < right) {
					while (left < right && arr[left] != k3)
						left ++;
					std::swap(arr[left], arr[right]);
					while (left < right && arr[right] == k3)
						right --;
				}
			}
		}
		else {
			std::swap(arr[right], arr[left]);
			while (left < right && arr[left] == k1)
				left ++;
			while (left < right && arr[right] == k3)
				right --;
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for(int i = 0 ;i < n; i ++)
		std::cin >> arr[i];
	sorting(arr, n, 0, 1, 2);
	for(int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
