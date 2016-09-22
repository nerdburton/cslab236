/**
 * Receives full file as string
 * eg
 *	.
 *	,
 *	'a string'
 *	#A comment
 *	Schemes
 *	FactsRules
 *	::-
 *
 * reads in whitespace as well
 * goes through string, character by character
 * reads character, creates token for each type of token
 * 
 * outputs
 *	(PERIOD, ".", 1)
 *	(COMMA, ",", 2)
 *	(STRING, "'a string'", 3)
 *	(COMMENT, "#A comment", 4)
 *	(SCHEMES, "Schemes", 5)
 *	(ID, "FactsRules", 6)
 *	(COLON, ":", 7)
 *	(COLON_DASH, ":-", 7)
 *	(EOF, "", 8)
 *	Total Tokens = 9
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "Token.h"

using namespace std;

class Scanner {
public:
	
