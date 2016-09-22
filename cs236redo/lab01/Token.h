#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

using namespace std;
class Token
{
public:
	enum token_type{ COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, ENDOF};

	map<token_type, string> tokenMap;
	token_type tokenType;
	string tokenString;
	int lineNum;
	bool mapPopulated;

	Token(token_type newEnum, string newString, int newLine);
	void populate_map();
	string get_token_type();
	string get_token();
	int get_line();
};

#endif
