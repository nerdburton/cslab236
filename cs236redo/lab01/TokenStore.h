#include <iostream>
#include <vector>
#include "Token.h"

using namespace std;

class TokenStore
{
public:
	vector<Token> token_vector;

	TokenStore();
	~TokenStore();

	void push_back(Token new_token);

	void pop_back();

	Token show_position(int pos);

	void print_list();

	vector<Token> returnTokenList();
	 
	void clear();
};