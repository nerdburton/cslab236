#include "TokenStore.h"

TokenStore::TokenStore()
{
	vector<Token> token_vector;
}
TokenStore::~TokenStore(){
	clear();
}

void TokenStore::push_back(Token new_token)
{
	token_vector.push_back(new_token);
	return;
}

void TokenStore::pop_back()
{
	token_vector.pop_back();
	return;
}

Token TokenStore::show_position(int pos)
{
	return token_vector[pos];
}
 
void TokenStore::print_list()
{
	for (unsigned int i = 0; i < token_vector.size(); i++)
		cout << token_vector[i].print_token() << endl;
	cout << "Total Tokens = " << token_vector.size() << endl;
	return;
}

vector<Token> TokenStore::returnTokenList()
{
	return token_vector;
}

void TokenStore::clear()
{
	while (!token_vector.empty())
		token_vector.pop_back();
	return;
}