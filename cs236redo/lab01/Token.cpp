/**#include "Token.h"

Token::Token(token_type newEnum, string, newString, int newLine) {
	tokenType = newEnum;
	tokenString = newString;
	lineNum = newLine;
	mapPopulated = false;
}

void Token::populate_map() {
	if (!map_populated) {
		mapPopulated = true;
		tokenMap[COMMA] = "COMMA";
		tokenMap[PERIOD] = "PERIOD";
		tokenMap[Q_MARK] = "Q_MARK";
		tokenMap[LEFT_PAREN] = "LEFT_PAREN";
		tokenMap[RIGHT_PAREN] = "RIGHT_PAREN";
		tokenMap[COLON] = "COLON";
		tokenMap[COLON_DASH] = "COLON_DASH";
		tokenMap[MULTIPLY] = "MULTIPLY";
		tokenMap[ADD] = "ADD";
		tokenMap[SCHEMES] = "SCHEMES";
		tokenMap[FACTS] = "FACTS";
		tokenMap[RULES] = "RULES";
		tokenMap[QUERIES] = "QUERIES";
		tokenMap[ID] = "ID";
		tokenMap[STRING] = "STRING";
		tokenMap[COMMENT] = "COMMENT";
		tokenMap[WHITESPACE] = "WHITESPACE";
		tokenMap[UNDEFINED] = "UNDEFINED";
		tokenMap[ENDOF] = "EOF";
	}
	return;
}

string Token::get_token_type() {
	populate_map();
	return tokenMap.at(tokenType);
}

string Token::get_token() {
	return tokenString;
}

int get_line() {
	return lineNum;
}*/

#include "Token.h"

Token::Token(token_list new_enum, string new_string, int new_line)
{
	token_type = new_enum;
	token_string = new_string;
	line_num = new_line;
	map_populated = false;
}

Token::~Token(void){} 

void Token::populate_map()
{
	if (!map_populated)
	{
		map_populated = true;
		token_map[COMMA] = "COMMA";
		token_map[PERIOD] = "PERIOD";
		token_map[Q_MARK] = "Q_MARK";
		token_map[LEFT_PAREN] = "LEFT_PAREN";
		token_map[RIGHT_PAREN] = "RIGHT_PAREN";
		token_map[COLON] = "COLON";
		token_map[COLON_DASH] = "COLON_DASH";
		token_map[MULTIPLY] = "MULTIPLY";
		token_map[ADD] = "ADD";
		token_map[SCHEMES] = "SCHEMES";
		token_map[FACTS] = "FACTS";
		token_map[RULES] = "RULES";
		token_map[QUERIES] = "QUERIES";
		token_map[ID] = "ID";
		token_map[STRING] = "STRING";
		token_map[COMMENT] = "COMMENT";
		token_map[WHITESPACE] = "WHITESPACE";
		token_map[UNDEFINED] = "UNDEFINED";
		token_map[ENDOF] = "EOF";
	}
	return;
}

string Token::print_token_type()
{
	populate_map();
	return token_map.at(token_type);
}

string Token::print_token()
{
	populate_map();
	stringstream ss;
	ss << line_num;
	string num;
	ss >> num;
	return "(" + token_map.at(token_type) + ",\"" + token_string + "\"," + num + ")";
}

string Token::print()
{
	return token_string;
}

Token::token_list Token::returnEnum()
{
	return token_type;
}
