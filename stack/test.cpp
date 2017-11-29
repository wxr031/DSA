#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	cout << (string::iterator) str.end() << endl;
	return 0;
}
