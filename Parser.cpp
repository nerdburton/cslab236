#include "Parser.h"

Parser::Parser(string new_filename)
{
	filename = new_filename;
	counter = 0;
}

Parser::~Parser(){}

void Parser::begin()
{
	Scanner scan;
	scan.begin_scan(filename);
	tokenList = scan.returnTokenList();
	bool parsed = datalog_program();
	if (!parsed)
		failure(tokenList[counter]);
	else
	{
		cout << tostring() << endl;
		cout << "Domain(" << domainList.size() << "):\n";
		set<string>::iterator iter;
		for (iter = domainList.begin(); iter != domainList.end(); ++iter)
		{
			cout << "  " << *iter << endl;
		}
	}
}

bool Parser::match(Token::token_list enum_type)
{
	while (tokenList[counter].returnEnum() == Token::token_list::COMMENT)
		counter++;
	if (tokenList[counter].returnEnum() == enum_type)
	{
		counter++;
		return true;
	}
	else
		return false;
}

bool Parser::datalog_program()
{
	if (match(Token::token_list::SCHEMES))
	{
		if (match(Token::token_list::COLON))
		{
			if (scheme())
			{
				if (schemeList())
				{
					if (match(Token::token_list::FACTS))
					{
						if (match(Token::token_list::COLON))
						{
							if (factList())
							{
								if (match(Token::token_list::RULES))
								{
									if (match(Token::token_list::COLON))
									{
										if (ruleList())
										{
											if (match(Token::token_list::QUERIES))
											{
												if (match(Token::token_list::COLON))
												{
													if (query())
													{
														if (queryList())
														{
															if (match(Token::token_list::ENDOF))
															{
																return true;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Parser::scheme()
{
	int start_loc = counter;
	if (match(Token::token_list::ID))
	{
		if (match(Token::token_list::LEFT_PAREN))
		{
			if (match(Token::token_list::ID))
			{
				if (idList())
				{
					if (match(Token::token_list::RIGHT_PAREN))
					{
						Predicate scheme_predicate;
						for (int i = start_loc; i < counter; i++)
						{
							if (tokenList[i].print_token_type() != "COMMENT")
							{
								Parameter new_parameter(tokenList[i].print());
								scheme_predicate.insert_value(new_parameter);
							}
						}
						program_contents.addToSchemes(scheme_predicate);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Parser::schemeList()
{
	if (scheme())
	{
		if (schemeList())
			return true;
	}
	else if (match(Token::token_list::FACTS))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::idList()
{
	if (match(Token::token_list::COMMA))
	{
		if (match(Token::token_list::ID))
		{
			if (idList())
			{
				return true;
			}
		}
	}
	else if (match(Token::token_list::RIGHT_PAREN))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::fact()
{
	int start_loc = counter;
	if (match(Token::token_list::ID))
	{
		if (match(Token::token_list::LEFT_PAREN))
		{
			if (match(Token::token_list::STRING))
			{
				string str = tokenList[counter - 1].print();
				domainList.insert(str);
				if (stringList())
				{
					if (match(Token::token_list::RIGHT_PAREN))
					{
						if (match(Token::token_list::PERIOD))
						{
							Predicate fact_predicate;
							for (int i = start_loc; i < counter; i++) 
							{
								if (tokenList[i].print_token_type() != "COMMENT")
								{
									Parameter new_parameter(tokenList[i].print());
									fact_predicate.insert_value(new_parameter);
								}
							}
							program_contents.addToFacts(fact_predicate);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Parser::factList()
{
	if (fact())
	{
		if (factList())
			return true;
		return true;
	}
	else if (match(Token::token_list::RULES))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::rule()
{
	int start_loc = counter;
	if (headPredicate())
	{
		if (match(Token::token_list::COLON_DASH))
		{
			if (predicate())
			{
				if (predicateList())
				{
					if (match(Token::token_list::PERIOD))
					{
						Predicate rule_predicate;
						for (int i = start_loc; i < counter; i++)
						{
							if (tokenList[i].print_token_type() != "COMMENT")
							{
								string str = tokenList[i].print();
								if (tokenList[i].print_token_type() == "COLON_DASH")
									str = " " + tokenList[i].print() + " ";
								Parameter new_parameter(str);
								rule_predicate.insert_value(new_parameter);
							}
						}
						program_contents.addToRules(rule_predicate);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Parser::ruleList()
{
	if (rule())
	{
		if (ruleList())
			return true;
		return true;
	}
	else if (match(Token::token_list::QUERIES))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::headPredicate()
{
	if (match(Token::token_list::ID))
	{
		if (match(Token::token_list::LEFT_PAREN))
		{
			if (match(Token::token_list::ID))
			{
				if (idList())
				{
					if (match(Token::token_list::RIGHT_PAREN))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Parser::predicate()
{
	if (match(Token::token_list::ID))
	{
		if (match(Token::token_list::LEFT_PAREN))
		{
			if (parameter())
			{
				if (parameterList())
				{
					if (match(Token::token_list::RIGHT_PAREN))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Parser::predicateList()
{
	if (match(Token::token_list::COMMA))
	{
		if (predicate())
		{
			if (predicateList())
				return true;
		}
	}//I"M HERE *******************************************
	else if (match(Token::token_list::PERIOD))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::parameter()
{
	if (match(Token::token_list::STRING))
	{
		return true;
	}
	else if (match(Token::token_list::ID))
	{
		return true;
	}
	else if (expression())
	{
		return true;
	}
	else
		return false;
}

bool Parser::parameterList()
{
	if (match(Token::token_list::COMMA))
	{
		if (parameter())
		{
			if (parameterList())
				return true;
		}
	}
	else if (match(Token::token_list::RIGHT_PAREN))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::expression()
{
	if (match(Token::token_list::LEFT_PAREN))
	{
		if (parameter())
		{
			if (operators())
			{
				if (parameter())
				{
					if (match(Token::token_list::RIGHT_PAREN))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Parser::operators()
{
	if (match(Token::token_list::ADD))
		return true;
	else if (match(Token::token_list::MULTIPLY))
		return true;
	else
		return false;
}

bool Parser::query()
{
	int start_loc = counter;
	if (predicate())
	{
		if (match(Token::token_list::Q_MARK))
		{
			Predicate query_predicate;
			for (int i = start_loc; i < counter; i++)
			{
				if (tokenList[i].print_token_type() != "COMMENT")
				{
					Parameter new_parameter(tokenList[i].print());
					query_predicate.insert_value(new_parameter);
				}
			}
			program_contents.addToQueries(query_predicate);
			return true;
		}
	}
	return false;
}

bool Parser::queryList()
{
	if (query())
	{
		if (queryList())
			return true;
		return true;
	}
	else if (match(Token::token_list::ENDOF))
	{
		counter--;
		return true;
	}
	return false;
}

bool Parser::stringList()
{
	if (match(Token::token_list::COMMA))
	{
		if (match(Token::token_list::STRING))
		{
			string str = tokenList[counter - 1].print();
			domainList.insert(str);
			if (stringList())
				return true;
		}
	}
	else if (match(Token::token_list::RIGHT_PAREN))
	{
		counter--;
		return true;
	}
	return false;
}

void Parser::failure(Token failed)
{
	cout << "Failure!" << endl;
	cout << "  " << failed.print_token() << endl;
	return;
}

string Parser::tostring()
{
	string str = "Success!\n" + program_contents.tostring();
	return str;
}

int Parser::notComment()
{
	int i = counter + 1;

	while (tokenList[i].print_token_type() == "COMMENT")
		i++;
	return i;
}
