#include <iostream>
#include <string>
struct Node {
	char data;
	bool is_eof_word;
	Node *left, *mid, *right;
	Node(char);
};
Node::Node(char c) {
	data = c;
	is_eof_word = false;
	left = mid = right = nullptr;
}
class Ternary {
	Node *root;
	Node *insert_util(Node *, std::string, int);
	bool search_util(Node *, std::string, int);
	bool remove_util(Node *, std::string, int);
	public:
	Ternary();
	void insert(std::string);
	bool search(std::string);
	bool remove(std::string);
};
Ternary::Ternary() {
	root = nullptr;
}
Node *Ternary::insert_util(Node *curr, std::string str, int pos) {
	if(!curr)
		curr = new Node(str[pos]);
	if(str[pos] < curr->data)
		curr->left = insert_util(curr->left, str, pos);
	else if(str[pos] > curr->data)
		curr->right = insert_util(curr->right, str, pos);
	else if(str[pos + 1])
		curr->mid = insert_util(curr->mid, str, pos + 1);
	else
		curr->is_eof_word = true;
	return curr;
}
void Ternary::insert(std::string str) {
	root = insert_util(root, str, 0);
}
bool Ternary::search_util(Node *curr, std::string str, int pos) {
	if(!curr)
		return false;
	if(str[pos] < curr->data)
		return search_util(curr->left, str, pos);
	else if(str[pos] > curr->data)
		return search_util(curr->right, str, pos);
	else if(str[pos + 1])
		return search_util(curr->mid, str, pos + 1);
	return curr->is_eof_word;
}
bool Ternary::search(std::string str) {
	return search_util(root, str, 0);
}
bool Ternary::remove_util(Node *curr, std::string str, int pos) {
	if(!curr)
		return false;
	if(str[pos] < curr->data) {
		if(remove_util(curr->left, str, pos)) {
			delete curr->left;
			curr->left = nullptr;
			return !curr->is_eof_word && !curr->left && !curr->mid && !curr->right;
		}
	}
	else if(str[pos] > curr->data) {
		if(remove_util(curr->right, str, pos)) {
			delete curr->right;
			curr->right = nullptr;
			return !curr->is_eof_word && !curr->left && !curr->mid && !curr->right;
		}
	}
	else {
		if(!str[pos + 1]) {
			bool temp = curr->is_eof_word;
			curr->is_eof_word = false;
			return temp && !curr->left && !curr->mid && !curr->right;
		}
		if(remove_util(curr->mid, str, pos + 1)) {
			delete curr->mid;
			curr->mid = nullptr;
			return !curr->is_eof_word && !curr->left && !curr->mid && !curr->right;
		}
	}
	return false;
}
bool Ternary::remove(std::string str) {
	remove_util(root, str, 0);
}
int main() {
	Ternary ternary;
	std::string str;
	int str_num;
	std::cin >> str_num;
	for(int i = 0; i < str_num; ++i) {
		std::cin >> str;
		ternary.insert(str);
	}
	int test_num;
	std::cin >> test_num;
	for(int i = 0; i < test_num; ++i) {
		std::cin >> str;
		ternary.remove(str);
	}
	int test2_num;
	std::cin >> test2_num;
	for(int i = 0; i < test2_num; ++i) {
		std::cin >> str;
		std::cout << ternary.search(str) << std::endl;
	}
	return 0;
}
