#include "datalogProgram.h"

datalogProgram::datalogProgram()
{
	schemes.insertID("Schemes");
	facts.insertID("Facts");
	rules.insertID("Rules");
	queries.insertID("Queries");
}

datalogProgram::~datalogProgram(){} 

void datalogProgram::addToSchemes(Predicate new_predicate)
{
	schemes.addToList(new_predicate);
}

void datalogProgram::addToFacts(Predicate new_predicate)
{
	facts.addToList(new_predicate);
}

void datalogProgram::addToRules(Predicate new_rule)
{
	rules.addToList(new_rule);
}

void datalogProgram::addToQueries(Predicate new_predicate)
{
	queries.addToList(new_predicate);
}

Object datalogProgram::getSchemes()
{
	return schemes;
}
Object datalogProgram::getFacts()
{
	return facts;
}
Object datalogProgram::getQueries()
{
	return queries;
}
Object datalogProgram::getRules()
{
	return rules;
}
void datalogProgram::setDatalogProgram(Object s, Object f, Object q, Object r)
{
	schemes = s;
	facts = f;
	queries = q;
	rules = r;
}
string datalogProgram::tostring()
{
	string str;
	str = schemes.tostring() + "\n" + facts.tostring() + "\n" + rules.tostring() + "\n" + queries.tostring();
	return str;
}
