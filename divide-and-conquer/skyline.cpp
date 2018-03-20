#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<int,int,int> > data;

std::vector<std::pair<int,int> > result;

std::vector<std::pair<int,int> > merge(std::vector<std::pair<int,int> > start,
		std::vector<std::pair<int,int> > finish) {
	std::vector<std::pair<int,int> > result;
	std::vector<int>::iterator its = start.begin(), itf = finish.begin();
	int rems = 0, remf = 0;
	while(its != start.end() && itf != finish.end()) {
		if(its->first > itf->first) {
			remf = itf->second;
			if(rems <= remf && remf != result.end()->second) {
				result.push_back(std::make_pair(itf->first, remf));
			} else if(rems > remf && rems != result.end()->second) {
				result.push_back(std::make_pair(itf->first, rems));
			}
			++itf;
		} else if(its->first < itf->first) {
			rems = its->second;
			if(rems <= remf && remf != result.end()->second) {
				result.push_back(std::make_pair(its->first, remf));
			} else if(rems > remf && rems != result.end()->second) {
				result.push_back(std::make_pair(its->first, rems));
			}
			++its;
		} else {
			remf = itf->second;
			rems = its->second;
			if(rems <= remf) {
				result.push_back(std::make_pair(its->first, remf));
			} else if(rems > remf && rems != result.end()->second) {
				result.push_back(std::make_pair(its->first, rems));
			}
			++its;
			++itf;
		}
	}
	while(its != start.end()) {
		rems = its->second;
		if(rems <= remf && remf != result.end()->second) {
			result.push_back(std::make_pair(its->first, remf));
		} else if(rems > remf && rems != result.end()->second) {
			result.push_back(std::make_pair(its->first, rems));
		}
		++its;
	}
	while(itf != start.end()) {
		remf = itf->second;
		if(rems <= remf && remf != result.end()->second) {
			result.push_back(std::make_pair(itf->first, remf));
		} else if(rems > remf && rems != result.end()->second) {
			result.push_back(std::make_pair(itf->first, rems));
		}
	}
	return result;
}
void div_and_conq(int start, int end) {
	if(start == end) {
		std::vector<std::pair<int,int> >result;
		result.push_back(std::make_pair(data[0], data[1]));
		result.push_back(std::make_pair(data[2], 0));
		return result;
	}
	int mid = start + (end - start) >> 1;
	std::vector<std::pair<int,int> > left = div_and_conq(start, mid);
	std::vector<std::pair<int,int> > right = div_and_conq(mid + 1, finish);
	return merge(left, right);
}
int main() {
	int start, finish, height;
	while(std::cin >> start >> finish >> height) {
		data.push_back(std::make_tuple(start, finish, height));
	}
	std::vector<std::pair<int,int> > result = div_and_conq();
	return 0;
}
