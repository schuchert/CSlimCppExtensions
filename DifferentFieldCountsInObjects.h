#pragma once
#ifndef DIFFERENTFIELDCOUNTSINOBJECTS_H_
#define DIFFERENTFIELDCOUNTSINOBJECTS_H_

class DifferentFieldCountsInObjects {
public:
	DifferentFieldCountsInObjects(int lastCount, int currentCount);
	virtual ~DifferentFieldCountsInObjects();

	const int lastCount;
	const int currentCount;
};

#endif
