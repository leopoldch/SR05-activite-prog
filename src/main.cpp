#include "main.hpp"

int main(int argc, char** argv)
{

    bool debug = false;

    std::string message = "";

    for (int i = 1; i < argc; ++i)
    {
	// verify if -d or --debug option is passed
	if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0)
	{
	    debug = true;
	    continue;
	}
	if (strncmp(argv[i], "message=", 8) == 0)
	{
	    message = argv[i] + 8;
	    continue;
	}
	if (strchr(argv[i], '-') == nullptr)
	{
	    message = argv[i];
	    continue;
	}
    }

    if (message == "")
    {
		message = DEFAULT_MESSAGE;
    }

    if (debug)
    {
		std::cerr << "Debug mode enabled" << std::endl;
		sleep(1);
    }

    while (true)
    {
		emitMessage(message, debug);
		sleep(1);
		listenForMessage();
    }

    return 0;
}
