#include "bidirectional_map".h

namespace playground {

	bidirectional_map::bidirectional_map(std::pair<S, T>) {
		forwards = std::make_unique<std::unordered_map<S, T>>;
		if (sizeof(S) != sizeof(T)) {
			backwards = std::make_unique<std::unordered_map<T, S>>;
		}
	}

	bidirectional_map::bidirectional_map(bidirectional_map &&other) {
		std::swap(forwards, other.forwards);
		std::swap(backwards, other.backwards);
	}

	bidirectional_map& operator=(bidirectional_map&& other) {
		bidirectional_map::return(other);
		return other; 
	}


}