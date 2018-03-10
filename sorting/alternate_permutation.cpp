#include <iostream>
#include <vector>
void alternate_permutation(std::vector<int> &vec, int num) {
	if(num <= 1)
		return;
	for(int i = 0, j = 1; j < num; ++i, ++j) {
		if((i & 1 && vec[i] < vec[j]) || 
				(!(i & 1) && vec[i] > vec[j]))
			std::swap(vec[i], vec[j]);
	}
}
int main() {
	int num;
	std::cin >> num;
	std::vector<int> vec(num);
	for(int i = 0; i < num; ++i)
		std::cin >> vec[i];
	alternate_permutation(vec, num);
	for(int i = 0; i < num; ++i)
		std::cout << vec[i] << " \n"[i == num - 1];
	return 0;
}
