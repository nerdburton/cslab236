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

#ifndef SCANNER_H
#define SCANNER_H

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
	 * Detects char tokens
	 */
	bool is_char_token(char ch);
	
	/**
	 * recursively creates strings for the tokens
	 */
	string stringer(string str);
	string commenter(string str);
	string block_commenter(string str);
	string ider(string str);

	/**
	 * used to create tokens
	 *
	 * after tokenizer_hub determines what kind of token 
	 *	a character might be starting, tokenizer
	 *	constructs a token until meeting end case
	 *	to end construction.
	 * If an EOF is detected and criteria for token has
	 *	not been created, token is UNIDENTIFIED
	 */
	void string_tokenizer();
	void comment_tokenizer();
	void block_comment_tokenizer();
	void id_tokenizer();
	
	/**
	 * Used for single character tokens.
	 *
	 * Special case for COLON token
	 *	After ':' looks for a '-'
	 */
	void char_tokenizer();
}
#endif
