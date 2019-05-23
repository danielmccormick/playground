#include <unordered_map>
#include <set>
#include <iostream>
#include <string>


void recoverBurrows(int R, std::string col) {
	std::cout << "Called with: " << col << "and permutation " << R;
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
