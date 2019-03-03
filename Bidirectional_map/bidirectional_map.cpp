#include "bidirectional_map".h

namespace playground {

	bidirectional_map::bidirectional_map(std::pair<S, T>) {
		forwards = std::make_unique<std::unordered_map<S, T>>;
		backwards = std::make_unique<std::unordered_map<T, S>>;
	}

	bidirectional_map::bidirectional_map(bidirectional_map &&other) {
		std::swap(forwards, other.forwards);
		std::swap(backwards, other.backwards);
	}

	// NEEDS FIXING
	bidirectional_map& operator=(bidirectional_map&& other) {
		bidirectional_map::return(other);
		return other; 
	}

	auto bidirectional_map::sbegin() { return forwards.begin() };
	auto bidirectional_map::send() { return forwards.end() };
	auto bidirectional_map::tbegin() { return backwards.begin() };
	auto bidirectional_map::tend() { return backwards.begin() };




}