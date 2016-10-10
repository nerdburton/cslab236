/**#include "Scanner.h"

string Scanner::import_text(string filename) {
	char ch;
	string str;
	fstream fin(filename.c_str(), fstream::in);
	while (fin >> noskipws >> ch) {
		str += ch;
	}
	return str;
}

void Scanner::tokenizer_hub(string fileText) {
	char ch;

	while (stringStillHasStuff)
	{
		ch = firstCharacterOfFileText
		if (is_char_token(ch)) {
			charTokenizer(ch)
			fileText = fileTextTruncated
		}
		else if (ch == '\'') {
			string str = stringer(fileText)
			string_tokenizer(str) 
			fileText = fileTextTruncated
		}
		else if (ch == '#') {
			//check if line or block comment
			
			string str = commenter(fileText)
			comment_tokenizer(str)
			fileText = fileTextTruncated
		}
		else {
			
		}
	}
}

bool Scanner::is_char_token(char ch) {

}

string Scanner::stringer(string str) {

}

string Scanner::commenter(string str) {

}

string Scanner::block_commenter(string str) {

}

string Scanner::ider(string str) {

}

void Scanner::string_tokenizer(string str) {

}

void Scanner::comment_tokenizer(string str) {

}

void Scanner::block_comment_tokenizer(string str) {

}

void Scanner::id_tokenizer(string str) {

}

void Scanner::char_tokenizer(string str) {

}*/

#include "Scanner.h"

Scanner::Scanner()
{
	TokenStore ts;
	string file = "";
}
Scanner::~Scanner(void){}

void Scanner::begin_scan(string filename)
{
	file = import_text(filename);
	string::iterator iter = file.begin();
	scan_token(iter, 1);
}

string Scanner::import_text(string filename)
{
	/*
	* ifstream open file
	* import file into string
	*	Need to keep spaces and line skips
	*/
	char ch;
	string str;
	fstream fin(filename.c_str(), fstream::in);
	while (fin >> noskipws >> ch)
	{
		str += ch;
	}
	return str;
}

void Scanner::scan_string(string::iterator iter, int line_num, string str, int line_quantity)
{
	string::iterator temp = iter;
	if (iter == file.end() || temp == file.end())
	{
		int first_line = line_num - line_quantity;
		Token new_token(Token::token_list::UNDEFINED, str, first_line);
		ts.push_back(new_token);
		scan_token(iter, line_num);
		return;
	}
	else
		temp++;
	if (str == "''" && *temp != '\'')
	{
		Token new_token(Token::token_list::STRING, str, line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
	}
	else if (*iter == '\'' && *temp == '\'' && str != "\'")
	{
		str += *iter;
		str +=*temp;
		iter = temp;
		if (iter == file.end())
		{
			Token new_token(Token::token_list::UNDEFINED, str, line_num);
			ts.push_back(new_token);
			scan_token(iter, line_num);
			return;
		}
		else
		{
			iter++;
			scan_string(iter, line_num, str, line_quantity);
		}
	}
	else if (*iter == '\'' && *temp == '\n' && *temp + 1 == '\'')
	{
		str += *iter;
		iter++;
		line_num++;
		line_quantity++;
		scan_string(iter, line_num, str, line_quantity);
	}
	else if (*iter == '\'' && *temp != '\'')
	{
		str += *iter;
		int first_line = line_num - line_quantity;
		Token new_token(Token::token_list::STRING, str, first_line);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
	}
	else if (*iter == '\n')
	{
		str += *iter;
		line_num++;
		line_quantity++;
		iter++;
		scan_string(iter, line_num, str, line_quantity);
	}
	else
	{
		str += *iter;
		iter++;
		scan_string(iter, line_num, str, line_quantity);
	}
}

void Scanner::key_words_and_stuff(string::iterator iter, int line_num, string str, bool first_time)
{
	if (!isalpha(*iter) && first_time)
	{
		str += *iter;

		Token new_token(Token::token_list::UNDEFINED, str, line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
	}
	else if (isdigit(*iter) && !first_time)
	{
		str += *iter;
		iter++;
		key_words_and_stuff(iter, line_num, str, false);
	}
	else if (!isalpha(*iter) && !first_time)
	{
		//compare string to "Queries", "Rules", "Facts" and "Schemes"
		//initialize schemes, facts, rules, queries or id token depending on outcome
		//id if it doesn't match the other four (obviously)		
		if (str == "Queries")
		{
			Token new_token(Token::token_list::QUERIES, str, line_num);
			ts.push_back(new_token);
		}
		else if (str == "Rules")
		{
			Token new_token(Token::token_list::RULES, str, line_num);
			ts.push_back(new_token);
		}
		else if (str == "Facts")
		{
			Token new_token(Token::token_list::FACTS, str, line_num);
			ts.push_back(new_token);
		}
		else if (str == "Schemes")
		{
			Token new_token(Token::token_list::SCHEMES, str, line_num);
			ts.push_back(new_token);
		}
		else
		{
			Token new_token(Token::token_list::ID, str, line_num);
			ts.push_back(new_token);
		}
		scan_token(iter, line_num);
	}
	else
	{
		str += *iter;
		iter++;
		key_words_and_stuff(iter, line_num, str, false);
	}
}

void Scanner::block_comment(string::iterator iter, int line_num, string str, int line_quantity)
{
	string::iterator temp = iter;
	temp++;
	while (*temp == ' ')
		temp++;
	if (iter == file.end())
	{
		int first_line = line_num - line_quantity;
		Token new_token(Token::token_list::UNDEFINED, str, first_line);
		ts.push_back(new_token);
		scan_token(iter, line_num);
	}
	else if (*iter == '|' && *temp == '#')
	{
		str += *iter;
		iter++;
		str += *iter;
		iter++;
		int first_line = line_num - line_quantity;
		Token new_token(Token::token_list::COMMENT, str, first_line);
		ts.push_back(new_token);
		scan_token(iter, line_num);
	}
	else if (*iter == '\n')
	{
		str += *iter;
		iter++;
		line_num++;
		line_quantity++;
		block_comment(iter, line_num, str, line_quantity);
	}
	else
	{
		str += *iter;
		iter++;
		block_comment(iter, line_num, str, line_quantity);
	}
	return;
}

void Scanner::line_comment(string::iterator iter, int line_num, string str)
{
	string::iterator temp = iter;
	temp++;
	if (*temp == '|' && *iter == '#')
		block_comment(iter, line_num, "", 0);
	else if (*iter == '\n')
	{
		Token new_token(Token::token_list::COMMENT, str, line_num);
		ts.push_back(new_token);
		line_num++;
		iter++;
		scan_token(iter, line_num);
	}
	else
	{
		str += *iter;
		iter++;
		line_comment(iter, line_num, str);
	} 
	return;
}

void Scanner::scan_token(string::iterator iter, int line_num)
{
	if (iter == file.end())
	{
		Token new_token(Token::token_list::ENDOF, "", line_num);
		ts.push_back(new_token);
		return;
	}
	char ch = *iter;
	switch (ch)
	{
	case ',':{
		Token new_token(Token::token_list::COMMA, ",", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case '.':{
		Token new_token(Token::token_list::PERIOD, ".", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case '?':{
		Token new_token(Token::token_list::Q_MARK, "\?", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case '(':{
		Token new_token(Token::token_list::LEFT_PAREN, "(", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case ')':{
		Token new_token(Token::token_list::RIGHT_PAREN, ")", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case ':':{
		string::iterator temp = iter + 1;
		if (temp == file.end())
		{
			iter++;
			scan_token(iter, line_num);
			return;
		}
		if (*temp == '-')
		{
			iter++;
			Token new_token(Token::token_list::COLON_DASH, ":-", line_num);
			ts.push_back(new_token);
		}
		else
		{
			Token new_token(Token::token_list::COLON, ":", line_num);
			ts.push_back(new_token);
		}
		iter++;
		scan_token(iter, line_num);
		break; }
	case '*':{
		Token new_token(Token::token_list::MULTIPLY, "*", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case '+':{
		Token new_token(Token::token_list::ADD, "+", line_num);
		ts.push_back(new_token);
		iter++;
		scan_token(iter, line_num);
		break; }
	case '#':
		line_comment(iter, line_num, "");
		break;
	case '\'':
		iter++;
		scan_string(iter, line_num, "\'", 0);
		break;
	case ' ':
		iter++;
		scan_token(iter, line_num);
		break;
	case '\t':
		iter++;
		scan_token(iter, line_num);
		break;
	case '\n':
		iter++;
		line_num++;
		scan_token(iter, line_num);
		break;
	default:
		key_words_and_stuff(iter, line_num, "", true);
		break;
	}
}

void Scanner::print_tokens()
{
	ts.print_list();
	return;
}

vector<Token> Scanner::returnTokenList()
{
	return ts.returnTokenList();
}
