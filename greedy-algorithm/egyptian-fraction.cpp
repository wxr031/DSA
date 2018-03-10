#include <iostream>
int GCD(int n1, int n2) {
	if(n2 == 0) return n1;
	return GCD(n2, n1 % n2);
}
void reduce(int &nr, int &dr) {
	int gcd = GCD(nr, dr);
	nr /= gcd;
	dr /= gcd;
}
void egyptian_fraction(int nr, int dr) {
	if(nr >= dr) {
		std::cout << nr/dr;
		if(nr % dr) {
			std::cout << " + ";
			egyptian_fraction(nr % dr, dr);
		}
		else {
			std::cout << "\n";
		}
		return;
	}
	int test = 2;
	reduce(nr, dr);
	std::cout << "1/";
	while(nr != 1) {
		while(nr * test < dr)
			++test;
		std::cout << test << " + ";
		nr = nr * test - dr;
		dr *= test;
		reduce(nr, dr);
		std::cout << "1/";
	}
	std::cout << dr << std::endl;
}
int main() {
	int nr, dr;
	std::cin >> nr >> dr;
	try {
		if(dr == 0)
			throw "Divisor cannot be zero";
	}
	catch(const char *error_message) {
		std::cout << error_message << std::endl;
		exit(1);
	}
	egyptian_fraction(nr, dr);
	return 0;
}
