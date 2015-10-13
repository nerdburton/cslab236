#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "datalogProgram.h"
#include "Scanner.h"
#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
using namespace std;

class Parser
{
public:
	datalogProgram program_contents;
	vector<Token> tokenList;
	set<string> domainList;
	string filename;
	int counter;

	Parser(string new_filename);
	~Parser();

	void begin();
	bool match(Token::token_list enumtype);
	bool datalog_program();
	bool scheme();
	bool schemeList();
	bool idList();
	bool fact();
	bool factList();
	bool rule();
	bool ruleList();
	bool headPredicate(); 
	bool predicate();
	bool predicateList();
	bool parameter();
	bool parameterList();
	bool expression();
	bool operators();
	bool query();
	bool queryList();
	bool stringList();

	string tostring();
	void failure(Token failed);
	int notComment();
};