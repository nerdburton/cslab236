#include "Predicate.h"

Predicate::Predicate(){}
Predicate::~Predicate(){}

void Predicate::insert_value(Parameter value)
{
	data.push_back(value); 
}

vector<Parameter> Predicate::getVec()
{
	return data;
}

void Predicate::editDat(vector<Parameter> vec)
{
	data = vec;
}

string Predicate::tostring()
{
	string str;
	for (int i = 0; i < data.size(); i++)
		str += data[i].tostring();
	return str;
}
