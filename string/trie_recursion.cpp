#include <iostream>
#include <cctype>
constexpr int char_size = 26;
struct Node {
	bool is_end_of_word;
	int word_num;
	Node *child[char_size];
	Node(): is_end_of_word(false), word_num(0) {
		for(int i = 0; i < char_size; ++i)
			child[i] = nullptr;
	}
};
class Trie {
	Node *root;
	void insert_util(std::string, Node *, int, int);
	bool search_util(std::string, Node *, int, int);
	bool remove_util(std::string, Node *, int, int);
public:
	Trie() {
		root = new Node;
	}
	void insert(std::string);
	bool search(std::string);
	bool remove(std::string);
};
void Trie::insert_util(std::string str, Node *curr, int pos, int len) {
	if(pos == len) {
		curr->is_end_of_word = true;
		std::cout << "finish" << std::endl;
		return;
	}
	int cpos = str[pos] - 'a';
	if(!curr->child[cpos])
		curr->child[cpos] = new Node;
	++curr->word_num;
	insert_util(str, curr->child[cpos], pos + 1, len);
}
void Trie::insert(std::string str) {
	insert_util(str, root, 0, str.length());
}
bool Trie::search_util(std::string str, Node *curr, int pos, int len) {
	if(pos == len)
		return curr->is_end_of_word;
	int cpos = str[pos] - 'a';
	if(!curr->child[cpos])
		return false;
	return search_util(str, curr->child[cpos], pos + 1, len);
}
bool Trie::search(std::string str) {
	return search_util(str, root, 0, str.length());
}
bool Trie::remove_util(std::string str, Node *curr, int pos, int len) {
	if(pos == len) {
		bool temp = curr->is_end_of_word;
		curr->is_end_of_word = false;
		return temp && curr->word_num == 0;
	}
	int cpos = str[pos] - 'a';
	if(!curr->child[cpos])
		return false;
	if(remove_util(str, curr->child[cpos], pos + 1, len)) {
		delete curr->child[cpos];
		curr->child[cpos] = nullptr;
		return !curr->is_end_of_word && --curr->word_num == 0;
	}
	return false;
}
bool Trie::remove(std::string str) {
	return remove_util(str, root, 0, str.length());
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
		trie.remove(str);
	}
	int test2_num;
	std::cin >> test2_num;
	for(int i = 0; i < test2_num; ++i) {
		std::cin >> str;
		std::cout << trie.search(str) << std::endl;
	}
	return 0;
}
