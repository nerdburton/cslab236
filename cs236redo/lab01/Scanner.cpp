#include "Scanner.h"

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
		if(is_char_token(ch)) {
			charTokenizer(ch)
			fileText = fileTextTruncated
		}
		else if
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

}
