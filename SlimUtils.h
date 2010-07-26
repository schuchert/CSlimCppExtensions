#pragma once
#ifndef SLIMUTILS_H_
#define SLIMUTILS_H_

struct SlimList;

const char* getStringAt(SlimList *args, int index);
const char* getFirstString(SlimList *args);
int getIntAt(SlimList *args, int index);
int getFirstInt(SlimList* args);

template<class T> T* Self(void *fixture) {
	return reinterpret_cast<T*>(fixture);
}

inline char *remove_const(const char *returnValue) {
	return const_cast<char*>(returnValue);
}

#endif
