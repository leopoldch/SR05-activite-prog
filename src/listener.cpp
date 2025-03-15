#include "listener.hpp"

using namespace std;

void listenForMessage(const bool debug)
{
    asio::io_context io;
    asio::posix::stream_descriptor inputStream(io, ::dup(STDIN_FILENO));

    vector<char> buffer(1024);

    // fonction asynchrone de lecture lorsqu'une donnée est déposée sur le fd
    function<void()> asyncRead;
    asyncRead = [&]() -> void
    {
	if (debug)
	{
	    for (int i = 0; i < 15; i++)
	    {
		std::cerr << "." << std::endl;
		sleep(5);
	    }
	}
	inputStream.async_read_some(
	    asio::buffer(buffer),
	    [&](const asio::error_code& ec, size_t bytes_transferred)
	    {
		if (!ec)
		{
		    string data(buffer.begin(),
				buffer.begin() + bytes_transferred);

		    if (data.find(ERROR) != string::npos)
		    {
			cerr << ERROR << endl;
			return;
		    }
		    const int pid = getpid();
		    cerr << "Received on listener: " << pid << " data :" << data
			 << endl;
		    cout << data << endl;
		    // une donnée a été lue alors on rappelle la fonction de
		    // lecture pour lire la prochaine donnée lorsqu'elle sera
		    // déposée
		    asyncRead();
		}
	    });
    };

    asyncRead();

    thread ioThread([&io]() { io.run(); });
    ioThread.join(); // Bloque le thread principal jusqu'à la fin des lectures
}
