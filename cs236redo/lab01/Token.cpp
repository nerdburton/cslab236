#include "Token.h"

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
}
