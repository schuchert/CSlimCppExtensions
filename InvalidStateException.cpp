#include "InvalidStateException.h"

InvalidStateException::InvalidStateException(const std::string &message) : message(message) {
}

InvalidStateException::~InvalidStateException() {
}
