#include "SlimUtils.h"
#include <stdlib.h>
#include "SlimList.h"

const char* getStringAt(SlimList *args, int index) {
    return SlimList_GetStringAt(args, index);
}

const char* getFirstString(SlimList *args) {
    return getStringAt(args, 0);
}

int getIntAt(SlimList *args, int index) {
	return atoi(getStringAt(args, index));
}

int getFirstInt(SlimList* args) {
    return getIntAt(args, 0);
}
