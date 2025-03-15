#include "listener.hpp"

using namespace std;

void listenForMessage() {
	asio::io_context			   io;
	asio::posix::stream_descriptor inputStream(io, ::dup(STDIN_FILENO));

	vector<char> buffer(1024);

	// fonction asynchrone de lecture lorsqu'une donnée est déposée sur le fd
	function<void()> asyncRead;
	asyncRead = [&]() -> void {
		inputStream.async_read_some(
			asio::buffer(buffer),
			[&](const asio::error_code &ec, size_t bytes_transferred) {
				if (!ec) {
					string data(buffer.begin(),
								buffer.begin() + bytes_transferred);
					string errorMsg	  = "ERROR";
					string defaultMsg = "DEFAULT_MESSAGE";

					if (data.find(errorMsg) != string::npos) {
						cerr << defaultMsg << endl;
						return;
					}

					cout << "Received: " << data << endl;
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
