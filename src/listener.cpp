#include "listener.hpp"

void listenForMessage()
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); // Surveille stdin

    // structure timeval permettant de configurer le timeout de select
    // tv_sec secondes d'attente
    // tv_usec ms d'attente

    // ici on veut que select ne bloque pas, donc on met le timeout à 0
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    //  select surveille les fd et detecte les changements
    //  1 le plus grand descripteur à surveiller + 1.
    //  on veut surveiller le stin donc STDIN_FILENO + 1.
    //  2 surveiller en lecture donc on passe le descripteur de fichier à
    //  surveiller 3 surveille en écriture non utilisé ici, donc nullptr 4
    //  surveille les erreurs spécifiques non utilisé ici, donc nullptr 5 le
    //  timeout
    int ret = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);

    const int pid = getpid();
    const std::string id = "PID: " + std::to_string(pid) + "  |  ";

    if (ret < 0)
    {
	perror("select");
	return;
    }

    if (ret == 0 || !FD_ISSET(STDIN_FILENO, &fds))
    {
	return;
    }

    char buffer[1024];
    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytesRead <= 0)
    {
	return;
    }
    buffer[bytesRead] = '\0';
    std::string message(buffer);
    if (message == "ERROR")
    {
	std::cerr << "An error occurred" << std::endl;
	return;
    }

    std::cerr << id << "Received message: " << message << std::endl;
}