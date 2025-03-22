#include "listener.hpp"

void listenForMessage()
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    int ret = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);

    if (ret > 0 && FD_ISSET(STDIN_FILENO, &fds))
    {
		std::string message;
		char buffer[1024];

		ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		if (bytesRead > 0)
		{
			// éviter les fuites de mémoire
			buffer[bytesRead] = '\0';
			message.append(buffer, bytesRead);
		}

		if (message == "ERROR")
		{
			std::cerr << "An error occurred" << std::endl;
			return;
		}

		if (!message.empty())
		{
			std::cerr << "Received message: " << message << std::endl;
		}
		return;
    }
    if (ret < 0)
    {
		perror("select");
    }
}
