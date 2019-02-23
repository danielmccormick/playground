#pragma once
#include <unordered_map>

namespace playground {

template <typename S, typename T>
class bidirectional_map {
public: 

	// no default construction
	bidirectional_map() = delete;

	// empty type
	bidirectional_map(std::pair<S, T>);

	bidirectional_map(bidirectional_map &&);
	bidirectional_map& operator=(bidirectional_map&& other)

	bidirectional_map(const bidirectional_map &) = default;
	~bidirectional_map();

	auto sbegin();
	auto send();
	auto tbegin();
	auto tend();

	bool empty;
	size_t size(); // To improve implementation must return size_type
	size_t max_size();

	void clear();

	void insert(std::pair<T, S>);
	void insert(std::pair<S, T>);
	
	void erase(void *); // fix this type later
	void erase(S);
	void erase(T);

	int count(S);
	int count(T);
	bool contains(S);
	bool contains(T);

	bool operator!=(const bidirectional_map &);
	bool operator==(const bidirectional_map &);

	friend void swap(bidirectional_map &A, bidirectional_map &B);

private:
	std::unique_ptr<std::unordered_map<S, T>> forwards;
	std::unique_ptr<std::unordered_map<T, S>> backwards;

};




}