#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::string recoverBurrows(int R, const std::string &col) {
	std::string perm = col;
	std::sort(perm.begin(),perm.end());
	std::vector<std::string> list(perm.size());
	std::vector<std::string> tmpList(perm.size());
	for (int i = 0; i < col.size(); i++) {
		list[i] += perm[i];
		list[i] += col[i];
	}
	std::sort(list.begin(),list.end()); // Now have two columns in order - can the rest be done?
	
	while(1) {
		for (int i = 0; i < col.size(); i++) {
			tmpList[i] += col[i];
			tmpList[i] += list[i];
			list[i] = tmpList[i];
			tmpList[i].clear();
		}
		std::sort(list.begin(),list.end());
		if(list[0].size() == col.size()) {
			return list[R-1];
		}
		std::cout << "List Size: " << list[0].size() << "\n";	
	}
	return "";
}

int main() {
	int R;
	std::string col;
	std::string junk;
	while(1) {
		std::getline(std::cin, junk);
		if(junk == "0" || junk.empty()) return 0;
		R = std::stoi(junk);
		junk.clear();
		std::getline(std::cin, col);
		std::cout << recoverBurrows(R,col);
	}

	return 0;
}
