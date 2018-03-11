#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int key;
	Node *next;
	Node(int val): key(val), next(nullptr) {};
};
class List {
	Node *head;
public:
	List(): head(nullptr) {}
	void insert(int);
	void remove(int);
	Node *get_head();
	Node *find(int);
};
Node *List::get_head() {
	return head;
}
void List::insert(int data) {
	Node *curr = head, *prev = nullptr;
	while(curr && curr->key <= data) {
		prev = curr;
		curr = curr->next;
	}
	Node *temp = new Node(data);
	if(prev == nullptr) {
		temp->next = head;
		head = temp;
		return;
	}
	prev->next = temp;
	temp->next = curr;
}
void List::remove(int data) {
	Node *curr = head, *prev = nullptr;
	while(curr && curr->key < data) {
		prev = curr;
		curr = curr->next;
	}
	if(!curr || curr->key != data) {
		std::cerr << "Key does not exist" << std::endl;
		return;
	}
	if(prev == nullptr)
		head = curr->next;
	else
		prev->next = curr->next;
	delete curr;
}
Node *List::find(int data) {
	Node *curr = head, *prev = nullptr;
	while(curr && curr->key < data)
		curr = curr->next;
	if(!curr || curr->key != data) {
		std::cerr << "Key does not exist" << std::endl;
		return nullptr;
	}
	return curr;
}
class Hash_table {
	int size;
	vector<List> hash_table;
public:
	Hash_table(int num): size(num) {
		hash_table.resize(num);
	}
	void print_table();
	int hash_func(int);
	void insert(int);
	void remove(int);
	Node *find(int);
};
void Hash_table::print_table() {
	for(int i = 0; i < size; ++i) {
		if(hash_table[i].get_head() == nullptr) {
			std::cout << "**" << std::endl;
			continue;
		}
		for(Node *temp = hash_table[i].get_head(); temp != nullptr; temp = temp->next)
			std::cout << temp->key << " \n"[!temp->next];
	}
}
int Hash_table::hash_func(int key) {
	return key % size;
}
void Hash_table::insert(int key) {
	int hash_val = hash_func(key);
	hash_table[hash_val].insert(key);
}
void Hash_table::remove(int key) {
	int hash_val = hash_func(key);
	hash_table[hash_val].remove(key);
}
Node *Hash_table::find(int key) {
	int hash_val = hash_func(key);
	return hash_table[hash_val].find(key);
}
int main() {
	Hash_table ht(16);
	ht.insert(19);
	ht.print_table();
	cout << "---\n";
	ht.insert(23);
	ht.print_table();
	cout << "---\n";
	ht.insert(5);
	ht.print_table();
	cout << "---\n";
	ht.insert(94);
	ht.print_table();
	cout << "---\n";
	ht.insert(87);
	ht.print_table();
	cout << "---\n";
	ht.remove(5);
	ht.print_table();
	cout << "---\n";
	ht.remove(23);
	ht.print_table();
	cout << "---\n";
	Node *temp = ht.find(94);
	std::cout << temp->key << std::endl;
	temp = ht.find(4);
	std::cout << ((temp) ? "has" : "nullptr") << std::endl;
	ht.remove(887);
	ht.insert(101010);
	ht.print_table();
	ht.remove(87);
	ht.print_table();
	return 0;
}
