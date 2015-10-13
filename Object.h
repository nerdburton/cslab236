#include "Predicate.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Object
{
public:
	string id;
	vector<Predicate> list; 

	Object();
	~Object(void);

	void insertID(string str);
	void addToList(Predicate new_predicate);
	string tostring();
};