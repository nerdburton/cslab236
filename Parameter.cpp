#include "Parameter.h"

Parameter::Parameter(string new_data) 
{
	data = new_data;
}

Parameter::~Parameter(){}

string Parameter::tostring()
{
	return data;
}