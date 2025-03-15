#include "utils.hpp"

bool isEmitter()
{
    return (isatty(STDIN_FILENO) && !isatty(STDOUT_FILENO)) ? 1 : 0;
}
