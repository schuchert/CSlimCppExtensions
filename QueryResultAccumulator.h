#pragma once
#ifndef QUERYRESULTACCUMULATOR_H_
#define QUERYRESULTACCUMULATOR_H_

class SlimList;
#include <vector>
#include <string>
class QueryResultAccumulator {
public:
	typedef std::vector<SlimList*> v_SlimList;
	typedef v_SlimList::iterator iterator;

	QueryResultAccumulator();
	virtual ~QueryResultAccumulator();

	void finishCurrentObject();
	void addFieldNamedWithValue(const std::string &name, const std::string &value);
	char *produceFinalResults();

private:
	SlimList* allocate();
	void releaseAll();
	void setInitialConditions();

private:
	v_SlimList created;
	SlimList *list;
	SlimList *currentObject;
	int lastFieldCount;
	int currentFieldCount;
	char *result;

private:
	QueryResultAccumulator(const QueryResultAccumulator&);
	QueryResultAccumulator& operator=(const QueryResultAccumulator&);
};

#endif
