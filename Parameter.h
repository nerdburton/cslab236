#ifndef PARAMETER_H
#define PARAMETER_H

#include <iostream>
#include "Token.h"

using namespace std;

class Parameter
{
public:
	string data;

	Parameter(string new_data); 
	~Parameter();

	string tostring();
};

#endif
