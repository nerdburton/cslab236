/*

 *
 * datalogProgram parser
 * As far as I can tell, the purpose of this is to check to make sure that the program can compile
 * If that is the case, then I will start this program by reading in the entire program with the scanner
 * The scanner will then return a vector containing all of the tokens from the program
 * It will then read through each token, looking for keywords and, after each keyword, parsing through the contents and looking for errors
 * If an error is found, it will stop the program and return an error with the offending token
 *		Offending tokens:
 *			Undefined tokens
 *			Tokens out of order
 *			Unpaired parentheses
 *			other stuff that I can't think of at the moment
 *
 * ONE WAY TO DO THIS
 *							
 *							get a keyword
 *								insert all following tokens behind it (up til the next keyword) into a storage class
 *								parse through tokens stored in each storage class and look for offending tokens
 *								if a single token is an error, stop program, return an error and say what token caused the error
 * 
 * 
 *
 */


#include <iostream>
#include "Predicate.h"
#include "Rule.h"
#include "Object.h"
#include <string>
#include <vector>

using namespace std;

class datalogProgram
{
public:
	/*
	Schemelist
	Factlist
	Querylist
	Rulelist
	*/
	Object schemes;
	Object facts;
	Object queries;
	Object rules;

	datalogProgram();
	~datalogProgram();
	 
	void addToSchemes(Predicate new_predicate);
	void addToFacts(Predicate new_predicate);
	void addToQueries(Predicate new_predicate);
	void addToRules(Predicate new_rule);

	Object getSchemes();
	Object getFacts();
	Object getQueries();
	Object getRules();

	string tostring();
};
