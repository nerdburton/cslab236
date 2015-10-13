#include "Predicate.h"

Predicate::Predicate(){}
Predicate::~Predicate(){}

void Predicate::insert_value(Parameter value)
{
	data.push_back(value); 
}

string Predicate::tostring()
{
	string str;
	for (int i = 0; i < data.size(); i++)
		str += data[i].tostring();
	return str;
}