#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

std::vector<std::tuple<int,int,int> > data;

std::vector<std::pair<int,int> > merge(std::vector<std::pair<int,int> > start,
		std::vector<std::pair<int,int> > finish) {
	std::vector<std::pair<int,int> > result;
	std::vector<std::pair<int,int> >::iterator its = start.begin(), itf = finish.begin();
	int rems = 0, remf = 0;
	while(its != start.end() && itf != finish.end()) {
#ifdef DEBUGGING
		std::cout << (*its).first << "," << (*its).second << "   "
			<< (*itf).first << "," << (*itf).second << std::endl;
#endif
		if(its->first > itf->first) {
			remf = itf->second;
			if(rems <= remf && (result.empty() || remf != (result.end()-1)->second)) {
				result.push_back(std::make_pair(itf->first, remf));
			} else if(rems > remf && (result.empty() || rems != (result.end()-1)->second)) {
				result.push_back(std::make_pair(itf->first, rems));
			}
			++itf;
		} else if(its->first < itf->first) {
			rems = its->second;
			if(rems <= remf && (result.empty() || remf != (result.end()-1)->second)) {
				result.push_back(std::make_pair(its->first, remf));
			} else if(rems > remf && (result.empty() || rems != (result.end()-1)->second)) {
				result.push_back(std::make_pair(its->first, rems));
			}
			++its;
		} else {
			remf = itf->second;
			rems = its->second;
			if(rems <= remf && (result.empty() || remf != (result.end()-1)->second)) {
				result.push_back(std::make_pair(its->first, remf));
			} else if(rems > remf && (result.empty() || rems != (result.end()-1)->second)) {
				result.push_back(std::make_pair(its->first, rems));
			}
			++its;
			++itf;
		}
	}
#ifdef DEBUGGING
		std::cout << "--------\n";
#endif
	while(its != start.end()) {
		rems = its->second;
		if(rems <= remf && (result.empty() || remf != (result.end()-1)->second)) {
			result.push_back(std::make_pair(its->first, remf));
		} else if(rems > remf && (result.empty() || rems != (result.end()-1)->second)) {
			result.push_back(std::make_pair(its->first, rems));
		}
		++its;
	}
	while(itf != finish.end()) {
		remf = itf->second;
		if(rems <= remf && remf != (result.end()-1)->second) {
			result.push_back(std::make_pair(itf->first, remf));
		} else if(rems > remf && rems != (result.end()-1)->second) {
			result.push_back(std::make_pair(itf->first, rems));
		}
		++itf;
	}
#ifdef RESULT
	std::cout << "\n\nooooooooooooooooo\n\n";
	for(auto p : result) {
		std::cout << p.first << " " << p.second << std::endl;
	}

	std::cout << "\n\nooooooooooooooooo\n\n";
#endif
	return result;
}
std::vector<std::pair<int,int> > div_and_conq(int start, int finish) {
	if(start == finish) {
		std::vector<std::pair<int,int> > result;
		result.push_back(std::make_pair(std::get<0>(data[start]), std::get<1>(data[start])));
		result.push_back(std::make_pair(std::get<2>(data[start]), 0));
		return result;
	}
	int mid = start + ((finish - start) >> 1);
	std::vector<std::pair<int,int> > left = div_and_conq(start, mid);
	std::vector<std::pair<int,int> > right = div_and_conq(mid + 1, finish);
#ifdef DEBUG
	for(auto p : left) {
		std::cout << p.first << " " << p.second << std::endl;
	}
	std::cout << "\n\n";
	for(auto p : right) {
		std::cout << p.first << " " << p.second << std::endl;
	}
#endif
	return merge(left, right);
}
int main() {
	int start, finish, height;
	int cnt = 0;
	while(std::cin >> start >> height >> finish) {
		data.push_back(std::make_tuple(start, height, finish));
		++cnt;
	}
	std::vector<std::pair<int,int> > result = div_and_conq(0, cnt - 1);
	for(auto pair : result) {
		std::cout << pair.first << " " << pair.second << " \n"[pair == *(result.end() - 1)];
	}
	return 0;
}
