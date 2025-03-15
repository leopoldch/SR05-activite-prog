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

    const bool emit = isEmitter();

    if (debug)
    {
	std::cerr << "Debug mode enabled" << std::endl;
    }

    if (emit)
    {
	if (message.empty())
	{
	    std::cerr << "No message provided" << std::endl;
	    return 1;
	}
	emitMessage(message, debug);
    }
    else
    {
	listenForMessage(debug);
    }

    return 0;
}
