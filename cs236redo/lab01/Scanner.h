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
	int lineNum;
	vector<Token> tokenStore;

	// scan in string
	string import_text(string filename);

	/**
	 * Main hub
	 * 
	 * Reads a character in the string and chooses where to go
	 *
	 * For single character tokens (always single character like LEFT_PAREN)
	 * send it to single character tokenizer
	 * 
	 * for multicharacter tokens (IDs, strings and comments)
	 * send to multicharacter tokenizer
	 */
	void tokenizer_hub(string fileText);

	/**
	 * recursively creates strings for the tokens
	 */
	string stringer(string str);
	string commenter(string str);
	string block_commenter(string str);
	string ider(string str);

	void string_tokenizer();
	void comment_tokenizer();
	void block_comment_tokenizer();
	void id_tokenizer();
	void char_tokenizer();

























