#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
struct compare {
	bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
		if(p1.second > p2.second)
			return true;
		if(p1.second < p2.second)
			return false;
		if(p1.first < p2.first)
			return true;
		return false;
	}
} mcompare;
int main() {
	int test_num;
	cin >> test_num;
	while(test_num--) {
		int ele_num;
		cin >> ele_num;
		map<int, int> table;
		vector<pair<int, int> > array;
		for(int i = 0; i < ele_num; ++i) {
			int val;
			cin >> val;
			map<int, int>::iterator mit;
			if((mit = table.find(val)) == table.end())
				table[val] = 1;
			else
				++(mit->second);
		}
		for(map<int, int>::iterator mit = table.begin();
				mit != table.end(); ++mit) {
			array.push_back(*mit);
		}
		sort(array.begin(), array.end(), mcompare);
		for(vector<pair<int, int> >::iterator vit = array.begin();
				vit != array.end(); ++vit) {
			for(int i = 0; i < vit->second; ++i) {
				cout << vit->first << endl;
			}
		}
	}
	return 0;
}
