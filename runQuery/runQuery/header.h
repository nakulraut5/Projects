#include <tc/tc.h>
#include <tc/tc_startup.h>
#include <tccore/workspaceobject.h>
#include <qry\qry.h>
#include <emh.h>
#include<aom.h>
#include <aom_prop.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//namespaces
namespace utils{
	int report_error(int x);
	void cleanUpStrings(char** cValues, int count);
}