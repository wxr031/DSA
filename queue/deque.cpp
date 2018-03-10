#include <iostream>
class Deque {
	int *arr;
	int front, back;
	int capacity;
	void double_size();
	bool full();
public:
	Deque(): front(-1), back(-1), capacity(2) {
		arr = new int[capacity];
	}
	bool empty();
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();

	friend void debug(Deque);
};
bool Deque::empty() {
	return front == -1 && back == -1;
}
bool Deque::full() {
	return back == 0 && front == capacity - 1 || front + 1 == back;
}
void Deque::double_size() {
	int orig_capacity = capacity;
	capacity *= 2;
	int *new_arr = new int[capacity];
	if (front < back)
		std::copy(arr + front, arr + back + 1, new_arr + front);
	else {
		std::copy(arr + front, arr + orig_capacity, new_arr + front);
		std::copy(arr, arr + back + 1, new_arr + orig_capacity);
		back += orig_capacity;
	}
	delete [] arr;
	arr = new_arr;
}
void Deque::push_front(int data) {
	if (full()) double_size();
	if (empty()) front = back = 0;
	else if (front == 0) front = capacity - 1;
	else front --;
	arr[front] = data;
}
void Deque::push_back(int data) {
	if (full()) double_size();
	if (empty()) front = back = 0;
	else if (back == capacity - 1) back = 0;
	else back ++;
	arr[back] = data;
}
int Deque::pop_front() {
	if (empty()) {
		std::cout << "Underflow" << ' ';
		return INT_MIN;
	}
	int ret = arr[front];
	if (front == back) front = back = -1;
	else if (front == capacity - 1) front = 0;
	else front ++;
	return ret;
}
int Deque::pop_back() {
	if (empty()) {
		std::cout << "Underflow" << ' ';
		return INT_MIN;
	}
	int ret = arr[back];
	if (back == front) front = back  = -1;
	else if (back == 0) back = capacity - 1;
	else back --;
	return ret;
}
void debug(Deque D) {
	std::cout << "----" << std::endl;
	std::cout << D.capacity << std::endl;
	std::cout << D.front << ' ' << D.back << std::endl;
	for (int i = 0; i < 10; i ++)
		std::cout << D.arr[i] << ' ';
	std::cout << std::endl;
}
int main() {
	Deque DQ;
	DQ.push_back(5);
	DQ.push_back(10);
	std::cout << DQ.pop_front() << std::endl;
	DQ.push_front(15);
	DQ.push_front(35);
	std::cout << DQ.pop_back() << std::endl;
	DQ.push_back(19);
	DQ.push_front(20);
	DQ.push_back(25);
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_front() << std::endl;
	DQ.push_back(20);
	DQ.push_front(15);
	DQ.push_front(4);
	std::cout << DQ.pop_front() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	DQ.push_front(15);
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	std::cout << DQ.pop_back() << std::endl;
	return 0;
}
