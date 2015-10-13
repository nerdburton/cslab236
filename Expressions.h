#include "Parameter.h"
#include <iostream>
#include <string>

using namespace std;

class Expressions
{
public:
	string data;

	Expressions(Parameter a, string op, Parameter b); 
	~Expressions();

	string tostring();
};