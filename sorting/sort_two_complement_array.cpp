#include <iostream>
void merge(int *arr1, int *arr2, int n, int m) {
	int end1 = n - 1, end2 = m - 1, end_all = m + n - 1;
	while (end2 >= 0) {
		if (arr1[end1] > arr2[end2])
			arr1[end_all --] = arr1[end1 --];
		else
			arr1[end_all --] = arr2[end2 --];
	}
}
int main() {
	int n, m;
	std::cin >> n >> m;
	int *arr1 = new int[n + m]();
	int *arr2 = new int[m];
	for (int i = 0; i < n; i ++)
		std::cin >> arr1[i];
	for (int i = 0; i < m; i ++)
		std::cin >> arr2[i];
	merge(arr1, arr2, n, m);
	for (int i = 0; i < n + m; i ++)
		std::cout << arr1[i] << " \n"[i == n + m - 1];
	return 0;
}
