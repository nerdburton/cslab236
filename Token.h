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
	enum token_list{ COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, ENDOF };
	map<token_list, string> token_map;
	token_list token_type;
	string token_string; 
	int line_num;
	bool map_populated;

	Token(token_list new_enum, string new_string, int new_line);
	Token(){}
	~Token(void);
	void populate_map();
	string print_token_type();
	string print_token();
	string print();
	Token::token_list returnEnum();
};

#endif
