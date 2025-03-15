#include "main.hpp"

int main(int argc, char **argv) {

	const int emit = isEmitter();

	if (emit) {
		if (argc < 2) {
			std::cerr << "No message provided" << std::endl;
			return 1;
		}
		emitMessage(argv[1]);
	} else {
		listenForMessage();
	}

	return 0;
}
