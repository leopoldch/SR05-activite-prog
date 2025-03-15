#include "emitter.hpp"

void emitMessage(const std::string &message) {
	const pid_t pid = getpid();
	std::cerr << "Emitter PID: " << pid << std::endl;

	std::string newMessage = message + " " + std::to_string(pid);
	while (true) {
		if (write(STDOUT_FILENO, newMessage.c_str(), newMessage.size()) == -1) {
			std::cerr << "An error occurred" << std::endl;
			write(STDOUT_FILENO, ERROR, sizeof(ERROR));
			return;
		}
		write(STDOUT_FILENO, "\n", 1);
		sleep(1);
	}
}
