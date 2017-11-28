#include <iostream>
using namespace std;
class Queue {
	int front, rear, capacity;
	int *array;
public:
	Queue(int size): front(-1), rear(-1), capacity(size) {
		array = new int[size];
	} // let front = -1, rear = -1 represent empty state
	bool is_empty();
	bool is_full();
	void enqueue(int data);
	int dequeue();
	int get_size();
#ifdef DEBUG
	friend void printCircularQueue(Queue q);
#endif
};
#ifdef DEBUG
void printCircularQueue(Queue q) {
#ifdef CALL_COMP
	cout << "capacity " << q.capacity << endl;
	cout << "front " << q.front << " rear " << q.rear << endl;
#endif
	if (q.front == -1) return;
	int start = q.front;
	cout << q.array[start] << endl; // <- remember to do this
	while (start != q.rear) {
		start = (start == q.capacity - 1)? 0: start + 1;
		cout << q.array[start] << endl;
	}
}
#endif
bool Queue::is_empty() {
	return front == -1;
}
bool Queue::is_full() {
	return (rear == 0 && front == capacity - 1 || rear + 1 == front);
}
void Queue::enqueue(int data) {
	if (is_full()) {
		cout << "overflow" << endl;
		return;
	}
	if (rear == capacity - 1) rear = 0;
	else rear ++; // alternative method: rear = (rear + 1) % capacity
	array[rear] = data;
	if (front == -1) front = 0; // if the queue is empty, make front points to 0
}
int Queue::dequeue () {
	if (is_empty()) {
		cout << "underflow" << endl;
		return INT_MIN;
	}
	int data = array[front];
	if (front == rear) front = rear = -1; // if there's only one element left, set the queue empty
	else if (front == capacity - 1) front = 0;
	else front ++; //alternative method: front = (front + 1) % capacity
	return data;
}
int Queue::get_size() {
	if (is_empty()) return 0;
	return (rear > front)? rear - front + 1: capacity - front + rear + 1;
}
int main() {
	Queue q(5);
    if (q.is_empty()) {
        cout << "queue is empty.\n\n";
    }
	q.enqueue(14);
	q.enqueue(22);
	q.enqueue(13);
	q.enqueue(-6);
	q.dequeue();
	q.enqueue(-1);
	q.enqueue(-8);
	q.enqueue(9);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	printCircularQueue(q);
    return 0;
}
