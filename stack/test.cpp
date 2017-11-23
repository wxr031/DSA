#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	string::size_type sz;
	for (char c: str) {
		if (isdigit(c)) {
			int num = stoi(str, &sz);
			cout << num << endl;
		}
		str = str.substr(sz);
	}
	return 0;
}
