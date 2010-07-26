#include "QueryResultAccumulator.h"
#include "DifferentFieldCountsInObjects.h"
#include "InvalidStateException.h"

extern "C" {
#include "SlimList.h"
#include "SlimListSerializer.h"
}

QueryResultAccumulator::QueryResultAccumulator() : result(0) {
	setInitialConditions();
}

QueryResultAccumulator::~QueryResultAccumulator() {
	releaseAll();
	SlimList_Release(result);
}

void QueryResultAccumulator::setInitialConditions() {
	releaseAll();
	list = allocate();
	currentObject = allocate();
	lastFieldCount = -1;
	currentFieldCount = -1;
}

SlimList* QueryResultAccumulator::allocate() {
	SlimList *list = SlimList_Create();
	created.push_back(list);
	return list;
}

void QueryResultAccumulator::releaseAll() {
	for (iterator i = created.begin(); i != created.end(); ++i)
		SlimList_Destroy(*i);
	created.clear();
}

void QueryResultAccumulator::finishCurrentObject() {
	if(lastFieldCount >= 0 && lastFieldCount != currentFieldCount)
		throw DifferentFieldCountsInObjects(lastFieldCount, currentFieldCount);

	SlimList_AddList(list, currentObject);
	currentObject = allocate();

	lastFieldCount = currentFieldCount;
	currentFieldCount = -1;
}

void QueryResultAccumulator::addFieldNamedWithValue(const std::string &name, const std::string &value) {
	SlimList *fieldList = allocate();
	SlimList_AddString(fieldList, name.c_str());
	SlimList_AddString(fieldList, value.c_str());
	SlimList_AddList(currentObject, fieldList);
	++currentFieldCount;
}

char* QueryResultAccumulator::produceFinalResults() {
	if(currentFieldCount != -1)
		throw InvalidStateException("Current object not written");

	SlimList_Release(result);
	result = SlimList_Serialize(list);
	setInitialConditions();
	return result;
}
