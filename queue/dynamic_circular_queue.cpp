#include <iostream>
using namespace std;
class Queue {
	int front, rear;
	int capacity;
	int *array;
	void double_size();
	bool is_full();
public:
	Queue(): front(-1), rear(-1), capacity(1) {
		array = new int[capacity];
	}
	bool is_empty();
	void enqueue(int data);
	int dequeue();
	int get_size();	
};
void Queue::double_size() {
	int prev_capacity = capacity;
	capacity <<= 1;
	int *new_array = new int[capacity];
	if (rear >= front) {
		for (int i = front; i <= rear; i ++)
			new_array[i] = array[i];
	} else {
		for (int i = front; i < prev_capacity; i ++)
			new_array[i] = array[i];
		for (int i = 0; i <= rear; i ++)
			new_array[i + prev_capacity] = array[i];
		rear += prev_capacity;
	}
	delete [] array;
	array = new_array;
}
bool Queue::is_full() {
	return rear == capacity - 1 && front == 0 || rear + 1 == front;
}
bool Queue::is_empty() {
	return front == -1;
}
void Queue::enqueue(int data) {
	if (is_full()) double_size();
	if (rear == capacity - 1) rear = 0;
	else rear ++;
	array[rear] = data;
	if (front == -1) front = 0;
}
int Queue::dequeue() {
	if (is_empty()) {
		cout << "Underflow" << endl;
		return INT_MIN;
	}
	int data_return = array[front];
	if (front == rear) front = rear = -1;
	else if (front == capacity - 1) front = 0;
	else front ++;
	return data_return;
}
int main() {
	/* Add test code */
	return 0;
}
