#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
class disjoint_set {
	int num;
	std::vector<int> parent, rank;
public:
	disjoint_set(int);
	int find_set(int);
	void union_set(int, int);
};
disjoint_set::disjoint_set(int val) {
	num = val;
	for(int i = 0; i < val; ++i) {
		parent.push_back(i);
		rank.push_back(0);
	}
}
int disjoint_set::find_set(int id) {
	if(parent[id] == id)
		return id;
	return parent[id] = find_set(parent[id]);
}
void disjoint_set::union_set(int id1, int id2) {
	int par1 = find_set(id1);
	int par2 = find_set(id2);
	if(par1 != par2) {
		if(rank[par1] > rank[par2])
			parent[par2] = par1;
		else if(rank[par1] < rank[par2])
			parent[par1] = par2;
		else {
			parent[par1] = par2;
			++rank[par2];
		}
	}
}
int get_max() {

}
struct compare {
	/* sort the vector according to profit in decreasing order */
	/* if the profit are the same, sort the vector according to 
		deadline in decreaing order*/ 
	bool operator() (std::tuple<int, int, int> p1, std::tuple<int, int, int> p2) {
		if(std::get<2>(p1) > std::get<2>(p1))
			return true;
		if(std::get<2>(p1) < std::get<2>(p1))
			return false;
		return std::get<1>(p1) > std::get<1>(p2);
	}
} compare;
int main() {
	int test_num;
	std::cin >> test_num;
	while(test_num--) {
		int num;
		std::cin >> num;
		std::vector<std::tuple<int, int, int> > schedule;
		for(int i = 0; i < num; ++i) {
			int id, deadline, profit;
			std::cin >> id >> deadline >> profit;
			schedule[id] = std::make_tuple(id, deadline, profit);
		}
		std::sort(schedule.begin(), schedule.end(), compare);
#ifdef DEBUG
		for(int i = 0; i < num; ++i)
			std::cout << std::get<0>(schedule) << " " << std::get<0>(schedule) << " "
				<< std::get<2>(schedule) << std::endl;
#endif
		/* Find the maximum deadline among all jobs.
			create a disjoint set data structure with
			maxDeadline disjoint sets initially. */
		int max_deadline = get_max();
		disjoint_set set(num);
		std::Vector<int> result;
		for(int i = 0; i < num; ++i) {
			int available = find(schedule[i].first);
			if(available > 0) {
				result.push_back()
			}
		}
	}
	return 0;
}
