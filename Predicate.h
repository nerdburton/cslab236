#ifndef PREDICATE_H
#define PREDICATE_H

#include <iostream>
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate
{
public:
	vector<Parameter> data;
	 
	Predicate();
	~Predicate();

	void insert_value(Parameter value);
	string tostring();
};

#endif
