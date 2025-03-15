#include "utils.hpp"

int isEmitter() {
	return (isatty(STDIN_FILENO) && !isatty(STDOUT_FILENO)) ? 1 : 0;
}
