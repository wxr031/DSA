#include <iostream>
class A;
class B;

class A {
public:
	int Aint;
	B bdata;
	A() {
		Aint = 8;
		bdata();
	}
	friend class B;
};
class B {
public:
	int Bint;
	A adata;
	B() {
		Bint = 7;
		adata();
	}
	friend class A;
};
int main() {
	A a;
	B b;
	std::cout << a.Aint << b.Bint << std::endl;
	return 0;
}

