/*
 *
 * fixDatalog was created with the intended use of removing unimportant tokens from the datalog database
 *it needs to remove all information except for parameters
 *eg SK(A,B)
 *	keeps SK id, A parameter and B parameter
 *
 *eg SK((A+B),B)
 *	keeps SK id, (A+B) parameter and B parameter
 *
 *
 */

#include <iostream>
#include "datalogProgram.h"
using namespace std;

class fixDatalog
{
public:
	datalogProgram database;

	fixDatalog(datalogProgram d);
	~fixDatalog();

	

};
