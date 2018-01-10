#include <iostream>
#include <deque>
int main() {
	int n, k;
	std::cin >> n >> k;
	int *array = new int[n];
	for (int i = 0; i < n; i ++)
		std::cin >> array[i];
	std::deque<int> DQ;
	for (int i = 0; i < k; i ++) {
		while (!DQ.empty() && array[i] > array[DQ.back()])
			DQ.pop_back();
		DQ.push_back(i);
	}
	for (int i = k; i < n; i ++) {
		std::cout << array[DQ.front()] << std::endl;
		while (DQ.front() <= i - k)
			DQ.pop_front();
		while (!DQ.empty() && array[i] > array[DQ.back()])
			DQ.pop_back();
		DQ.push_back(i);
	}
	std::cout << array[DQ.front()] << std::endl;
	return 0;
}
