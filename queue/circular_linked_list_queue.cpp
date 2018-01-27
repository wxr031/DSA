#include <iostream>
#include <limits>
struct listnode {
	int data;
	listnode *next;
	listnode(int val): data(val), next(this) {}
};
class cll_queue {
	listnode *tail;
	listnode *head;
public:
	cll_queue(): tail(nullptr), head(nullptr) {}
	void enqueue(int);
	int dequeue();
};
void cll_queue::enqueue(int val) {
	if(!head) {
		head = tail = new listnode(val);
		return;
	}
	listnode *temp = new listnode(val);
	tail->next = temp;
	tail = temp;
	tail->next = head;
}
int cll_queue::dequeue() {
	if(!head) {
		std::cerr << "Queue Underflow" << std::endl;
		return std::numeric_limits<int>::max();
	}
	int ret = head->data;
	if(head == tail) {
		delete head;
		head = tail = nullptr;
		return ret;
	}
	listnode *temp = head;
	head = head->next;
	tail->next = head;
	delete temp;
	return ret;
}
int main() {
	cll_queue Q;
	int cmd;
	int val;
	while(std::cin >> cmd) {
		switch(cmd) {
			case 0:
				std::cin >> val;
				Q.enqueue(val);
				break;
			case 1:
				std::cout << Q.dequeue() << std::endl;
				break;
			default:
				break;
		}
	}
	return 0;
}
