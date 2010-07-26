#pragma once
#ifndef INVALIDSTATEEXCEPTION_H_
#define INVALIDSTATEEXCEPTION_H_

#include <string>

class InvalidStateException {
public:
	InvalidStateException(const std::string &message);
	virtual ~InvalidStateException();

	const std::string message;
};

#endif
