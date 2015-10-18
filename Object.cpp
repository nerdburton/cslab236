#include "Object.h"

Object::Object(){}
Object::~Object(void){}

void Object::insertID(string str)
{
	id = str;
} 
void Object::addToList(Predicate new_predicate)
{
	list.push_back(new_predicate);
}

vector<Predicate> Object::getObj()
{
	return list;
}

void Object::editList(vector<Predicate> vec)
{
	list = vec;
}

string Object::tostring()
{
	string str = id + "(" + to_string(list.size()) + "):";
	for (int i = 0; i < list.size(); i++)
	{
		str += "\n  " + list[i].tostring();
	}
	return str;
}
