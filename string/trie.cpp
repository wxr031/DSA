#include <iostream>
constexpr int char_size = 26;
struct Node {
	bool is_end_of_word;
	Node *child[char_size];
	Node(): is_end_of_word(false) {
		for(int i = 0; i < char_size; ++i)
			child[i] = nullptr;
	}
};
class Trie {
	Node *root;
public:
	Trie() {
		root = new Node;
	}
	void insert(std::string);
	bool search(std::string);
	void remove(std::string);
};
void Trie::insert(std::string str) {
	Node *curr = root;
	for(char c : str) {
		int pos = c - 'a';
		if(!curr->child[pos])
			curr->child[pos] = new Node;
		curr = curr->child[pos];
	}
	curr->is_end_of_word = true;
}
bool Trie::search(std::string str) {
	Node *curr = root;
	for(char c : str) {
		int pos = c - 'a';
		if(curr->child[pos])
			curr = curr->child[pos];
		else return false;
	}
	return curr->is_end_of_word;
}
int main() {
	Trie trie;
	std::string str;
	int str_num;
	std::cin >> str_num;
	for(int i = 0; i < str_num; ++i) {
		std::cin >> str;
		trie.insert(str);
	}
	int test_num;
	std::cin >> test_num;
	for(int i = 0; i < test_num; ++i) {
		std::cin >> str;
		std::cout << trie.search(str) << std::endl;
	}
	return 0;
}
