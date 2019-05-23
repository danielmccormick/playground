#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::string recoverBurrows(int R, const std::string &col) {
	std::vector<std::string> list(col.size());
	std::vector<std::string> tmpList(col.size());
	for (int i = 0; i < col.size(); i++) {
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
	}
	return "";
}

int main() {
	std::string col;
	std::string R;
	while(1) {
		std::getline(std::cin, R);
		if(junk == "0" || R.empty()) return 0;
		std::getline(std::cin, col);
		std::cout << recoverBurrows(std::stoi(R),col) << "\n";
	}

	return 0;
}
