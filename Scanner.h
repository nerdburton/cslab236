#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "Token.h" 
#include "TokenStore.h"

using namespace std;

class Scanner
{
public:
	string file;
	TokenStore ts;

	Scanner();
	~Scanner(void);

	void begin_scan(string filename);

	string import_text(string filename);

	void scan_string(string::iterator iter, int line_num, string str, int line_quantity);
	void key_words_and_stuff(string::iterator iter, int line_num, string str, bool first_time);
	void block_comment(string::iterator iter, int line_num, string str, int line_quantity);
	void line_comment(string::iterator iter, int line_num, string str);
	void scan_token(string::iterator iter, int line_num);
	void print_tokens();
	vector<Token> returnTokenList();
};