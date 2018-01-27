#include <iostream>
#include <limits>
class mul_queue {
	constexpr static int max_size = 1024;
	int q_num, free_pos;
	int *data, *front, *back, *prev, *next;
	int *size;
public:
	mul_queue(int);
	void push(int, int);
	int pop(int);
	int get_front(int);
	int get_size(int);
};
mul_queue::mul_queue(int N) {
	q_num = N;
	free_pos = 0;
	data = new int[max_size];
	front = new int[N];
	back = new int[N];
	prev = new int[max_size];
	next = new int[max_size];
	size = new int[N]();
	std::fill(front, front + max_size, -1);
	std::fill(back, back + max_size, -1);
	std::fill(next, next + max_size, -1);
	for(int i = 0; i < max_size; i ++)
		prev[i] = i + 1;
}
void mul_queue::push(int q_id, int val) {
	if(free_pos == max_size) {
		std::cout << "Queue Overflow" << std::endl;
		return;
	}
	int free_tmp = prev[free_pos];
	prev[free_pos] = back[q_id];
	if(back[q_id] != -1)
		next[back[q_id]] = free_pos;
	back[q_id] = free_pos;
	if(front[q_id] == -1)
		front[q_id] = free_pos;
	data[free_pos] = val;
	free_pos = free_tmp;
	size[q_id] ++;
}
int mul_queue::pop(int q_id) {
	if(front[q_id] == -1) {
		std::cout << "Queue Underflow" << std::endl;
		return std::numeric_limits<int>::min();
	}
	int next_tmp = next[front[q_id]];
	prev[front[q_id]] = free_pos;
	next[front[q_id]] = -1;
	if(next_tmp != -1)
		prev[next_tmp] = -1;
	free_pos = front[q_id];
	front[q_id] = next_tmp;
	if(next_tmp == -1)
		back[q_id] = next_tmp;
	size[q_id] --;
	return data[free_pos];
}
int mul_queue::get_front(int q_id) {
	if(front[q_id] == -1) {
		std::cout << "Queue Underflow" << std::endl;
		return std::numeric_limits<int>::min();
	}
	return data[front[q_id]];
}
int mul_queue::get_size(int q_id) {
	return size[q_id];
}
int main() {
	int num;
	std::cin >> num;
	mul_queue Q(num);
	int cmd;
	int queue_n, val;
	while(std::cin >> cmd) {
		switch(cmd) {
		case 0:
			std::cin >> queue_n >> val;
			Q.push(queue_n, val);
			break;
		case 1:
			std::cin >> queue_n;
			std::cout << Q.pop(queue_n) << std::endl;
			break;
		case 2:
			std::cin >> queue_n;
			std::cout << Q.get_front(queue_n) << std::endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
