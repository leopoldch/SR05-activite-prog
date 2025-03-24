#include "emitter.hpp"

void emitMessage(const std::string& message, const bool debug)
{
    const std::string new_message = message + "\n";

    if (write(STDOUT_FILENO, new_message.c_str(), new_message.size()) == -1)
    {
	std::cerr << "An error occurred" << std::endl;
	write(STDOUT_FILENO, ERROR, sizeof(ERROR));
	return;
    }
    if (debug)
    {
	for (int i = 0; i < 1000; ++i)
	{
	    std::cerr << "." << std::endl;
	}
    }
}
