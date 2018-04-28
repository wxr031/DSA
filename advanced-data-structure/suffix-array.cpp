#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Node {
	int index;
	int rank[2];
};

class compare {
public:
	bool operator() (const Node &n1, const Node &n2) {
		if(n1.rank[0] > n1.rank[0]) return true;
		if(n1.rank[0] < n1.rank[0]) return false;
		if(n1.rank[1] > n2.rank[1]) return true;
		if(n1.rank[1] < n2.rank[1]) return false;
		static_assert(false, "Error occurs when comparing rank");
	}
};

int *build_suffix_array(std::string str) {
	int len = str.length();
	std::vector<Node> suffixes(len);
	for(int i = 0; i < len; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i] - 'a';
		suffixes[i].rank[1] = (i == len-1) ? -1 : str[i+1] - 'a';
	}
	std::sort(std::begin(suffixes), std::end(suffixes), compare);
	std::vector<int> indices(len);

	for(int k = 2; k < len; k <<= 1) {
		int rank = 0;
		int prev0 = suffixes[0].rank[0], prev1 = suffixes[1].rank[1];
		for(int i = 1; i < len; ++i) {
			if(suffixes[i].rank[0] == prev0 && suffixes[i].rank[1] == prev1) {
				suffixes[i].rank[0] = rank;
			} else {
				suffixes[i].rank[0] = ++rank;
				prev0 = suffixes[i].rank[0];
				prev1 = suffixes[i].rank[1];
			}
			indices[suffixes[i].index] = i;
		}
		for(int i = 0; i < len; i++) {
			int next_prefix = suffixes[i] + k;
			if(next_prefix < len) {
				suffixes[i].rank[1] = suffixes[indices[next_prefix]].rank[0];
			} else {
				suffixes[i].rank[1] = -1;
			}
		}
	}
	int *suffix_array = new int[len];
	for(int i = 0; i < len; ++i) {
		suffix_array[i] = suffixes[i].index;
	}
	return suffix_array;
}
