#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool KMP(string mainstr, string substr) {
	int i = 0, j = 1;
	int slen = substr.length(), mlen = mainstr.length();
	vector<int> prefix_table(slen);
	prefix_table[0] = 0;
	while(j != slen) {
		if(substr[i] == substr[j]) {
			prefix_table[j] = i + 1;
			++i;
			++j;
		}
		else if(i > 0)
			i = prefix_table[i - 1];
		else {
			prefix_table[j] = 0;
			++j;
		}
	}
	i = 0, j = 0;
	while(j != mlen) {
		if(substr[i] == mainstr[j]) {
			++i;
			++j;
			if(i == slen)
				return true;
		}
		else if(i > 0)
			i = prefix_table[i - 1];
		else ++j;
	}
	return false;
}
int main() {
	string mainstr, substr;
	cin >> mainstr >> substr;
	cout << KMP(mainstr, substr);
	return 0;
}
