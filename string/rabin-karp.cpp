#include <iostream>
#include <string>
constexpr int char_num = 37;
bool is_substr(std::string mainstr, std::string substr, int prime) {
	int mlen = mainstr.length(), slen = substr.length();
	int mhash = 0, shash = 0;
	int first_pow = 1;
	for(int i = 0; i < slen;) {
		mhash = (mhash * char_num + mainstr[i]) % prime;
		shash = (shash * char_num + substr[i]) % prime;
		if(++i == slen) break;
		first_pow = (first_pow * char_num) % prime;
	}
	std::cout << mhash << " " << shash << std::endl;
	int end = mlen - slen;
	for(int i = 0; i <= end; ++i) {
		if(mhash == shash) {
			int flag = true;
			for(int j = 0; j < slen && flag; ++j)
				if(mainstr[i + j] != substr[j])
					flag = false;
			if(flag)
				return true;
		}
		if(i < end)
			mhash = ((mhash - mainstr[i] * first_pow) * char_num + mainstr[i + slen]) % prime;
		if(mhash < 0)
			mhash += prime;
	}
	return false;
}
int main() {
	std::string str, substr;
	std::cin >> str >> substr;
	std::cout << is_substr(str, substr, 7) << std::endl;
	return 0;
}
