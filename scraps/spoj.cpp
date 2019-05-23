#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

void recoverBurrows(int R, std::string col) {
	std::string perm = col;
	std::sort(perm.begin(),perm.end());
	std::vector<std::string> list(perm.size());
	for (int i = 0; i < col.size(); i++) {
		list[i] += perm[i];
		list[i] += col[i];
	}
	std::sort(list.begin(),list.end()); // Now have two columns in order - can the rest be done?
	for (std::string s : list) {
		std::cout << "Possible match: " << s << "\n";
	}
	//std::cout << "Called with: " << col << " and permutation " << R << "\n";

	
	return;
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
		recoverBurrows(R,col);
	}

	return 0;
}
