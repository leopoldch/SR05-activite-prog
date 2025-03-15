#include "emitter.hpp"

void emitMessage(const std::string& message, const bool debug)
{
    const pid_t pid = getpid();
    std::cerr << "Emitter PID: " << pid << std::endl;

    std::string newMessage = message;
    while (true)
    {
	if (write(STDOUT_FILENO, newMessage.c_str(), newMessage.size()) == -1)
	{
	    std::cerr << "An error occurred" << std::endl;
	    write(STDOUT_FILENO, ERROR, sizeof(ERROR));
	    return;
	}
	sleep(1);
	if (debug)
	{
	    for (int i = 0; i < 15; i++)
	    {
		std::cerr << "." << std::endl;
		sleep(5);
	    }
	}
    }
}
