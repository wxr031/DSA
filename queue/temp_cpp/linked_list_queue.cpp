#include <iostream>
using namespace std;

class Listnode;
class Queue;

class Listnode {
	int data;
	Listnode *next;
	friend Queue;
};
class Queue {
	Listnode *front;
	Listnode *rear;
public:
	Queue(): front(nullptr), rear(nullptr) {}
	bool is_empty();
	void enqueue(int data);
	int dequeue();
};
bool Queue::is_empty() {
	return front == nullptr;
}
void Queue::enqueue(int data) {
	Listnode new_node = new Listnode;
	new_node.data = data;
	new_node.next = nullptr;
	if (rear == nullptr) {
		rear = front = new_node;
		return;
	}
	rear.next = new_node;
	rear = new_node;
}
int Queue::dequeue() {
	if (is_empty()) {
		cout << "Underflow" << endl;
		return INT_MIN;
	}
	Listnode *temp = front;
	if (rear == front) rear = front = nullptr;
	else front = front.next;
	int data_return = temp.data;
	delete temp;
	return data_return;
}
int main() {
	/* Add test code */
	return 0;
}
