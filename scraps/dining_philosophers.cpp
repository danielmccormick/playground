#include <thread>
#include <mutex>
#include <iostream> 
#include <string>
#include <vector> 
#include <chrono>
#include <memory>

int firstSet;
int secondSet;

std::mutex firstMutex;
std::mutex secondMutex;

class philosopher {
	std::string name; 
	std::thread consume;
	philosopher() = delete;
	philosopher(std::string name_) { name = name_;}
	~philosopher() {consume.join();}
	void eat () {
		std::cout << name << " is eating ... ";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << " ... done\n";
		return;
	} 

	void dine() {
		if (firstSet > secondSet) {
			secondSet++;
			{
				std::lock_guard<std::mutex> guard(secondMutex);
				eat();	
			}
		} else {
			firstSet++;
			{
				std::lock_guard<std::mutex> guard(firstMutex);
				eat();
			}
		}
		return;
	} 
};

int main() {
	firstSet = 0;
	secondSet = 0;
	std::vector<std::string> philosophers =  {"Marx", "Nietzsche", "Kant", "Calvin", "Hobbes"};
	std::array<5, std::unique_ptr<philosopher> philosopher_handles;
	for (auto i = 0; i < 5; i++) {
		philosopher_handles[i] = std::make_unique<philosopher>(philosophers[i]);
		philosopher_handles[i]->dine();
	}	

	return 0;
}
