#include <iostream>
void bubble(int *arr, int n) {
	for (int chg = n - 1; chg > 0; chg --)
		for (int i = 0; i < chg; i ++)
			if (arr[i] > arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
}
int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> arr[i];
	bubble(arr, n);
	for (int i = 0; i < n; i ++)
		std::cout << arr[i] << " \n"[i == n - 1];
	return 0;
}
